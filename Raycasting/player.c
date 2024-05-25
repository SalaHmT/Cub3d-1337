/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:42:22 by zbendahh          #+#    #+#             */
/*   Updated: 2024/05/25 02:34:30 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

int	check_map(t_data *data, float y_, float x_)
{
	int	y;
	int	x;

	y = (int)y_ / TILE_SIZE;
	x = (int)x_ / TILE_SIZE;
	if (data->map.map[y][x] == 49)
		return (1);
	else if (data->map.map[y][x] == 48)
		return (0);
	return (0);
}

void	player(t_data *data)
{
	float	move_step;
	float	new_x_player;
	float	new_y_player;

	data->player.player_rotation_angle += \
		data->player.turn_direction * data->player.player_rotation_speed;
	move_step = data->player.walk_direction * data->player.player_move_speed;
	new_x_player = (data->player.x_player + \
		cos(data->player.player_rotation_angle - \
		data->player.angle) * move_step);
	new_y_player = (data->player.y_player + \
		sin(data->player.player_rotation_angle \
		- data->player.angle) * move_step);
	if (check_map(data, new_y_player, new_x_player) != 1)
	{
		data->player.x_player = new_x_player;
		data->player.y_player = new_y_player;
	}
}
