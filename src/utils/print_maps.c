/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:25:28 by learn             #+#    #+#             */
/*   Updated: 2023/07/22 15:26:26 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_map(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (cub3d->map[i])
		printf("%s\n", cub3d->map[i++]);
}

void	print_full_map(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (cub3d->full_map[i])
		printf("%s\n", cub3d->full_map[i++]);
}
