/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:20:09 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/19 17:29:00 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	close_game(t_cub3d *cub3d)
{
	mlx_destroy_window(cub3d->mlx_ptr, cub3d->win_ptr);
	exit(0);
}

int	click_x(t_cub3d *cub3d)
{
	mlx_destroy_window(cub3d->mlx_ptr, cub3d->win_ptr);
	exit(0);
	return (0);
}

int    key_press(int keycode, t_cub3d *cub3d)
{
	if (keycode == KEY_ESC)
	{
		close_game(cub3d);
	}
		
	if (keycode == KEY_UP)
	{
		move_forward(cub3d);
	}	
		
	if (keycode == KEY_DOWN)
	{
		move_backward(cub3d);
	}	
		
	if (keycode == KEY_LEFT)
	{
		move_left(cub3d);
	}	
		
	if (keycode == KEY_RIGHT)
	{
		move_right(cub3d);
	}	
	if (keycode == CAM_ARROW_RIGHT)
	{
        rotate_camera(cub3d, ROTATION_RIGHT);
	}
    if (keycode == CAM_ARROW_LEFT)
	{
        rotate_camera(cub3d, ROTATION_LEFT);
	}
		
    return (0);
}
/* void verify_wall(t_cub3d *cub3d)
{
	while (cub3d->full_map)
	{
		
	}
} */

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
	// end windows

	load_texture(&cub3d, &cub3d.textures.north, cub3d.texture[3]);

	raycast(&cub3d);
	mlx_hook(cub3d.win_ptr, 2, 1L << 0, key_press, &cub3d);
	//verify_wall(&cub3d);
	//print_map(&cub3d);
	mlx_loop(cub3d.mlx_ptr);
	free_full_map(&cub3d);
	free_map(&cub3d);
	return (0);
}
