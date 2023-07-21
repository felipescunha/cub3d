/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:58:46 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/20 21:36:56 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void move_forward(t_cub3d *cub3d)
{
    if(cub3d->map[(int)cub3d->pos_y][(int)(cub3d->pos_x + cub3d->dirX * cub3d->move_speed)] == '0')
        cub3d->pos_x += cub3d->dirX *cub3d->move_speed;
    if(cub3d->map[(int)(cub3d->pos_y + cub3d->dirY * cub3d->move_speed)][(int)(cub3d->pos_x)] == '0')
        cub3d->pos_y += cub3d->dirY * cub3d->move_speed;
    raycast(cub3d);
}

void move_backward(t_cub3d *cub3d)
{
    if(cub3d->map[(int)cub3d->pos_y][(int)(cub3d->pos_x - cub3d->dirX * cub3d->move_speed)] == '0')
        cub3d->pos_x -= cub3d->dirX *cub3d->move_speed;
    if(cub3d->map[(int)(cub3d->pos_y - cub3d->dirY * cub3d->move_speed)][(int)(cub3d->pos_x)] == '0')
        cub3d->pos_y -= cub3d->dirY * cub3d->move_speed;
    raycast(cub3d);
}

void move_right(t_cub3d *cub3d)
{
    if(cub3d->map[(int)cub3d->pos_y][(int)(cub3d->pos_x + cub3d->planeX * cub3d->move_speed)] == '0')
        cub3d->pos_x += cub3d->planeX *cub3d->move_speed;
    if(cub3d->map[(int)(cub3d->pos_y + cub3d->planeY * cub3d->move_speed)][(int)(cub3d->pos_x)] == '0')
        cub3d->pos_y += cub3d->planeY * cub3d->move_speed;
    raycast(cub3d);
}

void move_left(t_cub3d *cub3d)
{
    if(cub3d->map[(int)cub3d->pos_y][(int)(cub3d->pos_x - cub3d->planeX * cub3d->move_speed)] == '0')
        cub3d->pos_x -= cub3d->planeX *cub3d->move_speed;
    if(cub3d->map[(int)(cub3d->pos_y - cub3d->planeY * cub3d->move_speed)][(int)(cub3d->pos_x)] == '0')
        cub3d->pos_y -= cub3d->planeY * cub3d->move_speed;
    raycast(cub3d);
}


void rotate_camera(t_cub3d *cub3d, int direction)
{
    double old_direction_x;
    double old_plane_x;
    double rotation_speed;

    rotation_speed = cub3d->rotation_speed;
    rotation_speed *= direction;
    old_direction_x = cub3d->dirX;
    cub3d->dirX = cub3d->dirX * cos(rotation_speed)
        - cub3d->dirY * sin(rotation_speed);
    cub3d->dirY = old_direction_x * sin(rotation_speed)
        + cub3d->dirY * cos(rotation_speed);
    old_plane_x = cub3d->planeX;
    cub3d->planeX = cub3d->planeX * cos(rotation_speed)
        - cub3d->planeY * sin(rotation_speed);
    cub3d->planeY = old_plane_x * sin(rotation_speed)
        + cub3d->planeY * cos(rotation_speed);
    raycast(cub3d);
}