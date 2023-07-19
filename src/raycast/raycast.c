/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:51:18 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/19 11:17:36 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void print_line(t_cub3d *cub3d, int drawStart, int drawEnd, int color, int x)
{
	while(drawStart < drawEnd)
	{
		mlx_pixel_put(cub3d->mlx_ptr, cub3d->win_ptr, x, drawStart, color);
		drawStart++;
	}
}

/* int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
} */

void raycast(t_cub3d *cub3d)
{
	for(int x = 0; x < SCREENWIDTH; x++)
	{
		//calculate ray position and direction
		double cameraX = 2 * x / (double)SCREENWIDTH - 1; //x-coordinate in camera space
		double rayDirX = cub3d->dirX + cub3d->planeX * cameraX;
		double rayDirY = cub3d->dirY + cub3d->planeY * cameraX;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;
		double deltaDistX;
		double deltaDistY;

		//length of ray from one x or y-side to next x or y-side
		if(rayDirX == 0)
			deltaDistX = 1e30;
		else
			deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
		if(deltaDistY == 0)
			deltaDistY = 1e30;
		else
			deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
		double perpWallDist;

		//which box of the map we're in
		int mapX = (int)cub3d->posX;
		int mapY = (int)cub3d->posY;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (cub3d->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - cub3d->posX) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (cub3d->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - cub3d->posY) * deltaDistY;
		}
			//which box of the map we're in
		

		 //perform DDA
		while(hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if(sideDistX < sideDistY)
			{
			sideDistX += deltaDistX;
			mapX += stepX;
			side = 0;
			}
			else
			{
			sideDistY += deltaDistY;
			mapY += stepY;
			side = 1;
			}
			//Check if ray has hit a wall
			if(cub3d->map[mapY][mapX] != '0')
				hit = 1;
      	}

		if(side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);

		//Calculate height of line to draw on screen
		int lineHeight = (int)(screenHeight / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + screenHeight / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + screenHeight / 2;
		if(drawEnd >= screenHeight)
			drawEnd = screenHeight - 1;
		
		//draw the pixels of the stripe as a vertical line
		print_line(cub3d, drawStart, drawEnd, 0x0000FFFF, x);
	}
}
