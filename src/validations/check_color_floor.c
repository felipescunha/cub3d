/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color_floor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learn <learn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:08:55 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/01 01:18:00 by learn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void print_floor_value(t_cub3d *cub3d)
{
	ft_printf("\n------------------------\n\n");
	ft_printf("ceiling\n");
	ft_printf("%i\n",cub3d->floor.red);
	ft_printf("%i\n",cub3d->floor.green);
	ft_printf("%i\n",cub3d->floor.blue);
	ft_printf("------------------------\n\n");
}

static void check_range_of_number(t_cub3d *cub3d)
{
	if(cub3d->floor.red < 0 || cub3d->floor.red > 255)
		print_error("the red valeu in floor is not correct!");
	if(cub3d->floor.green < 0 || cub3d->floor.green > 255)
		print_error("the green valeu in floor is not correct!");
	if(cub3d->floor.blue < 0 || cub3d->floor.blue > 255)
		print_error("the blue valeu in floor is not correct!");
	printf("\n");
}

void check_color_floor(t_cub3d *cub3d)
{
	char	**floor;
	int		i;

	i = 0;
	while (i < cub3d->read_lines)
	{
		if(ft_strchr(cub3d->file[i], 'F'))
		{
			floor  = ft_split_comma(cub3d->file[i]);
			if(ft_array_size(floor) != 4)
				print_error("the correct struct is: F 255,255,255");
			cub3d->floor.red = ft_atoi_digit(floor[1]);
			cub3d->floor.green = ft_atoi_digit(floor[2]);
			cub3d->floor.blue = ft_atoi_digit(floor[3]);
		}
		i++;
	}
	ft_array_size(floor);
	ft_free_array(floor);
	check_range_of_number(cub3d);
}