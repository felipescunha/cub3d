/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:20:09 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/10 17:46:41 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void set_value_in_coordinate(t_cub3d *cub3d)
{
	cub3d->coordinate = ft_calloc(5, sizeof(char *));
	cub3d->coordinate[0] = ft_strdup("NO");
	cub3d->coordinate[1] = ft_strdup("SO");
	cub3d->coordinate[2] = ft_strdup("WE");
	cub3d->coordinate[3] = ft_strdup("EA");
}

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
	set_value_in_coordinate(&cub3d);
	validation_map_name(argc, argv[1]);
	read_map(&cub3d, argv[1]);										
	copy_file(&cub3d, argv[1]);
	//validation_char(&cub3d);
	check_ceiling_floor(&cub3d);
	check_color_ceiling(&cub3d);
	check_color_floor(&cub3d);
	check_coordinate(&cub3d);
	print_file(&cub3d);
	free_map(&cub3d);
	return (0);
}
