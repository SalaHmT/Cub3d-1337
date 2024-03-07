/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map_Init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 00:31:33 by shamsate          #+#    #+#             */
/*   Updated: 2024/03/07 10:54:27 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

//This function initializes the t_map structure with default values.
void	struct_init(t_map *cub)
{
	cub->map = NULL;
	cub->map_y = 0;
	cub->map_x = 0;
	cub->c = -1;
	cub->f = -1;
	cub->no = NULL;
	cub->so = NULL;
	cub->we = NULL;
	cub->ea = NULL;
	cub->pos_player = '0';
}

//This function init_line initializes a specific row of a 2D array representing
//a map in a game (presumably Cub3D) with characters
void	initialize_map_line(char *line, t_map *cub3d, int row)
{
	int	column;

	column = 0;
	cub3d->map[row] = malloc(sizeof(char) * (cub3d->map_x + 1));
	while (line[column] != '\0' && line[column] != '\n')
	{
		cub3d->map[row][column] = line[column];
		column++;
	}
	while (column < cub3d->map_x)
	{
		cub3d->map[row][column] = ' ';
		column++;
	}
	cub3d->map[row][column] = '\0';
}

//this function ensures that the first and last lines consist only of solid
//walls ('1') and empty spaces (' '), indicating the boundaries of the map.
void	check_the_first_last_c(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != '1' && line[i] != ' ')
			p_error("Error: map is not surrounded by walls :(");
		i++;
	}
}

void	all_fun_check(t_map *cub3d, int fd)
{
	close(fd);
	player_init(cub3d);
	check_the_first_last_c(cub3d->map[0]);
	check_the_first_last_c(cub3d->map[cub3d->map_y - 1]);
	surrounded_check(cub3d);
}

//The function init_map reads the map data from the specified file, validates
//each line, and populates the 2D array representing the map (cub3d->my_map).
void	map_init(t_map *cub3d, char *file)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	cub3d->map = malloc(sizeof(char *) * (cub3d->map_y + 3));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strlen(line) == 1 && line[0] == '\n' && i > 0)
			p_error("Error: Empty line in the map :(");
		if (space_skip(line)[0] == '1')
		{
			line_check(line);
			initialize_map_line(line, cub3d, i++);
		}
		else if ((space_skip(line)[0] == '\0' || \
			space_skip(line)[0] == '\n') && i > 0)
			p_error("Error: Map not surrounded by walls :(");
		free(line);
	}
	all_fun_check(cub3d, fd);
}
