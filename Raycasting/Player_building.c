/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player_building.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:42:22 by zbendahh          #+#    #+#             */
/*   Updated: 2024/04/14 12:35:50 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

void	player_building(t_data *data)
{
	float	movestep;
	float	newplayerx;
	float	newplayery;

	data->player.player_rotation_angle += data->player.turn_direction * \
		data->player.player_rotation_speed;
	movestep = data->player.walk_direction * data->player.player_move_speed;
	newplayerx = (data->player.x_player + \
		cos(data->player.player_rotation_angle) * movestep);
	newplayery = (data->player.y_player + \
		sin(data->player.player_rotation_angle) * movestep);
	if (data->map.map[(int)newplayery / TILE_SIZE] \
		[(int)newplayerx / TILE_SIZE] != '1')
	{
		data->player.x_player = newplayerx;
		data->player.y_player = newplayery;
	}
	// int endX = data->player.x_player + cos(data->player.player_rotation_angle) * 30;
	// int endY = data->player.y_player + sin(data->player.player_rotation_angle) * 30;
	// mlx_circle(data, data->player.x_player, data->player.y_player, 0xFFFFFF);
	// mlx_line_dda(data, data->player.x_player, data->player.y_player, endX, endY, 0xFFFFFF);
}
