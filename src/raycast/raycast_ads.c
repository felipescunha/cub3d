/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_ads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:37:58 by marolive          #+#    #+#             */
/*   Updated: 2023/07/22 19:20:46 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	zero_fill(t_cub3d *cub3d)
{
	cub3d->ray_dir_x = 0;
	cub3d->ray_dir_y = 0;
	cub3d->line_height = 0;
	cub3d->draw_end = 0;
	cub3d->draw_start = 0;
	cub3d->wall_x = 0;
	cub3d->texture_x = 0;
	cub3d->texture_position = 0;
	cub3d->texture_step = 0;
	cub3d->perp_wall_dist = 0;
}

int	get_addr_locale(t_data img, int x, int y)
{
	return (y * img.line_length + x * (img.bits_per_pixel / 8));
}

void	mlx_image(t_cub3d *cub3d)
{
	mlx_put_image_to_window(cub3d->mlx, cub3d->win,
		cub3d->img.img, 0, 0);
	mlx_destroy_image(cub3d->mlx, cub3d->img.img);
	cub3d->img.img = mlx_new_image(cub3d->mlx, SCREENWIDTH, SCREENHEIGHT);
}
