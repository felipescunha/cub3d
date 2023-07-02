/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coordinate_no.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 21:00:22 by learn             #+#    #+#             */
/*   Updated: 2023/07/01 21:40:43 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void check_coordinate_no(t_cub3d *cub3d)
{
	int		i;
	int		fd;
	char	*extension;

	i = 0;
	while (i < cub3d->read_lines)
	{
		if(ft_strncmp(cub3d->file[i], "NO", 2) == 0)
		{
			if(ft_strchr(cub3d->file[i], '/'))
			{
				fd = open(ft_strchr(cub3d->file[i], '.'), O_RDONLY);
				if(fd < 0)
					printf("Error in texture file!\n----------\n");
				extension = ft_strrchr(cub3d->file[i], '.');
				if (!extension)
					print_error("The map not found!\n");
				if (ft_strncmp(extension, ".xpm", 5))
					print_error("The file needed .xpm extension\n");
			}
		}
		i++;
	}
}