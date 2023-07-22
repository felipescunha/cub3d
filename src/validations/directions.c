/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:01:20 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/22 18:01:48 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	direction_no(t_cub3d *cub3d, char **tmp_split, int i)
{
	if (!cub3d->texture[0])
		cub3d->texture[0] = ft_strdup(ft_split_texture(tmp_split));
	verify_extension(cub3d, i);
	cub3d->total += 1;
}

void	direction_so(t_cub3d *cub3d, char **tmp_split, int i)
{
	if (!cub3d->texture[1])
		cub3d->texture[1] = ft_strdup(ft_split_texture(tmp_split));
	verify_extension(cub3d, i);
	cub3d->total += 2;
}

void	direction_we(t_cub3d *cub3d, char **tmp_split, int i)
{
	if (!cub3d->texture[2])
		cub3d->texture[2] = ft_strdup(ft_split_texture(tmp_split));
	verify_extension(cub3d, i);
	cub3d->total += 4;
}

void	direction_ea(t_cub3d *cub3d, char **tmp_split, int i)
{
	if (!cub3d->texture[3])
		cub3d->texture[3] = ft_strdup(ft_split_texture(tmp_split));
	verify_extension(cub3d, i);
	cub3d->total += 8;
}
