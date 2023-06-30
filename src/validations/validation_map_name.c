/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:35:00 by fecunha           #+#    #+#             */
/*   Updated: 2023/04/15 20:50:17 by fecunha          ###   ########.fr       */
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