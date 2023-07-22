/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:27:16 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/22 15:22:53 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_extension(t_cub3d *cub3d)
{
	int		i;
	int		fd;

	i = 0;
	while (i < 4)
	{
		fd = open(cub3d->texture[i], O_RDONLY);
		if (fd < 0)
			print_error("In texture file!\n");
		i++;
	}
}

int	verify_extension(t_cub3d *cub3d, int i)
{
	char	*extension;
	extension = ft_strrchr(cub3d->file[i], '.');
	if (!extension)
		print_error("The map not found!\n");
	if (ft_strncmp(extension, ".xpm", 5))
		print_error("The file needed .xpm extension\n");
	i++;
	return (i);
}
