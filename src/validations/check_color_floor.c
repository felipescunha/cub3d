/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color_floor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:08:55 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/10 18:18:53 by fecunha          ###   ########.fr       */
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
	int		i;

	i = 0;
	while (i < cub3d->read_lines)
	{
		if(ft_strchr(cub3d->file[i], 'F'))
		{
			cub3d->verify_floor  = ft_split_comma(cub3d->file[i]);
			if(ft_array_size(cub3d->verify_floor) != 4)
				print_error("the correct struct is: F 255,255,255");
			cub3d->floor.red = ft_atoi_digit(cub3d->verify_floor[1]);
			cub3d->floor.green = ft_atoi_digit(cub3d->verify_floor[2]);
			cub3d->floor.blue = ft_atoi_digit(cub3d->verify_floor[3]);
		}
		i++;
	}
	if(!ft_array_size(cub3d->verify_floor))
		print_error("Verify Floor in map!\n");
	if(cub3d->verify_floor)
		ft_free_array(cub3d->verify_floor);
	check_range_of_number(cub3d);
}