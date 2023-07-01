/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coordinate_no.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learn <learn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 21:00:22 by learn             #+#    #+#             */
/*   Updated: 2023/07/01 00:40:20 by learn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void check_coordinate_no(t_cub3d *cub3d)
{

	int		i;
	
	i = 0;

	while (i < cub3d->read_lines)
	{
		if(ft_strncmp(cub3d->file[i], "NO", 2) == 0)
		{
        	ft_printf("%s\n", cub3d->file[i]);
		}
		i++;
	}
}