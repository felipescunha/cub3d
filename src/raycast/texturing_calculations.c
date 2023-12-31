/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing_calculations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:34:13 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/22 15:27:55 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	texturing_calculations(t_cub3d *cub3d)
{
	if (cub3d->side == SIDE_X)
		cub3d->wall_x = cub3d->pos_y + cub3d->perp_wall_dist
			* cub3d->ray_dir_y;
	else
		cub3d->wall_x = cub3d->pos_x + cub3d->perp_wall_dist
			* cub3d->ray_dir_x;
	cub3d->wall_x -= floor(cub3d->wall_x);
	cub3d->texture_x = (int)(cub3d->wall_x
			*(double)cub3d->textures.north.sprite_width);
	if (cub3d->side == SIDE_X && cub3d->ray_dir_x > 0)
		cub3d->texture_x = cub3d->textures.north.sprite_width
			- cub3d->texture_x - 1;
	if (cub3d->side == SIDE_Y && cub3d->ray_dir_y < 0)
		cub3d->texture_x = cub3d->textures.north.sprite_width
			- cub3d->texture_x - 1;
	cub3d->texture_step = 1.0 * cub3d->textures.north.sprite_height
		/ cub3d->line_height;
	cub3d->texture_position = (cub3d->draw_start - SCREENHEIGHT
			/ 2 + cub3d->line_height / 2) * cub3d->texture_step;
}

char	*ft_split_texture(char **texture)
{
	if (ft_array_size(texture) != 2)
		print_error("In texture array\n");
	return (texture[1]);
}
