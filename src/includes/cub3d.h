/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:23:06 by fecunha           #+#    #+#             */
/*   Updated: 2023/06/29 21:58:23 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../../mlx_linux/mlx.h"
# include "../../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_color {
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_cub3d {
	char	**file;
	char	**map;
	int		lines;
	int		read_lines;
	t_color	ceiling;
	t_color	floor;

}	t_cub3d;

void	print_error(char *msg);
void	copy_file(t_cub3d *cub3d, char *argv);
void	read_map(t_cub3d *cub3d, char *argv);
void	print_map(t_cub3d *cub3d);
void	validation_map_name(int argc, char *argv);
void 	free_map(t_cub3d *cub3d);
char	**ft_split_comma(char const *s);
void	check_color_floor(t_cub3d *cub3d);
void	check_color_ceiling(t_cub3d *cub3d);
#endif