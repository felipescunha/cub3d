/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completing_lines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:44:22 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/21 23:52:58 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static char	*fill(char *line, int max_col)
{
	int		len;
	char	*tmp_line;

	len = ft_strlen(line);
	tmp_line = my_realloc(line, max_col + 2);
	while (len < max_col +1)
		tmp_line[len++] = ' ';
	return (tmp_line);
}

static void	fill_copy_map(t_cub3d *cub3d)
{
	int		max_size;
	size_t	last_line;

	last_line = cub3d->array_size -1;
	max_size = cub3d->biggest_line + 1;
	cub3d->full_map[0] = ft_calloc(sizeof(char), max_size);
	cub3d->full_map[last_line] = ft_calloc(sizeof(char), max_size);
	cub3d->full_map[0] = fill(cub3d->full_map[0], max_size);
	cub3d->full_map[last_line] = fill(cub3d->full_map[last_line], max_size);
}

int	fill_rows(t_cub3d *cub3d)
{
	size_t	i;
	int		j;
	char	*tmp_line;

	i = 0;
	j = 1;
	cub3d->array_size = ft_array_size(cub3d->map) + 2;
	cub3d->full_map = ft_calloc(sizeof(char *), cub3d->array_size);
	if (!cub3d->full_map)
		return (1);
	fill_copy_map(cub3d);
	while (cub3d->map[i] && i < cub3d->array_size - 3)
	{
		tmp_line = ft_strjoin(" ", cub3d->map[i]);
		cub3d->full_map[j++] = fill(tmp_line, cub3d->biggest_line + 1);
		i++;
	}
	cub3d->temp_line = ft_array_size(cub3d->full_map) - 1;
	cub3d->temp_collunm = ft_strlen(cub3d->full_map[0]);
	return (0);
}
