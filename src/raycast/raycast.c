/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:51:18 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/22 19:05:14 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	delta_dist(t_cub3d *cub3d)
{
	if (cub3d->ray_dir_x == 0)
		cub3d->delta_dist_x = 1e30;
	else
		cub3d->delta_dist_x = fabs(1 / cub3d->ray_dir_x);
	if (cub3d->delta_dist_y == 0)
		cub3d->delta_dist_y = 1e30;
	else
		cub3d->delta_dist_y = fabs(1 / cub3d->ray_dir_y);
}

void	p_steps(t_cub3d *cub3d, int map_x, int map_y)
{
	if (cub3d->ray_dir_x < 0)
	{
		cub3d->step_x = -1;
		cub3d->side_dist_x = (cub3d->pos_x - map_x) * cub3d->delta_dist_x;
	}
	else
	{
		cub3d->step_x = 1;
		cub3d->side_dist_x = (map_x + 1.0 - cub3d->pos_x)
			* cub3d->delta_dist_x;
	}
	if (cub3d->ray_dir_y < 0)
	{
		cub3d->step_y = -1;
		cub3d->side_dist_y = (cub3d->pos_y - map_y) * cub3d->delta_dist_y;
	}
	else
	{
		cub3d->step_y = 1;
		cub3d->side_dist_y = (map_y + 1.0 - cub3d->pos_y)
			* cub3d->delta_dist_y;
	}
}

void	perform_dda(t_cub3d *cub3d, int hit, int map_x, int map_y)
{
	while (hit == 0)
	{
		if (cub3d->side_dist_x < cub3d->side_dist_y)
		{
			cub3d->side_dist_x += cub3d->delta_dist_x;
			map_x += cub3d->step_x;
			cub3d->side = 0;
		}
		else
		{
			cub3d->side_dist_y += cub3d->delta_dist_y;
			map_y += cub3d->step_y;
			cub3d->side = 1;
		}
		if (cub3d->map[map_y][map_x] != '0')
			hit = 1;
	}
}

void	wall_dist(t_cub3d *cub3d)
{
	if (cub3d->side == 0)
		cub3d->perp_wall_dist = (cub3d->side_dist_x - cub3d->delta_dist_x);
	else
		cub3d->perp_wall_dist = (cub3d->side_dist_y - cub3d->delta_dist_y);
	cub3d->line_height = (int)(SCREENHEIGHT / cub3d->perp_wall_dist);
	cub3d->draw_start = -cub3d->line_height / 2 + SCREENHEIGHT / 2;
	if (cub3d->draw_start < 0)
		cub3d->draw_start = 0;
	cub3d->draw_end = cub3d->line_height / 2 + SCREENHEIGHT / 2;
	if (cub3d->draw_end >= SCREENHEIGHT)
		cub3d->draw_end = SCREENHEIGHT - 1;
}

void	raycast(t_cub3d *cub3d)
{
	int		x;
	int		hit;
	int		map_x;
	int		map_y;
	double	camera_x;

	x = 0;
	while (x++ < SCREENWIDTH)
	{
		zero_fill(cub3d);
		camera_x = 2 * x / (double)SCREENWIDTH - 1;
		cub3d->ray_dir_x = cub3d->dir_x + cub3d->plane_x * camera_x;
		cub3d->ray_dir_y = cub3d->dir_y + cub3d->plane_y * camera_x;
		delta_dist(cub3d);
		map_x = (int)cub3d->pos_x;
		map_y = (int)cub3d->pos_y;
		hit = 0;
		cub3d->side = 0;
		p_steps(cub3d, map_x, map_y);
		perform_dda(cub3d, hit, map_x, map_y);
		wall_dist(cub3d);
		texturing_calculations(cub3d);
		print_line(cub3d, 0xFFFF00, x);
	}
	mlx_image(cub3d);
}
