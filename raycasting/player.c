/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 08:53:57 by zbendahh          #+#    #+#             */
/*   Updated: 2024/06/04 10:22:41 by zbendahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	player(t_data *data)
{
	float	move_step;
	float	new_player_x;
	float	new_player_y;

	data->player.rotation_angle += \
		data->player.turn_direction * \
		data->player.turn_speed * (2 * (PI / 180));
	move_step = data->player.walk_direction * \
		data->player.walk_speed * (2 * (PI / 180));
	new_player_x = data->player.x + \
		cos(data->player.rotation_angle) * move_step;
	new_player_y = data->player.y + \
		sin(data->player.rotation_angle) * move_step;
	if (check_collisions(data, new_player_x, new_player_y) != 1)
	{
		data->player.x = new_player_x;
		data->player.y = new_player_y;
	}
}
