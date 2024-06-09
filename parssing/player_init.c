/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:23:04 by shamsate          #+#    #+#             */
/*   Updated: 2024/06/07 15:58:20 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parssing.h"

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

//searching for the player symbol ('N', 'S', 'E', or 'W'). It sets the player's
//position and orientation if found and checks if more than one player
//is present or if no player is found, printing error messages accordingly.
void	player_init(t_map *cub3d)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub3d->map_y)
	{
		j = 0;
		while (j < cub3d->map_x && cub3d->map[i][j] != '\0' \
			&& cub3d->map[i][j] != '\n')
		{
			if (cub3d->map[i][j] == 'N' || cub3d->map[i][j] == 'S'
				|| cub3d->map[i][j] == 'E' || cub3d->map[i][j] == 'W')
			{
				if (cub3d->pos_player != '0')
					p_error("Error: More than one player in the map :(\n");
				cub3d->player_x = j;
				cub3d->player_y = i;
				cub3d->pos_player = cub3d->map[i][j];
			}
			j++;
		}
		i++;
	}
	if (cub3d->pos_player == '0')
		p_error("Error: Player not found in the map :(\n");
}
