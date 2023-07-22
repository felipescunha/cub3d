/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:23:06 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/22 18:10:08 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../../mlx_linux/mlx.h"
# include "../../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define SCREENWIDTH 1024
# define SCREENHEIGHT 1024
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
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		sprite_width;
	int		sprite_height;
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
	int			total;
	int			i;
	int			count;
	int			read_lines;
	char		target_player;
	int			player_position_y;
	int			step_x;
	int			step_y;
	int			side;
	int			draw_end;
	int			draw_start;
	int			texture_x;
	int			line_height;
	void		*mlx_ptr;
	void		*win_ptr;
	char		*tmp_strtrim;
	char		**coordinate;
	char		**file;
	char		**map;
	char		**full_map;
	char		**texture;
	char		**verify_ceiling;
	char		**verify_floor;
	size_t		j;
	size_t		array_size;
	size_t		biggest_line;
	size_t		temp_line;
	size_t		temp_collunm;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		time;
	double		old_time;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		wall_x;
	double		ray_dir_x;
	double		ray_dir_y;
	double		move_speed;
	double		texture_step;
	double		rotation_speed;
	double		perp_wall_dist;
	double		texture_position;
	t_data		img;
	t_color		ceiling;
	t_color		floor;
	t_texture	textures;
}	t_cub3d;

size_t	ft_array_size(char **array);
char	**ft_split_comma(char const *s);
long	ft_atoi_digit(const char *str);
void	read_map(t_cub3d *cub3d, char *argv);
void	copy_file(t_cub3d *cub3d, char *argv);
void	validation_map_name(int argc, char *argv);
void	ft_free_array(char **array);
void	free_map(t_cub3d *cub3d);
void	print_full_map(t_cub3d *cub3d);
void	print_error(char *msg);
void	print_map(t_cub3d *cub3d);
void	check_color_floor(t_cub3d *cub3d, int i);
int		validations(t_cub3d *s_cub3d);
void	check_color_ceiling(t_cub3d *cub3d, int i);
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
void	rotate_camera(t_cub3d *cub3d, double rotation_speed, int direction);
void	load_texture(t_cub3d *cub3d, t_data *texture, char *path);
void	texturing_calculations(t_cub3d *cub3d);
void	position_player_in_map(t_cub3d *cub3d);
void	free_full_map(t_cub3d *cub3d);
int		validation_wall(t_cub3d *cub3d);
void	check_comma(char *str);
char	*ft_split_texture(char **texture);
void	check_extension(t_cub3d *cub3d);
int		verify_extension(t_cub3d *cub3d, int i);
void	direction_no(t_cub3d *cub3d, char **tmp_split, int i);
void	direction_so(t_cub3d *cub3d, char **tmp_split, int i);
void	direction_we(t_cub3d *cub3d, char **tmp_split, int i);
void	direction_ea(t_cub3d *cub3d, char **tmp_split, int i);

#endif