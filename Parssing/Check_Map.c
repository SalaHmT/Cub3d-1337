/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Check_Map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:03:38 by shamsate          #+#    #+#             */
/*   Updated: 2024/05/24 20:24:08 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

void	line_check(char *line)
{
	int	i;

	i = 0;
	left_check(line);
	right_check(line);
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != '1' && line[i] != '0'
			&& line[i] != 'W' && line[i] != 'E' && line[i] != 'S'
			&& line[i] != 'N' && line[i] != ' ')
			p_error("Error : Wrong character in the map");
		i++;
	}
}

//first iterates to the end of the line, then moves backwards
//to find the last non-space character. Finally, it checks
//if the last non-space character is not '1' and prints an error message if so.

void	right_check(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	i--;
	while (line[i] == ' ')
		i--;
	if (line[i] != '1')
		p_error("Error: Map not surrounded by walls :(\n");
}

void	left_check(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] != '1' || line[i] == '\0' || line[i] == '\n')
		p_error("Error: Map not surrounded by walls :(\n");
}

void	surrounded_check(t_map *cub3d)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cub3d->map_y)
	{
		j = 0;
		while (j < cub3d->map_x && cub3d->map[i][j++] != '\0'
			&& cub3d->map[i][j] != '\n' && cub3d->map[i][j + 1] != '\0'
			&& cub3d->map[i][j + 1] != '\n')
		{
			if (cub3d->map[i][j] == ' ')
			{
				if (i != 0 && cub3d->map[i - 1][j] == '0')
					p_error("Error: Map not surrounded by walls :(\n");
				if (i != cub3d->map_y - 1 && cub3d->map[i + 1][j] == '0')
					p_error("Error: Map not surrounded by walls :(\n");
				if (j != 0 && cub3d->map[i][j - 1] == '0')
					p_error("Error: Map not surrounded by walls :(\n");
				if (cub3d->map[i][j + 1] == '0')
					p_error("Error: Map not surrounded by walls :(\n");
			}
		}
	}
}

//This checks if the floor or ceiling color is not
//set and if any texture is not set. It then increments the map height
// and updates the map width if the current line'slength (excluding newline
//character)is greater than the current map width. If any condition
//is met, it prints an error message accordingly.
void	map_check(char *line, t_map *cub3d)
{
	if (cub3d->c == -1 || cub3d->f == -1)
		p_error("Error: floor or ceiling color not set :(\n");
	if (cub3d->no == NULL || cub3d->so == NULL
		|| cub3d->we == NULL || cub3d->ea == NULL)
		p_error("Error: Texture not set :(\n");
	cub3d->map_y += 1;
	if (ft_strlen(line) - 1 > cub3d->map_x)
		cub3d->map_x = ft_strlen(line) - 1;
}
