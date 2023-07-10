/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:23:06 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/10 17:44:01 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../../mlx_linux/mlx.h"
# include "../../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_data {
	void	*img;
	int		length;
	int		width;
	int		height;
}	t_data;

typedef struct s_color {
	int		red;
	int		green;
	int		blue;
}	t_color;

typedef struct s_texture {
	t_data	north;
	t_data	south;
	t_data	east;
	t_data	west;
}	t_texture;

typedef struct s_cub3d {
	char    **coordinate;
	char	**file;
	char	**map;
	char	**verify_ceiling;
	char	**verify_floor;
	int		index;
	int		read_lines;
	t_data 	img;
	t_color	ceiling;
	t_color	floor;
}	t_cub3d;

size_t	ft_array_size(char **array);
char	**ft_split_comma(char const *s);
long	ft_atoi_digit(const char *str);
void	read_map(t_cub3d *cub3d, char *argv);
void	copy_file(t_cub3d *cub3d, char *argv);
void	validation_map_name(int argc, char *argv);
void	ft_free_array(char **array);
void 	free_map(t_cub3d *cub3d);
void	print_error(char *msg);
void	print_map(t_cub3d *cub3d);

void	check_color_ceiling(t_cub3d *cub3d);
void	check_color_floor(t_cub3d *cub3d);
void	check_coordinate(t_cub3d *cub3d);
void	check_ceiling_floor(t_cub3d *cub3d);
int		validation_char(t_cub3d *cub3d);

#endif