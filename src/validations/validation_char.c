/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 20:07:38 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/17 14:16:46 by fecunha          ###   ########.fr       */
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
					flag++;

			if (cub3d->map[i] && (cub3d->map[i][j] != 32
				&& cub3d->map[i][j] != '1' && cub3d->map[i][j] != '0'
				&& cub3d->map[i][j] != 'N' && cub3d->map[i][j] != 'S'
				&& cub3d->map[i][j] != 'W' && cub3d->map[i][j] != 'E' ))
				print_error("Only characters 1, 0, N, S, W, E or Spaces are permited\n");
			j++;
		}
		i++;
	}
	if (flag == 0)
		print_error("Need a position N, S, W, or E \n");
	if (flag > 1 )
		print_error("More then one player detected\n");
}
