/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:20:09 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/17 14:58:03 by fecunha          ###   ########.fr       */
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
	//verify_wall(&cub3d);
	print_map(&cub3d);
	free_full_map(&cub3d);
	free_map(&cub3d);
	return (0);
}
