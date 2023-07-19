/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:03:51 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/19 16:58:11 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void check_extension(t_cub3d *cub3d)
{
    int i = 0;
    int		fd;
	char	*extension;
    while(i < 4)
    {
        fd = open(cub3d->texture[i], O_RDONLY);
        if (fd < 0)
            print_error("In texture file!\n");
        extension = ft_strrchr(cub3d->file[i], '.');
        if (!extension)
            print_error("The map not found!\n");
        if (ft_strncmp(extension, ".xpm", 5))
            print_error("The file needed .xpm extension\n");
        i++;
    }
}

char *ft_split_texture(char **texture)
{
    if(ft_array_size(texture) != 2)
        print_error("In texture array\n");
    return (texture[1]);
}

int  validations(t_cub3d *cub3d)
{    
    int i = 0;
    int j = 0;
    int size = get_range(cub3d);
    char *tmp_strtrim;
    char **tmp_split;

    cub3d->index = 0;
    while (i < size)
    {
        check_color_ceiling(cub3d, i);
        check_color_floor(cub3d, i);
        tmp_strtrim = ft_strtrim(cub3d->file[i], "");
        tmp_split = ft_split(cub3d->file[i], 32);
        if(ft_strncmp(tmp_strtrim, "NO", 2) == 0)
        {
            cub3d->texture[0] = ft_strdup(ft_split_texture(tmp_split));
            printf("%s", cub3d->texture[0]);
            cub3d->total += 1;
        }
        else if(ft_strncmp(tmp_strtrim, "SO", 2) == 0)
        {
            cub3d->texture[1] = ft_strdup(ft_split_texture(tmp_split));
            cub3d->total += 2;
        }
        else if(ft_strncmp(tmp_strtrim, "WE", 2) == 0)
        {
            cub3d->texture[2] = ft_strdup(ft_split_texture(tmp_split));
            cub3d->total += 4;
        }
        else if(ft_strncmp(tmp_strtrim, "EA", 2) == 0)
        {
            cub3d->texture[3] = ft_strdup(ft_split_texture(tmp_split));
            cub3d->total += 8;
        }
        free(tmp_strtrim);
        while (tmp_split[j])
            free(tmp_split[j++]);
        free(tmp_split);
        j = 0;
        i++;
    }
    check_extension(cub3d);
    if (cub3d->total != 63)
        print_error("Map is not correct!\n"); 
    return 0;
}