/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Check_Map_Color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:05:01 by shamsate          #+#    #+#             */
/*   Updated: 2024/03/11 12:11:12 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

void	digit_color_check(char *str, t_map *cub3d, char type)
{
	char	**color;

	color = ft_split(str, ',');
	if (color[0] == NULL || color[1] == NULL || color[2] == NULL)
		p_error("Error: Wrong format :(\n");
	if (ft_isdigit(color[0]) == 0 || ft_isdigit(color[1]) == 0 \
		|| ft_isdigit(color[2]) == 0)
		p_error("Error: Wrong format :(\n");
	if (type == 'F')
	{
		if (cub3d->f != -1)
			p_error("Error: F color already defined :(\n");
		cub3d->f = (ft_atoi(color[0]) << 16) + (ft_atoi(color[1]) << 8) \
			+ ft_atoi(color[2]);
	}
	else if (type == 'C')
	{
		if (cub3d->c != -1)
			p_error("Error: C color already defined :(\n");
		cub3d->c = (ft_atoi(color[0]) << 16) + (ft_atoi(color[1]) << 8) \
			+ ft_atoi(color[2]);
	}
	free_string_array(color);
}

//This function check_color is responsible for verifying
// the validity of a color specification in a given line of a map file.

void	color_check(char *line, char type, t_map *cub3d)
{
	int		i;
	int		j;
	char	*tmp;
	char	**col;

	i = 0;
	j = 0;
	if (line[1] != ' ')
		col = ft_split(line, '\t');
	else
		col = ft_split(line, ' ');
	if (col[1] == NULL)
		p_error("Error: Wrong format :(\n");
	tmp = trim_whitespace(line);
	while (tmp[i] && tmp[i] != '\n')
	{
		if (tmp[i] == ',')
			j++;
		i++;
	}
	if (j != 2)
		p_error("Error:  commas is not 2 ',' in color :(\n");
	digit_color_check(tmp + 1, cub3d, type);
	free(tmp);
	free_string_array(col);
}
