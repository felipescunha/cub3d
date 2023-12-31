/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color_ceiling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:08:50 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/22 18:54:36 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	check_range_of_number(t_cub3d *cub3d)
{
	if (cub3d->ceil.red < 0 || cub3d->ceil.red > 255)
		print_error("the red valeu in ceiling is not correct!\n");
	if (cub3d->ceil.green < 0 || cub3d->ceil.green > 255)
		print_error("the green valeu in ceiling is not correct!\n");
	if (cub3d->ceil.blue < 0 || cub3d->ceil.blue > 255)
		print_error("the blue valeu in ceiling is not correct!\n");
}

void	check_color_ceiling(t_cub3d *cub3d, int i)
{
	if (ft_strchr(cub3d->file[i], 'C'))
	{
		if (!cub3d->verify_ceiling)
		{
			check_comma(cub3d->file[i]);
			cub3d->verify_ceiling = ft_split_comma(cub3d->file[i]);
			cub3d->ceil.red = ft_atoi_digit(cub3d->verify_ceiling[1]);
			cub3d->ceil.green = ft_atoi_digit(cub3d->verify_ceiling[2]);
			cub3d->ceil.blue = ft_atoi_digit(cub3d->verify_ceiling[3]);
			if (ft_array_size(cub3d->verify_ceiling) != 4)
				print_error("the correct struct is: C 255,255,255\n");
			ft_free_array(cub3d->verify_ceiling);
			if (cub3d->verify_ceiling)
				check_range_of_number(cub3d);
		}
		cub3d->total += 32;
	}
}
