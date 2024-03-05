/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Check_Map_Color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:05:01 by shamsate          #+#    #+#             */
/*   Updated: 2024/03/05 11:54:17 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_digit_color(char *str, t_map *cub3d, char type)
{
	char	**color;
	int		i;

	i = 0;
	color = ft_split(str, ',');
	if (color[0] == NULL || color[1] == NULL || color[2] == NULL)
		p_error("Error: Wrong format");
	if (ft_isdigit(color[0]) == 0 || ft_isdigit(color[1]) == 0 \
		|| ft_isdigit(color[2]) == 0)
		p_error("Error: Wrong format");
	if (type == 'F')
	{
		if (cub3d->f != -1)
			p_error("Error: F color already defined");
		cub3d->f = (ft_atoi(color[0]) << 16) + (ft_atoi(color[1]) << 8) \
			+ ft_atoi(color[2]);
	}
	else if (type == 'C')
	{
		if (cub3d->c != -1)
			print_error("Error: C color already defined");
		cub3d->c = (ft_atoi(color[0]) << 16) + (ft_atoi(color[1]) << 8) \
			+ ft_atoi(color[2]);
	}
	free_string_array(color);
}
