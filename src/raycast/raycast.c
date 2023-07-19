/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:51:18 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/19 18:16:50 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int    get_addr_locale(t_data img, int x, int y)
{
    return (y * img.line_length + x * (img.bits_per_pixel / 8));
}

void    my_mlx_pixel_put(t_cub3d *cub3d, int x, int y, int color)
{
    char    *dest;

    dest = cub3d->img.addr + get_addr_locale(cub3d->img, x, y);
    *(unsigned int *)dest = color;
}

unsigned int	get_pixel_color(t_data img, int x, int y)
{
    char    *dest;

    dest = img.addr + get_addr_locale(img, x, y);
    return (*(unsigned int *)dest);
}


void print_line(t_cub3d *cub3d, int drawStart, int drawEnd, int color, int x)
{
	int i = 0;
	int texture_y = 0;

	while ( i <= SCREENHEIGHT)
	{
		if(i < drawStart)
			my_mlx_pixel_put(cub3d, x, i, create_trgb(0, cub3d->ceiling.red, cub3d->ceiling.green, cub3d->ceiling.blue));
		else if( i > drawStart && i < drawEnd)
			{
				texture_y = (int)cub3d->texture_position & (cub3d->textures.north.sprite_height -1);
				cub3d->texture_position += cub3d->texture_step;
				if( cub3d->side == SIDE_X && cub3d->step_x > 0)
					color = get_pixel_color(cub3d->textures.north, cub3d->texture_x, texture_y);
				else if( cub3d->side == SIDE_X && cub3d->step_x <= 0)
					color = get_pixel_color(cub3d->textures.south, cub3d->texture_x, texture_y);
				else if( cub3d->side == SIDE_Y && cub3d->step_y > 0)
					color = get_pixel_color(cub3d->textures.west, cub3d->texture_x, texture_y);
				else if( cub3d->side == SIDE_Y && cub3d->step_y <= 0)
					color = get_pixel_color(cub3d->textures.east, cub3d->texture_x, texture_y);
				my_mlx_pixel_put(cub3d, x, i, color);
			}	
		else
			my_mlx_pixel_put(cub3d, x, i, create_trgb(0, cub3d->floor.red, cub3d->floor.green, cub3d->floor.blue));
		i++;
	}
}

void zero_fill(t_cub3d *cub3d)
{
	cub3d->rayDirX = 0;
	cub3d->rayDirY = 0;
	cub3d->line_height = 0;
	cub3d->draw_end = 0;
	cub3d->draw_start = 0;
	cub3d->wall_x = 0;
	cub3d->texture_x = 0;
	cub3d->texture_position = 0;
	cub3d->texture_step = 0;
	cub3d->perp_wall_dist = 0;
}

void raycast(t_cub3d *cub3d)
{
	for(int x = 0; x < SCREENWIDTH; x++)
	{
		zero_fill(cub3d);
		//calculate ray position and direction
		double cameraX = 2 * x / (double)SCREENWIDTH - 1; //x-coordinate in camera space
		cub3d->rayDirX = cub3d->dirX + cub3d->planeX * cameraX;
		cub3d->rayDirY = cub3d->dirY + cub3d->planeY * cameraX;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;
		double deltaDistX;
		double deltaDistY;

		//length of ray from one x or y-side to next x or y-side
		if(cub3d->rayDirX == 0)
			deltaDistX = 1e30;
		else
			deltaDistX = sqrt(1 + (cub3d->rayDirY * cub3d->rayDirY) / (cub3d->rayDirX * cub3d->rayDirX));
		if(deltaDistY == 0)
			deltaDistY = 1e30;
		else
			deltaDistY = sqrt(1 + (cub3d->rayDirX * cub3d->rayDirX) / (cub3d->rayDirY * cub3d->rayDirY));

		//which box of the map we're in
		int mapX = (int)cub3d->posX;
		int mapY = (int)cub3d->posY;

		//what direction to step in x or y-direction (either +1 or -1)
	
		int hit = 0; //was there a wall hit?
		//int side; //was a NS or a EW wall hit?
		cub3d->side = 0;
		if(cub3d->rayDirX < 0)
		{
			cub3d->step_x = -1;
			sideDistX = (cub3d->posX - mapX) * deltaDistX;
		}
		else
		{
			cub3d->step_x = 1;
			sideDistX = (mapX + 1.0 - cub3d->posX) * deltaDistX;
		}
		if(cub3d->rayDirY < 0)
		{
			cub3d->step_y = -1;
			sideDistY = (cub3d->posY - mapY) * deltaDistY;
		}
		else
		{
			cub3d->step_y = 1;
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
			mapX += cub3d->step_x;
			cub3d->side = 0;
			}
			else
			{
			sideDistY += deltaDistY;
			mapY += cub3d->step_y;
			cub3d->side = 1;
			}
			//Check if ray has hit a wall
			if(cub3d->map[mapY][mapX] != '0')
				hit = 1;
      	}

		if(cub3d->side == 0)
			cub3d->perp_wall_dist = (sideDistX - deltaDistX);
		else
			cub3d->perp_wall_dist = (sideDistY - deltaDistY);

		//Calculate height of line to draw on screen
		cub3d->line_height = (int)(SCREENHEIGHT / cub3d->perp_wall_dist);

		//calculate lowest and highest pixel to fill in current stripe
		cub3d->draw_start = - cub3d->line_height / 2 + SCREENHEIGHT / 2;
		if(cub3d->draw_start < 0)
			cub3d->draw_start = 0;
		cub3d->draw_end = cub3d->line_height / 2 + SCREENHEIGHT / 2;
		if(cub3d->draw_end >= SCREENHEIGHT)
			cub3d->draw_end = SCREENHEIGHT - 1;
		
		//draw the pixels of the stripe as a vertical line
		texturing_calculations(cub3d);
		print_line(cub3d, cub3d->draw_start, cub3d->draw_end, 0x00FF00, x);
	}

	mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->win_ptr, cub3d->img.img, 0, 0);
   	mlx_destroy_image(cub3d->mlx_ptr, cub3d->img.img);
    cub3d->img.img = mlx_new_image(cub3d->mlx_ptr, SCREENWIDTH, SCREENHEIGHT);
}
