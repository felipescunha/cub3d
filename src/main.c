/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:20:09 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/22 19:26:57 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	starting(t_cub3d *cub3d)
{	
	validations(cub3d);
	copy_map(cub3d);
	validation_char(cub3d);
	fill_rows(cub3d);
	validation_wall(cub3d);
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
	starting(&cub3d);
	cub3d.mlx = mlx_init();
	cub3d.win = mlx_new_window(cub3d.mlx, SCREENWIDTH, SCREENHEIGHT, "Cub3D");
	cub3d.img.img = mlx_new_image(cub3d.mlx, SCREENWIDTH, SCREENHEIGHT);
	cub3d.img.addr = mlx_get_data_addr(cub3d.img.img,
			&cub3d.img.bits_per_pixel,
			&cub3d.img.line_length, &cub3d.img.endian);
	load_texture(&cub3d, &cub3d.textures.north, cub3d.texture[0]);
	load_texture(&cub3d, &cub3d.textures.south, cub3d.texture[1]);
	load_texture(&cub3d, &cub3d.textures.west, cub3d.texture[2]);
	load_texture(&cub3d, &cub3d.textures.east, cub3d.texture[3]);
	mlx_hook(cub3d.win, 17, 0, click_x, &cub3d);
	mlx_hook(cub3d.win, 2, 1L << 0, key_press, &cub3d);
	position_player_in_map(&cub3d);
	mlx_loop(cub3d.mlx);
	return (0);
}
