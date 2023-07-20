/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting_values_in_struct.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:28:57 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/20 17:55:13 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void starting_values_in_struct(t_cub3d *cub3d)
{
    ft_memset(cub3d, 0, sizeof(t_cub3d));
    cub3d->texture = ft_calloc(5, sizeof(char *));
	cub3d->coordinate = ft_calloc(5, sizeof(char *));
	cub3d->coordinate[0] = ft_strdup("NO");
	cub3d->coordinate[1] = ft_strdup("SO");
	cub3d->coordinate[2] = ft_strdup("WE");
	cub3d->coordinate[3] = ft_strdup("EA");
	cub3d->posX = 3;
	cub3d->posY = 3;
	cub3d->dirX = 1;
	cub3d->dirY = 0;
	cub3d->planeX = 0;
	cub3d->step_x = 0;
	cub3d->step_y = 0;
	cub3d->sideDistX = 0;
	cub3d->sideDistY = 0;
	cub3d->deltaDistX = 0;
	cub3d->deltaDistY = 0;
	cub3d->planeY = 0.66;
	cub3d->move_speed = 0.3;
	cub3d->rotation_speed = M_PI / 32;
}

