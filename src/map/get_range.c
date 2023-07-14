/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_range.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:22:43 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/13 17:41:11 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub3d.h"

int get_range(t_cub3d *cub3d)
{   
    int i;
    int j;
    
    i = 0;
    while (cub3d->file[i])
    {
        j = 0;
        if (cub3d->file[i][j] == 32 && j == 0)
            while (cub3d->file[i] && cub3d->file[i][j] == 32)
                j++;            
        if (cub3d->file[i] && cub3d->file[i][j] != '0' && cub3d->file[i][j] != '1')
           i++;
        else
            break;
    }
    return i;
}