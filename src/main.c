/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learn <learn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:20:09 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/01 02:18:28 by learn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	print_file(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (i < cub3d->read_lines)
	{
		printf("%s\n", cub3d->file[i++]);
	}
}

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;

	if (argc != 2)
	{
		printf("Number of argument is inválid\n");
		return (0);
	}
	ft_memset(&cub3d, 0, sizeof(t_cub3d));
	validation_map_name(argc, argv[1]);
	read_map(&cub3d, argv[1]);										
	copy_file(&cub3d, argv[1]);
	check_color_floor(&cub3d);
	check_color_ceiling(&cub3d);
	check_coordinate_no(&cub3d);
	print_file(&cub3d);
	//free_map(&cub3d);
	return (0);
}
