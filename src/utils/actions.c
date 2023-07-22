/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:19:31 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/22 19:20:39 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	close_game(t_cub3d *cub3d)
{
	mlx_destroy_window(cub3d->mlx, cub3d->win);
	free_map(cub3d);
	exit(0);
}

int	click_x(t_cub3d *cub3d)
{
	free_map(cub3d);
	mlx_destroy_window(cub3d->mlx, cub3d->win);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_cub3d *cub3d)
{
	if (keycode == KEY_ESC)
		close_game(cub3d);
	if (keycode == KEY_UP)
		move_forward(cub3d);
	if (keycode == KEY_DOWN)
		move_backward(cub3d);
	if (keycode == KEY_LEFT)
		move_left(cub3d);
	if (keycode == KEY_RIGHT)
		move_right(cub3d);
	if (keycode == CAM_ARROW_RIGHT)
		rotate_camera(cub3d, cub3d->rotation_speed, ROTATION_RIGHT);
	if (keycode == CAM_ARROW_LEFT)
		rotate_camera(cub3d, cub3d->rotation_speed, ROTATION_LEFT);
	return (0);
}
