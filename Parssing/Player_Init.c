/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:23:04 by shamsate          #+#    #+#             */
/*   Updated: 2024/05/24 03:23:40 by zbendahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parssing.h"

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
