/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learn <learn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:20:09 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/16 21:11:09 by learn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void flood_fill_full_map(t_cub3d *cub3d)
{
	int i = 0;
	int j = 0;

	while (cub3d->full_map[i])
	{
		j = 0;
		while (cub3d->full_map[i][j])
		{
			if(cub3d->full_map[i][j] == 'N')
			{
				cub3d->play_position_x = i;
				cub3d->play_position_y = j;
			}
			j++;
		}
		i++;
	}
}

void set_value_in_coordinate(t_cub3d *cub3d)
{
	cub3d->texture = ft_calloc(5, sizeof(char *));
	cub3d->coordinate = ft_calloc(5, sizeof(char *));
	cub3d->coordinate[0] = ft_strdup("NO  ");
	cub3d->coordinate[1] = ft_strdup("SO  ");
	cub3d->coordinate[2] = ft_strdup("WE  ");
	cub3d->coordinate[3] = ft_strdup("EA  ");
}

void	print_map(t_cub3d *cub3d)
{
	int	i = 0;
	ft_printf("array size: %i\n", cub3d->array_size);
	while (cub3d->full_map[i] && i <=7)
		ft_printf("%s\n", cub3d->full_map[i++]);
	ft_printf("%s\n", cub3d->full_map[cub3d->array_size]);
}

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;

	if (argc != 2)
		print_error("Number of argument is inválid\n");
	ft_memset(&cub3d, 0, sizeof(t_cub3d));
	set_value_in_coordinate(&cub3d);
	validation_map_name(argc, argv[1]);
	read_map(&cub3d, argv[1]);										
	copy_file(&cub3d, argv[1]);
	validations(&cub3d);
	copy_map(&cub3d);
	validation_char(&cub3d);
	fill_rows(&cub3d);
	print_map(&cub3d);
	flood_fill_full_map(&cub3d);
	free_map(&cub3d);
	return (0);
}
