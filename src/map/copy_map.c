/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learn <learn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:22:43 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/16 21:11:41 by learn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void check_break_line(t_cub3d *cub3d)
{
    int i;
    int j;
    
    i = 0;
    while (cub3d->map[i])
    {
        j = 0;
        while (cub3d->map[i][j])
        {
            if(cub3d->map[i][j] == '\n')
                print_error("The map dont not be contain break line!\n");
            j++;
        }
        i++;
    }
}

void biggest_line(t_cub3d *cub3d, char *line)
{
	if(cub3d->biggest_line < ft_strlen(line))
		cub3d->biggest_line = ft_strlen(line);
}

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
    {   cub3d->map[j] = ft_strdup(cub3d->file[i]);
        biggest_line(cub3d, cub3d->map[j]);
        i++;
        j++; 
    }
    check_break_line(cub3d);
}