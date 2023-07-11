/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:03:51 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/11 19:27:29 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int  validations(t_cub3d *cub3d)
{
    //void check_coordinate(cub3d);
    int i = 0;
    int size = get_range(cub3d);

    while (i < size)
    {
        check_color_ceiling(cub3d, i);
        check_color_floor(cub3d, i);
        if(ft_strncmp(ft_strtrim(cub3d->file[i], ""), "NO", 2) == 0)
            cub3d->total += 1;
        else if(ft_strncmp(ft_strtrim(cub3d->file[i], " "), "SO", 2) == 0)
            cub3d->total += 2;
        else if(ft_strncmp(ft_strtrim(cub3d->file[i], " "), "WE", 2) == 0)
            cub3d->total += 4;
        else if(ft_strncmp(ft_strtrim(cub3d->file[i], " "), "EA", 2) == 0)
            cub3d->total += 8;
        i++;
    }
    if (cub3d->total != 63)
        print_error("Map is not correct!\n");   
    return 0;
}