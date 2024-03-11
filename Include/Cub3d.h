/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:15:13 by shamsate          #+#    #+#             */
/*   Updated: 2024/03/11 12:37:19 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

// *** Get_Next_Line ***
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_map
{
	char	**map;// 2D array to store the map
	char	*no;// North texture
	char	*so;// South texture
	char	*we;// West texture
	char	*ea;// East texture
	int		c;// Ceiling color
	int		f;// Floor color
	int		map_x;// Map width
	int		map_y;// Map height
	char	pos_player;// Player position
}				t_map;

// *** Get_Next_Line ***
char	*get_next_line(int fd);
char	*ft_re(char *str);
char	*ft_get_ln(int fd, char *str);
char	*read_ln(char *str);


// *** libft functions ***
char	**ft_split(const char *str, char c);
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
// *** Parssing/Read_Map_File.c ***
void	read_file_map(char *file, t_map *cub3d);

#endif