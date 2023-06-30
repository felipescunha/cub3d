/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color_floor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:08:55 by fecunha           #+#    #+#             */
/*   Updated: 2023/06/29 21:54:22 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void free_floor(char **floor)
{
    int i;

    i = 0;
    while (floor[i])
        free(floor[i++]);
    free(floor);
}

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
	if(cub3d->floor.green < 0 || cub3d->floor.red > 255)
		print_error("the green valeu in floor is not correct!");
	if(cub3d->floor.blue < 0 || cub3d->floor.red > 255)
		print_error("the blue valeu in floor is not correct!");
	printf("\n");
}

;

void check_color_floor(t_cub3d *cub3d)
{
	int i;
	char **floor = malloc(sizeof(4));
	i = 0;
	while (i < cub3d->read_lines)
	{
		if(ft_strchr(cub3d->file[i], 'F'))
		{
			floor  = ft_split_comma(cub3d->file[i]);
			cub3d->floor.red = ft_atoi(floor[1]);
			cub3d->floor.green = ft_atoi(floor[2]);
			cub3d->floor.blue = ft_atoi(floor[3]);
		}
		i++;
	}
	free_floor(floor);
	check_range_of_number(cub3d);
}