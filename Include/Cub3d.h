/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:15:13 by shamsate          #+#    #+#             */
/*   Updated: 2024/04/17 11:09:24 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdint.h>
# include <unistd.h>
# include <float.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <stdbool.h>

#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
#endif

//-------------------[ data cast ]-------------------------------
#define     PI                      3.14159265
#define     TWO_PI                  6.28318530
#define     TILE_SIZE               32
#define     FOV_ANGLE               60 * (PI / 180)
#define     NUM_RAYS                1248
//------------------[ events ]-----------------------------------
#define     ON_KEYDOWN              2
#define     ON_KEYUP                3
#define     ON_MOUSEMOVE            6
#define     ON_DESTROY              17
//-------------------[ keycodes ]--------------------------------
#define     ROTATION_FORWARD        126
#define     ROTATION_BACK           125
#define     ROTATION_RIGHT          124
#define     ROTATION_LEFT           123
#define     ROTATION_FORWARD_E      14
#define     ROTATION_BACK_D         2
#define     ROTATION_RIGHT_F        3
#define     ROTATION_LEFT_S         1
#define     EXIT                    53
//---------------------------------------------------------------
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
    void	*win_ptr;
    void	*img_ptr;
	char	*addr_ptr;
    int		bits_per_pixel;
	int		line_length;
	int		endian;
    int		win_size_x;
    int		win_size_y;
    int		img_x;
    int		img_y;
}	t_mlx;

typedef struct s_player
{
    float	x_player;
    float	y_player;
    float	player_rotation_angle;
    float	player_move_speed;
    double	player_rotation_speed;
    int	    walk_direction;
    int	    turn_direction;
    int     prev_x;
}	t_player;

typedef struct s_ray {
    float	ray_angle;
    float	wall_hit_x;
    float	wall_hit_y;
    float	distance;
    int		was_hit_vertical;
    int		is_ray_facing_up;
    int		is_ray_facing_down;
    int		is_ray_facing_left;
    int		is_ray_facing_right;
    int		wall_hit_content;
} t_ray;

typedef struct s_cast_3d {
	int		wall_strip_height;
	int		wall_top_pixel;
	int		wall_bottom_pixel;
	float	perp_distance;
	float	distance_proj_plane;
	float	projected_wall_height;
}	t_cast_3d;


typedef struct s_cast_rays
{
    int     isRayFacingDown;
	int     isRayFacingUp;
	int     isRayFacingRight;
	int     isRayFacingLeft;
	float   x_intercept;
	float   y_intercept;
	float   x_step;
	float   y_step;
    int     foundHorzWallHit;
    float   horzWallHitX;
    float   horzWallHitY;
    int     horzWallContent;
    float   nextHorzTouchX;
    float   nextHorzTouchY;
    int     foundVertWallHit;
    float   vertWallHitX;
    float   vertWallHitY;
    int     vertWallContent;
    float   nextVertTouchX;
    float   nextVertTouchY;
    float   xToCheck;
    float   yToCheck;
    float   horzHitDistance;
    float   vertHitDistance;
}   t_cast_rays;

typedef struct s_data
{
    t_player	player;
    t_mlx		mlx;
    t_map		map;
    t_ray		ray[NUM_RAYS];
    t_cast_3d   cast_3d;
    t_cast_rays cast_rays;
}	t_data;

float	normal_angle(float ray_angle);
void    init_var_rays(t_data *data, float ray_angle, int index);
void    horizontal_while(t_data *data);
void    vertical_while(t_data *data);

void    horizontal(t_data *data, float ray_angle);
void    vertical(t_data *data, float ray_angle);
void    cast_ray(t_data *data, float ray_angle, int index);
void    cast_all_rays(t_data *data);

int	    update(t_data *data);
int		pressed(int keycode, t_data *data);
int		released(int keycode, t_data *data);
int     mousemove(int x, int y, t_data *data);
int     destroy(void);
void	move_player(t_data *data);
float	normal_angle(float ray_angle);
void    cast_ray(t_data *data, float rayAngle, int stripId);
void    cast_all_rays(t_data *data);
void    clear_img(t_data *data);
void	mlx_setup(t_data *data);
void	img_pixel_put(t_mlx *mlx, int x, int y, int color);
void	cast_3d(t_data* data);
void    floor_3d(t_data *data, int i);
void    walls_3d(t_data *data, int i);
void    render_walls(t_data *data, int i);
char	*get_next_line(int fd);
char	*remove_extracted_line(char *str);
char	*ft_get_ln(int fd, char *str);
char	*read_ln(char *str);
char	**ft_split(const char *s, char c);
int		ft_strlen(char *s);
char	*duplicate_string(const char *src);
char	*ft_strchr(char *str, int character);
char	*ft_strjoin(char *first_string, char *second_string);
int		ft_atoi( char *str);
int		ft_isdigit(char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
void	p_error(char *str);
char	*space_skip(char *ln);
char	*trim_whitespace(char *line);
int		count_string_array(char **str_array);
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
char	*remove_leading_and_trailing_spaces(char *input);
void	digit_color_check(char *str, t_map *cub3d, char type);
void	color_check(char *line, char type, t_map *cub3d);
void	right_check(char *line);
void	left_check(char *line);
void	surrounded_check(t_map *cub3d);
void	line_check(char *line);
void	map_check(char *line, t_map *cub3d);
#endif
