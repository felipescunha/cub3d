/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:23:54 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/22 19:18:19 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	load_texture(t_cub3d *cub3d, t_data *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(cub3d->mlx, path,
			&texture->sprite_width, &texture->sprite_height);
	texture->addr = mlx_get_data_addr(texture->img,
			&texture->bits_per_pixel, &texture->line_length, &texture->endian);
}
