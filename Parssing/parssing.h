/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2024/02/26 22:15:13 by shamsate          #+#    #+#             */
/*   Updated: 2024/06/04 15:02:37 by shamsate         ###   ########.fr       */
=======
/*   Created: 2024/05/27 20:29:27 by shamsate          #+#    #+#             */
/*   Updated: 2024/05/28 04:39:46 by shamsate         ###   ########.fr       */
>>>>>>> ba759715961b7d202c237d1dc1936533b8b29bc8
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSSING_H
# define PARSSING_H

# include "../dependencies/libft_function/libft.h" 
# include "../dependencies/get_next_line/get_next_line.h"

// # include <stdint.h>
// # include <unistd.h>
// # include <stdio.h>
# include <fcntl.h>
// # include <stdlib.h>
// # include "../MLX/MLX42.h"
// # include <math.h>
// # include <stdbool.h>
// # include <string.h>

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

int		count_string_array(char **str_array);
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
char	*duplicate_string(const char *src);
char	*ft_strjoin(char *first_string, char *second_string);
char	*remove_leading_and_trailing_spaces(char *input);
char	*trim_whitespace(char *line);
char	*space_skip(char *ln);
#endif