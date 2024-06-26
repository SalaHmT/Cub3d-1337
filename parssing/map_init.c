/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 00:31:33 by shamsate          #+#    #+#             */
/*   Updated: 2024/06/07 15:58:12 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parssing.h"

//This function init_line initializes a specific row of a 2D array representing
//a map in a game (presumably Cub3D) with characters
void	initialize_map_line(char *line, t_map *cub, int row)
{
	int	column;

	column = 0;
	cub->map[row] = malloc(sizeof(char) * (cub->map_x + 1));
	while (line[column] != '\0' && line[column] != '\n' && column < cub->map_x)
	{
		cub->map[row][column] = line[column];
		column++;
	}
	while (column < cub->map_x)
	{
		cub->map[row][column] = ' ';
		column++;
	}
	cub->map[row][column] = '\0';
}

//this function ensures that the first and last lines consist only of solid
//walls ('1') and empty spaces (' '), indicating the boundaries of the map.
void	the_first_last_check(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != '1' && line[i] != ' ')
			p_error("Error: map is not surrounded by walls :(\n");
		i++;
	}
}

void	all_fun_check(t_map *cub3d, int fd)
{
	close(fd);
	player_init(cub3d);
	the_first_last_check(cub3d->map[0]);
	the_first_last_check(cub3d->map[cub3d->map_y - 1]);
	surrounded_check((cub3d));
}

//The function init_map reads the map data from the specified file, validates
//each line, and populates the 2D array representing the map (cub3d->my_map).
void	process_line(char *line, t_map *cub3d, int *i)
{
	if (ft_strlen(line) == 1 && line[0] == '\n' && *i > 0)
	{
		free(line);
		p_error("Error: Empty line in the map :(\n");
	}
	if (space_skip(line)[0] == '1')
	{
		line_check(line);
		initialize_map_line(line, cub3d, (*i)++);
	}
	else if ((space_skip(line)[0] == '\0' || \
		space_skip(line)[0] == '\n') && *i > 0)
	{
		free(line);
		p_error("Error: Map not surrounded by walls :(\n");
	}
}

void	map_init(t_map *cub3d, char *file)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		p_error("Error opening file");
	cub3d->map = malloc(sizeof(char *) * (cub3d->map_y + 3));
	if (!cub3d->map)
		p_error("Error allocating memory for map");
	line = get_next_line(fd);
	while (line != NULL)
	{
		process_line(line, cub3d, &i);
		free(line);
		line = get_next_line(fd);
	}
	all_fun_check(cub3d, fd);
}
