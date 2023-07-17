/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learn <learn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:50:52 by learn             #+#    #+#             */
/*   Updated: 2023/07/16 12:32:52 by learn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	pulse(char x)
{
	if (x == '0' || x == 'N' || x == 'S' || x == 'E' || x == 'W')
		return (1);
	return (0);
}

int	verify_content(t_cub3d *cub3d, int flag)
{
	int	i;
	int	j;

	i = 0;
	while (i < ft_array_size(cub3d->map) -1)
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
				return (ret_value(1, "Only 1, 0, N, S, W, E or Spaces"));
			j++;
		}
		i++;
	}
	if (flag != 0)
		return (ret_value(1, "Need a position (N, S, W, or E)"));
	return (flag);
}

int	check_map_x_y(t_cub3d *cub3d)
{
	if (radar_validation(cub3d))
		return (ret_value(1, "Close map around spaces"));
	//free_matrix(cub3d->temp_map);
	return (0);
}