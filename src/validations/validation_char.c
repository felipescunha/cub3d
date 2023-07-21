/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 20:07:38 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/20 21:00:19 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	permited_char(t_cub3d *cub3d, int i, int j)
{
	while (cub3d->map[i][j])
	{
		if (cub3d->map[i] && (cub3d->map[i][j] == 'N'
			|| cub3d->map[i][j] == 'S' || cub3d->map[i][j] == 'W'
			|| cub3d->map[i][j] == 'E'))
			return (1);
		if (cub3d->map[i] && (cub3d->map[i][j] != 32
			&& cub3d->map[i][j] != '1' && cub3d->map[i][j] != '0'
			&& cub3d->map[i][j] != 'N' && cub3d->map[i][j] != 'S'
			&& cub3d->map[i][j] != 'W' && cub3d->map[i][j] != 'E' ))
			return (2);
		j++;
	}
	return (0);
}

void	validation_char(t_cub3d *cub3d)
{
	size_t	i;
	int		j;
	int		flag;

	i = 0;
	flag = 0;
	while (i < ft_array_size(cub3d->map) - 1)
	{
		j = 0;
		if (permited_char(cub3d, i, j) == 1)
		{
			flag++;
			cub3d->map[i][j] = '0';
			cub3d->posX = j;
			cub3d->posY = i;
		}
		if (permited_char(cub3d, i, j) == 2)
			print_error("Only 1, 0, N, S, W, E or Spaces are permited\n");
		i++;
	}
	printf("i: %li | j: %i\n", i, j);
	if (flag == 0)
		print_error("Need a position N, S, W, or E \n");
	if (flag > 1)
		print_error("More then one player detected\n");
}
