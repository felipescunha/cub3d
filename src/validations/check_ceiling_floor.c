/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ceiling_floor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:20:42 by learn             #+#    #+#             */
/*   Updated: 2023/07/11 15:49:19 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int check_ceiling_floor(t_cub3d *cub3d, int i)

{
    int count = 0;
    cub3d->total = 0;

    if(ft_strncmp(ft_strtrim(cub3d->file[i], ""), "NO", 2) == 0)
    {
        count += 1;
        cub3d->total += 1;
    }
    else if(ft_strncmp(ft_strtrim(cub3d->file[i], " "), "SO", 2) == 0)
    {
        count += 1;
        cub3d->total += 2;
    }
    else if(ft_strncmp(ft_strtrim(cub3d->file[i], " "), "WE", 2) == 0)
    {
        count += 1;
        cub3d->total += 4;
    }   
    else if(ft_strncmp(ft_strtrim(cub3d->file[i], " "), "EA", 2) == 0)
    {
        count += 1;
        cub3d->total += 8;
    }
    return 0;
}
