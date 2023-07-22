/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:44:46 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/21 23:36:33 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_map(t_cub3d *cub3d)
{
	cub3d->i = 0;
	while (cub3d->file[cub3d->i])
		free(cub3d->file[cub3d->i++]);
	free(cub3d->file);
	cub3d->i = 0;
	while (cub3d->coordinate[cub3d->i])
		free(cub3d->coordinate[cub3d->i++]);
	free(cub3d->coordinate);
	cub3d->i = 0;
	while (cub3d->texture[cub3d->i])
		free(cub3d->texture[cub3d->i++]);
	free(cub3d->texture);
	cub3d->i = 0;
	while (cub3d->map[cub3d->i])
		free(cub3d->map[cub3d->i++]);
	free(cub3d->map);
}
