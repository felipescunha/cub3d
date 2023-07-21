/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:58:46 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/21 16:11:23 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void move_forward(t_cub3d *cub3d)
{
    if(cub3d->map[(int)cub3d->pos_y][(int)(cub3d->pos_x + cub3d->dir_x * cub3d->move_speed)] == '0')
        cub3d->pos_x += cub3d->dir_x *cub3d->move_speed;
    if(cub3d->map[(int)(cub3d->pos_y + cub3d->dir_y * cub3d->move_speed)][(int)(cub3d->pos_x)] == '0')
        cub3d->pos_y += cub3d->dir_y * cub3d->move_speed;
    raycast(cub3d);
}

void move_backward(t_cub3d *cub3d)
{
    if(cub3d->map[(int)cub3d->pos_y][(int)(cub3d->pos_x - cub3d->dir_x * cub3d->move_speed)] == '0')
        cub3d->pos_x -= cub3d->dir_x *cub3d->move_speed;
    if(cub3d->map[(int)(cub3d->pos_y - cub3d->dir_y * cub3d->move_speed)][(int)(cub3d->pos_x)] == '0')
        cub3d->pos_y -= cub3d->dir_y * cub3d->move_speed;
    raycast(cub3d);
}

void move_right(t_cub3d *cub3d)
{
    if(cub3d->map[(int)cub3d->pos_y][(int)(cub3d->pos_x + cub3d->plane_x * cub3d->move_speed)] == '0')
        cub3d->pos_x += cub3d->plane_x *cub3d->move_speed;
    if(cub3d->map[(int)(cub3d->pos_y + cub3d->plane_y * cub3d->move_speed)][(int)(cub3d->pos_x)] == '0')
        cub3d->pos_y += cub3d->plane_y * cub3d->move_speed;
    raycast(cub3d);
}

void move_left(t_cub3d *cub3d)
{
    if(cub3d->map[(int)cub3d->pos_y][(int)(cub3d->pos_x - cub3d->plane_x * cub3d->move_speed)] == '0')
        cub3d->pos_x -= cub3d->plane_x *cub3d->move_speed;
    if(cub3d->map[(int)(cub3d->pos_y - cub3d->plane_y * cub3d->move_speed)][(int)(cub3d->pos_x)] == '0')
        cub3d->pos_y -= cub3d->plane_y * cub3d->move_speed;
    raycast(cub3d);
}


void rotate_camera(t_cub3d *cub3d, double rotation_speed, int direction)
{
    double old_direction_x;
    double old_plane_x;

    rotation_speed *= direction;
    old_direction_x = cub3d->dir_x;
    cub3d->dir_x = cub3d->dir_x * cos(rotation_speed)
        - cub3d->dir_y * sin(rotation_speed);
    cub3d->dir_y = old_direction_x * sin(rotation_speed)
        + cub3d->dir_y * cos(rotation_speed);
    old_plane_x = cub3d->plane_x;
    cub3d->plane_x = cub3d->plane_x * cos(rotation_speed)
        - cub3d->plane_y * sin(rotation_speed);
    cub3d->plane_y = old_plane_x * sin(rotation_speed)
        + cub3d->plane_y * cos(rotation_speed);
    raycast(cub3d);
}