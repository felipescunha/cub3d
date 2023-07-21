/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 20:07:38 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/21 13:13:02 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

#include "../includes/cub3d.h"

int    permited_char(t_cub3d *cub3d, int i)
{
    while (cub3d->map[i][cub3d->i ])
    {
        if (cub3d->map[i] && (cub3d->map[i][cub3d->i] == 'N'
            || cub3d->map[i][cub3d->i] == 'S' || cub3d->map[i][cub3d->i] == 'W'
            || cub3d->map[i][cub3d->i] == 'E'))
            return (1);    
        if (cub3d->map[i] && (cub3d->map[i][cub3d->i] != 32
            && cub3d->map[i][cub3d->i] != '1' && cub3d->map[i][cub3d->i] != '0'
            && cub3d->map[i][cub3d->i] != 'N' && cub3d->map[i][cub3d->i] != 'S'
            && cub3d->map[i][cub3d->i] != 'W' && cub3d->map[i][cub3d->i] != 'E' ))
            return (2);
        cub3d->i++;
    }
    return (0);
}

void    validation_char(t_cub3d *cub3d)
{
    size_t    i;
    int        flag;

    i = 0;
    flag = 0;
    while (i < ft_array_size(cub3d->map) - 1)
    {
        cub3d->i = 0;
        if (permited_char(cub3d, i) == 1)
        {
            flag++;
            cub3d->map[i][cub3d->i] = '0';
            cub3d->pos_x = cub3d->i + 0.5;
            cub3d->pos_y = i + 0.5;
        }
        if (permited_char(cub3d, i) == 2)
            print_error("Only 1, 0, N, S, W, E or Spaces are permited\n");
        i++;
    }
    if (flag == 0)
        print_error("Need a position N, S, W, or E \n");
    if (flag > 1)
        print_error("More then one player detected\n");
}