/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ceiling_floor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:20:42 by learn             #+#    #+#             */
/*   Updated: 2023/07/10 17:52:52 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void check_ceiling_floor(t_cub3d *cub3d)

{
    int total = 0;
    int count = 0;

    cub3d->index = 0;
    while (cub3d->index < cub3d->read_lines)
    {
        if(ft_strncmp(ft_strtrim(cub3d->file[cub3d->index], ""), "NO", 2) == 0)
        {
            count += 1;
            total += 1;
        }
        else if(ft_strncmp(ft_strtrim(cub3d->file[cub3d->index], " "), "SO", 2) == 0)
        {
            count += 1;
            total += 2;
        }
        else if(ft_strncmp(ft_strtrim(cub3d->file[cub3d->index], " "), "WE", 2) == 0)
        {
            count += 1;
            total += 4;
        }   
        else if(ft_strncmp(ft_strtrim(cub3d->file[cub3d->index], " "), "EA", 2) == 0)
        {
            count += 1;
            total += 8;
        }
        else if(ft_strncmp(ft_strtrim(cub3d->file[cub3d->index], " "), "F", 1) == 0)
        {
            count += 1;
            total += 16;
        }
        else if(ft_strncmp(ft_strtrim(cub3d->file[cub3d->index], " "), "C", 1) == 0)
        {
            count += 1;
            total += 32;
        }
        cub3d->index++;
    }
    if (total != 63 || count != 6)
        print_error("Map is not correct!\n");
}