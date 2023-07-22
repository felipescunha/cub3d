/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 20:07:38 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/22 00:42:36 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	permited_char(t_cub3d *c, int i)
{
	while (c->map[c->j][c->i])
	{
		if (c->map[c->j] && (c->map[c->j][c->i] == 'N'
			|| c->map[c->j][c->i] == 'S' || c->map[c->j][c->i] == 'W'
			|| c->map[c->j][c->i] == 'E'))
		{
			i = c->i;
			while (c->map[c->j][i])
			{
				i++;
				if (c->map[c->j] && (c->map[c->j][i] == 'N'
					|| c->map[c->j][i] == 'S' || c->map[c->j][i] == 'W'
					|| c->map[c->j][i] == 'E'))
					print_error("More then one player detected\n");
			}
			return (1);
		}
		if (c->map[c->j] && (c->map[c->j][c->i] != 32
			&& c->map[c->j][c->i] != '1' && c->map[c->j][c->i] != '0'
			&& c->map[c->j][c->i] != 'N' && c->map[c->j][c->i] != 'S'
			&& c->map[c->j][c->i] != 'W' && c->map[c->j][c->i] != 'E'))
			return (2);
		c->i++;
	}
	return (0);
}

void	validation_char(t_cub3d *cub3d)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (cub3d->j < ft_array_size(cub3d->map) - 1)
	{
		cub3d->i = 0;
		if (permited_char(cub3d, i) == 1)
		{
			flag++;
			cub3d->target_player = cub3d->map[cub3d->j][cub3d->i];
			cub3d->map[cub3d->j][cub3d->i] = '0';
			cub3d->pos_x = cub3d->i + 0.5;
			cub3d->pos_y = cub3d->j + 0.5;
		}
		if (permited_char(cub3d, i) == 2)
			print_error("Only 1, 0, N, S, W, E or Spaces are permited\n");
		cub3d->j++;
	}
	if (flag == 0)
		print_error("Need a position N, S, W, or E \n");
	if (flag > 1)
		print_error("More then one player detected\n");
}
