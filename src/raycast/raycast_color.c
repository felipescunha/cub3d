/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:33:20 by marolive          #+#    #+#             */
/*   Updated: 2023/07/22 19:09:58 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_cub3d *cub3d, int x, int y, int color)
{
	char	*dest;

	dest = cub3d->img.addr + get_addr_locale(cub3d->img, x, y);
	*(unsigned int *)dest = color;
}

size_t	get_color(t_data img, int x, int y)
{
	char	*dest;

	dest = img.addr + get_addr_locale(img, x, y);
	return (*(unsigned int *)dest);
}

void	pixel_color(t_cub3d *cub3d, int color, int i, int x)
{
	int	texture_y;

	texture_y = (int)cub3d->texture_position
		& (cub3d->textures.north.sprite_height -1);
	if (cub3d->side == SIDE_X && cub3d->step_x > 0)
		color = get_color(cub3d->textures.north, cub3d->texture_x, texture_y);
	else if (cub3d->side == SIDE_X && cub3d->step_x <= 0)
		color = get_color(cub3d->textures.south, cub3d->texture_x, texture_y);
	else if (cub3d->side == SIDE_Y && cub3d->step_y > 0)
		color = get_color(cub3d->textures.west, cub3d->texture_x, texture_y);
	else if (cub3d->side == SIDE_Y && cub3d->step_y <= 0)
		color = get_color(cub3d->textures.east, cub3d->texture_x, texture_y);
	my_mlx_pixel_put(cub3d, x, i, color);
}

void	print_line(t_cub3d *c, int color, int x)
{
	int	i;
	int	draw_start;
	int	draw_end;

	i = 0;
	draw_end = c->draw_end;
	draw_start = c->draw_start;
	while (i <= SCREENHEIGHT)
	{
		if (i < draw_start)
			my_mlx_pixel_put(c, x, i,
				create_trgb(0, c->ceil.red, c->ceil.green, c->ceil.blue));
		else if (i > draw_start && i < draw_end)
		{
			c->texture_position += c->texture_step;
			pixel_color(c, color, i, x);
		}	
		else
			my_mlx_pixel_put(c, x, i,
				create_trgb(0, c->floor.red, c->floor.green, c->floor.blue));
		i++;
	}
}
