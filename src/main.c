/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:20:09 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/18 18:28:20 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"



void verify_wall(t_cub3d *cub3d)
{
	while (cub3d->full_map)
	{
		
	}
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
	raycast(&cub3d);

	cub3d.mlx_ptr = mlx_init();
	cub3d.win_ptr = mlx_new_window(cub3d.mlx_ptr, 640, 640, "Cub3D Raycaster Game");
		
	//verify_wall(&cub3d);
	print_map(&cub3d);
	mlx_loop(cub3d.mlx_ptr);
	free_full_map(&cub3d);
	free_map(&cub3d);
	return (0);
}
