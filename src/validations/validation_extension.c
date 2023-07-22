/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_extension.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:35:00 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/22 00:42:14 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
