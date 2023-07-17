/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting_values_in_struct.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:28:57 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/17 14:47:29 by fecunha          ###   ########.fr       */
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
}