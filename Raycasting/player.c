/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:42:22 by zbendahh          #+#    #+#             */
/*   Updated: 2024/04/17 10:37:17 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

void	move_player(t_data *data)
{
	float	move_step;
	float	new_x_player;
	float	new_y_player;

	data->player.player_rotation_angle = \
		normal_angle(data->player.player_rotation_angle);
	data->player.player_rotation_angle += data->player.turn_direction * \
		data->player.player_rotation_speed;
	move_step = data->player.walk_direction * \
		data->player.player_move_speed;
	new_x_player = (data->player.x_player + \
		cos(data->player.player_rotation_angle) * move_step);
	new_y_player = (data->player.y_player + \
		sin(data->player.player_rotation_angle) * move_step);
	if (data->map.map[(int)new_y_player / TILE_SIZE] \
		[(int)new_x_player / TILE_SIZE] != 49)
	{
		data->player.x_player = new_x_player;
		data->player.y_player = new_y_player;
	}
}
