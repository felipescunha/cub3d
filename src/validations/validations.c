/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:45:28 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/22 18:01:43 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	condenate_condition(t_cub3d *cub3d, char **tmp_split, int i)
{
	char	*tmp_strtrim;

	tmp_strtrim = ft_strtrim(cub3d->file[i], " ");
	if (ft_strncmp(tmp_strtrim, "NO", 2) == 0)
		direction_no(cub3d, tmp_split, i);
	else if (ft_strncmp(tmp_strtrim, "SO", 2) == 0)
		direction_so(cub3d, tmp_split, i);
	else if (ft_strncmp(tmp_strtrim, "WE", 2) == 0)
		direction_we(cub3d, tmp_split, i);
	else if (ft_strncmp(tmp_strtrim, "EA", 2) == 0)
		direction_ea(cub3d, tmp_split, i);
	free(tmp_strtrim);
}

int	validations(t_cub3d *cub3d)
{
	int		i;
	int		j;
	int		size;
	char	**tmp_split;

	i = 0;
	j = 0;
	size = get_range(cub3d);
	cub3d->i = 0;
	while (i < size)
	{
		check_color_ceiling(cub3d, i);
		check_color_floor(cub3d, i);
		tmp_split = ft_split(cub3d->file[i], 32);
		condenate_condition(cub3d, tmp_split, i);
		while (tmp_split[j])
			free(tmp_split[j++]);
		free(tmp_split);
		j = 0;
		i++;
	}
	check_extension(cub3d);
	if (cub3d->total != 63)
		print_error("Map is not correct!\n");
	return (0);
}
