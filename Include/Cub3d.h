/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:15:13 by shamsate          #+#    #+#             */
/*   Updated: 2024/03/23 17:49:56 by zbendahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>

// *** Get_Next_Line ***
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

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
    void	    *mlx_ptr;
    void	    *win_ptr;
    void	    *img_ptr;
    char        *pixel_ptr;
	char	    *data_addr;
	int		    bits_per_pixel;
	int		    line_length;
	int		    endian;
}   t_mlx;

typedef struct s_rectangle
{
    int		y;
    int		x;
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
    double  player_rotation_speed;
    int     walk_direction;
    int     turn_direction;
}   t_player;

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