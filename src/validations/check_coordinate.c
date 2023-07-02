/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coordinate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learn <learn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 21:00:22 by learn             #+#    #+#             */
/*   Updated: 2023/07/02 18:00:36 by learn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void check_coordinate(t_cub3d *cub3d)
{
	int		i;
	int		j;
	int		fd;
	char	*extension;
	char    *coordinate[] = {"NO","SO","WE","EA"};
	
	i = 0;
	j = 0;

	while (i < cub3d->read_lines)
	{
		j = 0;
		while (j < 4)
		{
			if(ft_strncmp(cub3d->file[i], coordinate[j], 2) == 0)
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
			j++;
		}
		i++;
	}
}