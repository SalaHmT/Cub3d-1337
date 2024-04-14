/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:15:13 by shamsate          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/04/14 12:11:48 by shamsate         ###   ########.fr       */
=======
/*   Updated: 2024/03/23 17:49:56 by zbendahh         ###   ########.fr       */
>>>>>>> b10567c01136b06cd4627b58ee4eea32a3c15d00
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
<<<<<<< HEAD
# include <stdbool.h>
=======
>>>>>>> b10567c01136b06cd4627b58ee4eea32a3c15d00

// *** Get_Next_Line ***
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#define RADIUS_LINE 8
#define RADIUS_PLAYER 4
#define TILE_SIZE 32
#define FOV_ANGLE  60 * (M_PI / 180)
#define NUM_RAYS 1248 / 1
#define PI 3.14159265
#define TWO_PI 6.28318530

#define MAP_NUM_ROWS 13
#define MAP_NUM_COLS 20

#define MINIMAP_SCALE_FACTOR 0.6


#define FPS 30
#define FRAME_TIME_LENGTH (1000 / FPS)

typedef struct s_map
{
	char	**map; // 2D array to store the map
	char	*no; // North texture
	char	*so; // South texture
	char	*we; // West texture
	char	*ea; // East texture
	int		c; // Ceiling color
	int		f; // Floor color
	int		map_x; // Map width
	int		map_y; // Map height
	int		player_y; // Player position
	int		player_x; // Player position
	char	pos_player; // Player position
}	t_map;


typedef struct s_mlx
{
<<<<<<< HEAD
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img_ptr;
	char    *addr_ptr;
    int	    bits_per_pixel;
	int	    line_length;
    int     size_x;
    int     size_y;
	int	    endian;
=======
    void	    *mlx_ptr;
    void	    *win_ptr;
    void	    *img_ptr;
    char        *pixel_ptr;
	char	    *data_addr;
	int		    bits_per_pixel;
	int		    line_length;
	int		    endian;
>>>>>>> b10567c01136b06cd4627b58ee4eea32a3c15d00
}   t_mlx;

typedef struct s_rectangle
{
    int		y;
    int		x;
<<<<<<< HEAD
    int		color;
}	t_rectangle;

typedef struct s_player
{
    float   x_player;
    float   y_player;
    float   player_rotation_angle;
    float   player_move_speed;
=======
    int		width;
    int		height;
    int		c_color;
}	t_rectangle;

typedef struct s_circle
{
    int y;
    int x;
    int radius;
    int c_color;
}	t_circle;

typedef struct s_player {
    double  player_x;
    double  player_y;
    double  player_rotation_angle;
    double  player_move_speed;
>>>>>>> b10567c01136b06cd4627b58ee4eea32a3c15d00
    double  player_rotation_speed;
    int     walk_direction;
    int     turn_direction;
}   t_player;

<<<<<<< HEAD
typedef struct s_ray {
    float rayAngle;
    float wallHitX;
    float wallHitY;
    float distance;
    int wasHitVertical;
    int isRayFacingUp;
    int isRayFacingDown;
    int isRayFacingLeft;
    int isRayFacingRight;
    int wallHitContent;
} t_ray;

typedef struct s_data
{
    t_player    player;
    t_mlx       mlx;
    t_map       map;
    t_ray       ray[NUM_RAYS];
}   t_data;

void    backround(t_data *data);
void    mlx_line_dda(t_data *data, int y_first, int x_first, int y_last, int x_last, int color);
void    mlx_rectangle(t_data* data, int x_old, int y_old, int color);
void    mlx_circle(t_data *data, int y, int x, int color);
void    map_building(t_data *data);
void    player_building(t_data *data);
void    mlx_setup(t_data *data);
void	img_pix_put(t_mlx *mlx, int x, int y, int color);
=======
typedef struct s_line
{
    int y_first;
    int x_first;
    int x_last;
    int y_last;
    int c_color;
}   t_line;

typedef struct s_data {
    int         size;
    int         width;
    int         heigh;
    t_mlx       mlx;
    t_line      line;
    t_circle    circle;
    t_rectangle rectangle;
    t_player    player;
}   t_data;

void    circle(t_data *data);
void    line_dda(t_data *data);
void    rectangle(t_data *data);
void    map_building(t_data *data);
void    mlx_setup(t_data *data);
void    put_pixel(t_mlx *mlx, int x, int y, int color);
>>>>>>> b10567c01136b06cd4627b58ee4eea32a3c15d00
// *** Get_Next_Line ***
char	*get_next_line(int fd);
char	*remove_extracted_line(char *str);
char	*ft_get_ln(int fd, char *str);
char	*read_ln(char *str);
// *** libft functions ***
char	**ft_split(const char *s, char c);
int		ft_strlen(char *s);
char	*duplicate_string(const char *src);
char	*ft_strchr(char *str, int character);
char	*ft_strjoin(char *first_string, char *second_string);
int		ft_atoi( char *str);
int		ft_isdigit(char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
// *** Parssing/Map_Dependencies.c ***
void	p_error(char *str);
char	*space_skip(char *ln);
char	*trim_whitespace(char *line);
int		count_string_array(char **str_array);
void	free_string_array(char **str_array);
// *** Parssing/Read_Map_File.c ***
void	read_file_map(char *file, t_map *cub3d);
// *** Parssing/Map_Init.c ***
void	struct_init(t_map *cub);
void	initialize_map_line(char *line, t_map *cub, int row);
void	the_first_last_check(char *line);
void	all_fun_check(t_map *cub3d, int fd);
void	map_init(t_map *cub3d, char *file);
// *** Parssing/Player_init.c ***
void	player_init(t_map *cub3d);
// *** Parssing/Check_Map_texture.c ***
void	extension_check(char *str);
void	texture_color_check(t_map *cub3d, char *line);
void	texture_init(t_map *cub3d, char *line, char *texture);
void	texture_check(char *line, t_map *cub3d);
char	*remove_leading_and_trailing_spaces(char *input);
// *** Parssing/Check_Map_Color.c ***
void	digit_color_check(char *str, t_map *cub3d, char type);
void	color_check(char *line, char type, t_map *cub3d);
// *** Parssing/Check_Map.c ***
void	right_check(char *line);
void	left_check(char *line);
void	surrounded_check(t_map *cub3d);
void	line_check(char *line);
void	map_check(char *line, t_map *cub3d);

#endif