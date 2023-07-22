/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color_floor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:08:55 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/21 20:58:06 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	check_range_of_number(t_cub3d *cub3d)
{
	if (cub3d->floor.red < 0 || cub3d->floor.red > 255)
		print_error("the red value in floor is not correct!\n");
	if (cub3d->floor.green < 0 || cub3d->floor.green > 255)
		print_error("the green value in floor is not correct!\n");
	if (cub3d->floor.blue < 0 || cub3d->floor.blue > 255)
		print_error("the blue value in floor is not correct!\n");
}

void	check_color_floor(t_cub3d *cub3d, int i)
{
	if (ft_strchr(cub3d->file[i], 'F'))
	{
		if (!cub3d->verify_floor)
		{
			check_comma(cub3d->file[i]);
			cub3d->verify_floor = ft_split_comma(cub3d->file[i]);
			cub3d->floor.red = ft_atoi_digit(cub3d->verify_floor[1]);
			cub3d->floor.green = ft_atoi_digit(cub3d->verify_floor[2]);
			cub3d->floor.blue = ft_atoi_digit(cub3d->verify_floor[3]);
			if (ft_array_size(cub3d->verify_floor) != 4)
				print_error("the correct struct is: F 255,255,255\n");
			ft_free_array(cub3d->verify_floor);
			if (cub3d->verify_floor)
				check_range_of_number(cub3d);
		}
		cub3d->total += 16;
	}
}
