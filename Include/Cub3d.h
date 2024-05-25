/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:15:13 by shamsate          #+#    #+#             */
/*   Updated: 2024/05/25 17:44:21 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdint.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stdbool.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# define PI 3.14159265
# define PI_2 6.28318530
# define TILE_SIZE 32
# define FOV_ANGLE 1.0471975512
# define FLT_MAX 3.40282347e+38F

typedef struct s_map
{
	char	**map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		c;
	int		f;
	int		map_x;
	int		map_y;
	int		player_y;
	int		player_x;
	char	pos_player;
}	t_map;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*img_ptr;
	int		win_x;
	int		win_y;
	int		img_x;
	int		img_y;
}	t_mlx;

typedef struct s_player
{
	float	x_player;
	float	y_player;
	float	player_move_speed;
	float	player_rotation_angle;
	double	player_rotation_speed;
	int		walk_direction;
	int		turn_direction;
	int		prev_x;
	float	angle;
}	t_player;

typedef struct s_ray
{
	float	ray_angle;
	float	wall_hit_x;
	float	wall_hit_y;
	float	distance;
	int		was_hit_vertical;
	int		wall_hit_content;
	int		is_ray_facing_up;
	int		is_ray_facing_down;
	int		is_ray_facing_left;
	int		is_ray_facing_right;
}	t_ray;

typedef struct s_cast
{
	float	x_step;
	float	y_step;
	float	x_to_check;
	float	y_to_check;
	float	x_intercept;
	float	y_intercept;
	float	horz_wall_hit_x;
	float	horz_wall_hit_y;
	float	vert_wall_hit_x;
	float	vert_wall_hit_y;
	float	next_horz_touch_y;
	float	next_horz_touch_x;
	float	next_vert_touch_x;
	float	next_vert_touch_y;
	float	horz_hit_distance;
	float	vert_hit_distance;
	int		is_ray_facing_down;
	int		is_ray_facing_up;
	int		is_ray_facing_right;
	int		is_ray_facing_left;
	int		found_horz_wall_hit;
	int		found_vert_wall_hit;
	int		horz_wall_content;
	int		vert_wall_content;
}	t_cast;

typedef struct s_data
{
	t_player		player;
	t_mlx			mlx;
	t_map			map;
	t_cast			cast;
	mlx_texture_t	*texture[4];
	mlx_image_t		*wall_images[4];
	t_ray			ray[1248];
}	t_data;

void	horizontal(t_data *data, float ray_angle);
void	vertical(t_data *data, float ray_angle);

int		ft_atoi( char *str);
int		ft_isdigit(char *str);
void	update(t_data *data);
void	mouse(t_data *data);
int		count_string_array(char **str_array);
int		ft_strlen(char *s);
void	init_ray(t_data *data, float ray_angle, int index);
void	cast(t_data *data);
void	player(t_data *data);
void	clear(t_data *data);
void	setup(t_data *data);
void	texture(t_data *data);
void	p_error(char *str);
void	free_string_array(char **str_array);
void	read_file_map(char *file, t_map *cub3d);
void	struct_init(t_map *cub);
void	initialize_map_line(char *line, t_map *cub, int row);
void	the_first_last_check(char *line);
void	all_fun_check(t_map *cub3d, int fd);
void	map_init(t_map *cub3d, char *file);
void	player_init(t_map *cub3d);
void	extension_check(char *str);
void	texture_color_check(t_map *cub3d, char *line);
void	texture_init(t_map *cub3d, char *line, char *texture);
void	texture_check(char *line, t_map *cub3d);
void	digit_color_check(char *str, t_map *cub3d, char type);
void	color_check(char *line, char type, t_map *cub3d);
void	right_check(char *line);
void	left_check(char *line);
void	surrounded_check(t_map *cub3d);
void	line_check(char *line);
void	map_check(char *line, t_map *cub3d);
char	*get_next_line(int fd);
char	*remove_extracted_line(char *str);
char	*ft_get_ln(int fd, char *str);
char	*read_ln(char *str);
char	**ft_split(const char *s, char c);
char	*duplicate_string(const char *src);
char	*ft_strchr(char *str, int character);
char	*ft_strjoin(char *first_string, char *second_string);
char	*remove_leading_and_trailing_spaces(char *input);
char	*trim_whitespace(char *line);
char	*space_skip(char *ln);
float	normal_angle(float ray_angle);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

#endif