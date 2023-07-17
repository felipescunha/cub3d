/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learn <learn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 20:07:38 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/16 14:06:36 by learn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	validation_char(t_cub3d *cub3d)
{
	size_t	i;
	int	j;
	int flag = 0;
	
	i = 0;
	while (i < ft_array_size(cub3d->map) - 1)
	{
		j = 0;
		while (cub3d->map[i][j])
		{
			if (cub3d->map[i] && (cub3d->map[i][j] == 'N'
				|| cub3d->map[i][j] == 'S' || cub3d->map[i][j] == 'W'
				|| cub3d->map[i][j] == 'E'))
					flag--;
			if (cub3d->map[i] && (cub3d->map[i][j] != 32
				&& cub3d->map[i][j] != '1' && cub3d->map[i][j] != '0'
				&& cub3d->map[i][j] != 'N' && cub3d->map[i][j] != 'S'
				&& cub3d->map[i][j] != 'W' && cub3d->map[i][j] != 'E' ))
				print_error("Error\n Only 1, 0, N, S, W, E or Spaces\n");
			j++;
		}
		i++;
	}
	if (flag > -1)
		print_error("Need a position N, S, W, or E \n");
}

/* int	check_map_x_y(t_cub3d *cub3d)
{
	if (radar_validation(cub3d))
		return (ret_value(1, "Close map around spaces"));
	free_matrix(cub3d->full_map);
	return (0);
} */