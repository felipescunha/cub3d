/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 20:07:38 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/20 21:35:20 by fecunha          ###   ########.fr       */
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
			{
				flag++;
				cub3d->map[i][j] = '0';
				cub3d->pos_x = j + 0.5;
				cub3d->pos_y = i + 0.5;
			}
			if (cub3d->map[i] && (cub3d->map[i][j] != 32
				&& cub3d->map[i][j] != '1' && cub3d->map[i][j] != '0'
				&& cub3d->map[i][j] != 'N' && cub3d->map[i][j] != 'S'
				&& cub3d->map[i][j] != 'W' && cub3d->map[i][j] != 'E' ))
				print_error("Only characters 1, 0, N, S, W, E or Spaces are permited\n");
			j++;
		}
		i++;
	}
	printf("i: %li | j: %i\n", i, j);
	if (flag == 0)
		print_error("Need a position N, S, W, or E \n");
	if (flag > 1 )
		print_error("More then one player detected\n");
}
