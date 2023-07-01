/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color_ceiling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learn <learn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:08:50 by fecunha           #+#    #+#             */
/*   Updated: 2023/06/30 21:20:06 by learn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void print_ceiling_value(t_cub3d *cub3d)
{
	ft_printf("\n------------------------\n\n");
	ft_printf("ceiling\n");
	ft_printf("%i\n",cub3d->ceiling.red);
	ft_printf("%i\n",cub3d->ceiling.green);
	ft_printf("%i\n",cub3d->ceiling.blue);
	ft_printf("------------------------\n\n");
}

static void check_range_of_number(t_cub3d *cub3d)
{
	if(cub3d->ceiling.red < 0 || cub3d->ceiling.red > 255)
		print_error("the red valeu in ceiling is not correct!");
	if(cub3d->ceiling.green < 0 || cub3d->ceiling.green > 255)
		print_error("the green valeu in ceiling is not correct!");
	if(cub3d->ceiling.blue < 0 || cub3d->ceiling.blue > 255)
		print_error("the blue valeu in ceiling is not correct!");
	printf("\n");
}

void check_color_ceiling(t_cub3d *cub3d)
{
	char	**ceiling;
	int		i;
	
	i = 0;
	while (i < cub3d->read_lines)
	{
		if(ft_strchr(cub3d->file[i], 'C'))
		{
			ceiling  = ft_split_comma(cub3d->file[i]);
			if(ft_array_size(ceiling) != 4)
				print_error("the correct struct is: C 255,255,255");
			cub3d->ceiling.red = ft_atoi_digit(ceiling[1]);
			cub3d->ceiling.green = ft_atoi_digit(ceiling[2]);
			cub3d->ceiling.blue = ft_atoi_digit(ceiling[3]);
		}
		i++;
	}
	ft_array_size(ceiling);
	ft_free_array(ceiling);
	check_range_of_number(cub3d);
}
