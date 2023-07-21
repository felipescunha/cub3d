/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:20:09 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/21 17:28:02 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	close_game(t_cub3d *cub3d)
{
	free_full_map(&cub3d);
	free_map(&cub3d);
	mlx_destroy_window(cub3d->mlx_ptr, cub3d->win_ptr);
	exit(0);
}

int	click_x(t_cub3d *cub3d)
{
	free_full_map(&cub3d);
	free_map(&cub3d);
	mlx_destroy_window(cub3d->mlx_ptr, cub3d->win_ptr);
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
		rotate_camera(cub3d,cub3d->rotation_speed, ROTATION_RIGHT);
	if (keycode == CAM_ARROW_LEFT)
		rotate_camera(cub3d,cub3d->rotation_speed, ROTATION_LEFT);
	return (0);
}

void free_full_map(t_cub3d *cub3d)
{
	int i = 0 ;
	while (cub3d->full_map[i])
		free(cub3d->full_map[i++]);
	free(cub3d->full_map);
}

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;
	if (argc != 2)
		print_error("Number of argument is inválid\n");
	starting_values_in_struct(&cub3d);
	validation_map_name(argc, argv[1]);
	read_map(&cub3d, argv[1]);										
	copy_file(&cub3d, argv[1]);
	validations(&cub3d);
	copy_map(&cub3d);
	validation_char(&cub3d);
	fill_rows(&cub3d);
	//window
	cub3d.mlx_ptr = mlx_init();
	cub3d.win_ptr = mlx_new_window(cub3d.mlx_ptr, SCREENWIDTH, SCREENHEIGHT, "Cub3D Raycaster Game");
	cub3d.img.img = mlx_new_image(cub3d.mlx_ptr, SCREENWIDTH, SCREENHEIGHT);
	cub3d.img.addr = mlx_get_data_addr(cub3d.img.img, &cub3d.img.bits_per_pixel,
	&cub3d.img.line_length, &cub3d.img.endian);
	//End windows

	load_texture(&cub3d, &cub3d.textures.north, cub3d.texture[0]);
	load_texture(&cub3d, &cub3d.textures.south, cub3d.texture[1]);
	load_texture(&cub3d, &cub3d.textures.west, cub3d.texture[2]);
	load_texture(&cub3d, &cub3d.textures.east, cub3d.texture[3]);
	mlx_hook(cub3d.win_ptr, 17, 0, click_x, &cub3d);
	mlx_hook(cub3d.win_ptr, 2, 1L << 0, key_press, &cub3d);
	position_player_in_map(&cub3d);
	mlx_loop(cub3d.mlx_ptr);
	return (0);
}
