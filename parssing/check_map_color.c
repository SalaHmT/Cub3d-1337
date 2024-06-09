/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:05:01 by shamsate          #+#    #+#             */
/*   Updated: 2024/06/09 18:16:42 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parssing.h"

int32_t	get_rgba2(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

//This function check_color is responsible for verifying
// the validity of a color specification in a given line of a map file.

void	parse_and_validate_color_line(char *line, char ***col, char **tmp)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (line[1] != ' ')
		*col = ft_split(line, '\t');
	else
		*col = ft_split(line, ' ');
	if ((*col)[1] == NULL)
		p_error("Error: Wrong format :(\n");
	*tmp = trim_whitespace(line);
	while ((*tmp)[i] && (*tmp)[i] != '\n')
	{
		if ((*tmp)[i] == ',')
			j++;
		i++;
	}
	if (j != 2)
		p_error("Error: commas is not 2 ',' in color :(\n");
}

void	process_rgb_and_set_color(char *tmp, char type, t_map *cub3d)
{
	char	**col;
	uint8_t	rgb[3];
	int32_t	color;
	int		i;

	i = 0;
	col = ft_split(tmp + 1, ',');
	if (!col[0] || !col[1] || !col[2])
		p_error("Error: Invalid color format :(\n");
	while (i < 3)
	{
		rgb[i] = (uint8_t)atoi(col[i]);
		if (rgb[i] > 255)
			p_error("Error: Color value out of range :(\n");
		i++;
	}
	color = get_rgba2(rgb[0], rgb[1], rgb[2], 255);
	if (type == 'C')
		cub3d->ceiling_color = color;
	else if (type == 'F')
		cub3d->floor_color = color;
	else
		p_error("Error: Unknown color type :(\n");
	free_string_array(col);
}

void	color_check(char *line, char type, t_map *cub3d)
{
	char	*tmp;
	char	**col;

	parse_and_validate_color_line(line, &col, &tmp);
	process_rgb_and_set_color(tmp, type, cub3d);
	digit_color_check(tmp + 1, cub3d, type);
	free(tmp);
	free_string_array(col);
}
