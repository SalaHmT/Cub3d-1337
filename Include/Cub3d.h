/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:15:13 by shamsate          #+#    #+#             */
/*   Updated: 2024/03/05 11:52:06 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

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
}				t_map;

// *** Get_Next_Line ***
char	*get_next_line(int fd);

// *** libft functions ***
char	**ft_split(const char *str, char c);
int		ft_strlen(const char *s);
char	*duplicate_string(const char *src);
char	*ft_strchr(char *str, int character);
char	*ft_strjoin(char *first_string, char *second_string);
int		ft_atoi( char *str);
int		ft_isdigit(char *str);

// *** Parssing/Map_Dependencies.c ***
void	p_error(char *str);
char	*space_skip(char *ln);
char	*trim_whitespace(char *line);
int		count_string_array(char **str_array);
void	free_string_array(char **str_array);

// *** Parssing/Map_Init.c ***
void	init_struct(t_map *cub);

// *** Parssing/Check_Map.c ***
void	check_extension(char *str);
void	check_texture_color(t_map *cub3d, char *line);
void	init_texture(t_map *cub3d, char *line, char *texture);

#endif