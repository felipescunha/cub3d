/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:41:43 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/22 00:42:33 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	chars(char x)
{
	if (x == '0' || x == 'N' || x == 'S' || x == 'E' || x == 'W')
		return (1);
	return (0);
}

static int	check_wall(t_cub3d *cub3d, size_t line, size_t col)
{
	if (cub3d->full_map[line])
	{
		if (line != 0 && col != 0 && chars(cub3d->full_map[line - 1][col - 1]))
			return (1);
		if (col != 0 && chars(cub3d->full_map[line][col - 1]))
			return (1);
		if (line < cub3d->temp_line && col != 0
			&& chars(cub3d->full_map[line + 1][col - 1]))
			return (1);
		if (line != 0 && chars(cub3d->full_map[line - 1][col]))
			return (1);
		if (chars(cub3d->full_map[line][col]))
			return (1);
		if (line < cub3d->temp_line && chars(cub3d->full_map[line + 1][col]))
			return (1);
		if (line != 0 && col < cub3d->temp_collunm
			&& chars(cub3d->full_map[line - 1][col + 1]))
			return (1);
		if (col < cub3d->temp_collunm && chars(cub3d->full_map[line][col + 1]))
			return (1);
		if (line < cub3d->temp_line && col < cub3d->temp_collunm
			&& chars(cub3d->full_map[line + 1][col + 1]))
			return (1);
	}
	return (0);
}

int	validation_wall(t_cub3d *cub3d)
{
	int		flag;
	size_t	line;
	size_t	col;
	size_t	max_col;

	flag = 0;
	line = 0;
	max_col = ft_strlen(cub3d->full_map[0]);
	while (cub3d->full_map[line])
	{
		col = 0;
		while (col < (size_t)max_col)
		{
			if (cub3d->full_map[line][col] == ' ')
				flag = check_wall(cub3d, line, col);
			if (flag == 1)
				print_error("Close walls\n");
			col++;
		}
		line++;
	}
	return (0);
}
