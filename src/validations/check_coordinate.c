/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coordinate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 21:00:22 by learn             #+#    #+#             */
/*   Updated: 2023/07/10 15:18:17 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_coordinate(t_cub3d *cub3d)
{
	int		j;
	int		fd;
	char	*extension;

	j = 0;
	cub3d->index = 0;
	while (cub3d->index < cub3d->read_lines)
	{
		j = 0;
		while (j < 4)
		{
			if (ft_strncmp(cub3d->file[cub3d->index], cub3d->coordinate[j], 2) == 0)
			{
				if (ft_strchr(cub3d->file[cub3d->index], '/'))
				{
					fd = open(ft_strchr(cub3d->file[cub3d->index], '.'), O_RDONLY);
					if (fd < 0)
						printf("Error in texture file!\n----------\n");
					extension = ft_strrchr(cub3d->file[cub3d->index], '.');
					if (!extension)
						print_error("The map not found!\n");
					if (ft_strncmp(extension, ".xpm", 5))
						print_error("The file needed .xpm extension\n");
				}
			}
			j++;
		}
		cub3d->index++;
	}
}
