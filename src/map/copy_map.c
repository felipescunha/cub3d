/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:22:43 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/10 22:25:55 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub3d.h"

void	copy_map(t_cub3d *cub3d)
{   
    int i;
    int j;
    
    i = get_range(cub3d);
    j = 0; 
    cub3d->map = ft_calloc((cub3d->read_lines - i) + 1 , sizeof(*cub3d->map));
    if(!cub3d->map)
        return ;
    while (cub3d->file[i])
    {
        cub3d->map[j] = ft_strdup(cub3d->file[i]);
        ft_printf("%s\n", cub3d->map[j]);
        i++;
        j++;
    }
}