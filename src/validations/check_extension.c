/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:27:16 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/22 18:14:13 by fecunha          ###   ########.fr       */
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

void	validation_map_name(int argc, char *argv)
{
	char	*extension;

	if (argc != 2)
		print_error("Number of arguments diferents that two Cadet\n");
	extension = ft_strrchr(argv, '.');
	if (!extension)
		print_error("The map not found!\n");
	if (ft_strncmp(extension, ".cub", 5))
		print_error("The map must contain the .cub extension\n");
}
