/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_player_in_map.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:21:47 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/21 19:33:58 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	position_player_in_map(t_cub3d *cub3d)
{
	if (cub3d->target_player == 'N')
		raycast(cub3d);
	else if (cub3d->target_player == 'S')
		rotate_camera(cub3d, M_PI, ROTATION_LEFT);
	else if (cub3d->target_player == 'E')
		rotate_camera(cub3d, M_PI / 2, ROTATION_RIGHT);
	else if (cub3d->target_player == 'W')
		rotate_camera(cub3d, M_PI / 2, ROTATION_LEFT);	
}