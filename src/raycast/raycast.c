/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:51:18 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/18 18:38:46 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void print_line(t_cub3d *cub3d, int drawStart, int drawEnd, int color)
{
	drawStart = 1; 
	drawEnd = 3; 
	while(drawStart < drawEnd)
	{
		mlx_pixel_put(cub3d->mlx_ptr, cub3d->win_ptr, drawStart, drawEnd, color);
	//mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
		drawStart++;
	}
}

/* int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
} */

void raycast(t_cub3d *cub3d)
{
	for(int x = 0; x < screenWidth; x++)
	{
		//calculate ray position and direction
		double cameraX = 2 * x / (double)screenWidth - 1; //x-coordinate in camera space
		double rayDirX = cub3d->dirX + cub3d->planeX * cameraX;
		double rayDirY = cub3d->dirY + cub3d->planeY * cameraX;


		//which box of the map we're in
		int mapX = (int)cub3d->posX;
		int mapY = (int)cub3d->posY;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;
		double deltaDistX;
		double deltaDistY;

		//length of ray from one x or y-side to next x or y-side
		deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
		deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
		double perpWallDist;

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
			if(cub3d->map[mapX][mapY] > 0)
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

		print_line(cub3d, drawStart, drawEnd, 0x00FFFFFF);
	}
}
