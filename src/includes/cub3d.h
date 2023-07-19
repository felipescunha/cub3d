/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:23:06 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/19 17:17:17 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../../mlx_linux/mlx.h"
# include "../../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define mapWidth 24
# define mapHeight 24
# define SCREENWIDTH 2040
# define SCREENHEIGHT 1080
# define ROTATION_LEFT -1
# define ROTATION_RIGHT 1
# define SIDE_X 0
# define SIDE_Y 1


enum {
	CLICK_X = 17,
	KEY_ESC = 65307,
	KEY_UP = 119,
	KEY_LEFT = 97,
	KEY_DOWN = 115,
	KEY_RIGHT = 100,
	CAM_ARROW_RIGHT = 65363,
	CAM_ARROW_LEFT = 65361
};

typedef struct s_data {
    void    *img;
    char    *addr;
    int        bits_per_pixel;
    int        line_length;
    int        endian;
    int        sprite_width;
    int        sprite_height;
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
	void 	*mlx_ptr;
	void 	*win_ptr;
	
	char    **coordinate;
	char	**file;
	char	**map;
	char	**full_map;
	char	**texture;
	char	**verify_ceiling;
	char	**verify_floor;
	int 	total;
	int		index;
	int		count;
	int		read_lines;
	int		play_position_x;
	int		play_position_y;
	size_t	array_size;
	size_t	biggest_line;
	size_t	temp_line;
	size_t	temp_collunm;
	t_data 	img;
	t_color	ceiling;
	t_color	floor;
	t_texture textures;
	//raycast
	int		side;
	int 	draw_end;
	int		draw_start;
	int		texture_x;
	int		line_height;
	double	posX;  //x and y start position
	double	posY;  //x and y start position
  	double	dirX; //initial direction vector
  	double	dirY; //initial direction vector
  	double	planeX; //the 2d raycaster version of camera plane
  	double	planeY; //the 2d raycaster version of camera plane
  	double	time; //time of current frame
  	double	oldTime; //time of previous frame
	
	double	wall_x;
	double	rayDirX;
	double	rayDirY;
	double	move_speed;
	double	texture_step;
	double	rotation_speed;
	double	perp_wall_dist;
	double	texture_position;

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
void	check_color_floor(t_cub3d *cub3d, int i);
int		validations(t_cub3d *s_cub3d);
void	check_color_ceiling(t_cub3d *cub3d, int i);
void	check_coordinate(t_cub3d *cub3d, int i);
int		check_ceiling_floor(t_cub3d *cub3d, int i);
char	*my_realloc(char *str, size_t new_size);
void	copy_map(t_cub3d *cub3d);
int		get_range(t_cub3d *cub3d);
int		fill_rows(t_cub3d *cub3d);
void	validation_char(t_cub3d *cub3d);
void	print_map(t_cub3d *cub3d);
void	starting_values_in_struct(t_cub3d *cub3d);
void	raycast(t_cub3d *cub3d);
void	move_forward(t_cub3d *cub3d);
void	move_backward(t_cub3d *cub3d);
void	move_right(t_cub3d *cub3d);
void	move_left(t_cub3d *cub3d);
void	rotate_camera(t_cub3d *cub3d, int direction);
void	load_texture(t_cub3d *cub3d, t_data *texture, char *path);
void	texturing_calculations(t_cub3d *cub3d);
#endif