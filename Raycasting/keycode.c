/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 05:44:35 by zbendahh          #+#    #+#             */
/*   Updated: 2024/04/17 10:36:55 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

int	pressed(int keycode, t_data *data)
{
	if (keycode == ROTATION_FORWARD || \
		keycode == ROTATION_FORWARD_E)
		data->player.walk_direction = +1;
	else if (keycode == ROTATION_BACK || \
		keycode == ROTATION_BACK_D)
		data->player.walk_direction = -1;
	else if (keycode == ROTATION_RIGHT || \
		keycode == ROTATION_RIGHT_F)
		data->player.turn_direction = +1;
	else if (keycode == ROTATION_LEFT || \
		keycode == ROTATION_LEFT_S)
		data->player.turn_direction = -1;
	else if (keycode == EXIT)
		exit(1);
	return (0);
}

int	released(int keycode, t_data *data)
{
	if (keycode == ROTATION_FORWARD || \
		keycode == ROTATION_BACK || \
		keycode == ROTATION_FORWARD_E || \
		keycode == ROTATION_BACK_D)
		data->player.walk_direction = 0;
	else if (keycode == ROTATION_RIGHT || \
		keycode == ROTATION_LEFT || \
		keycode == ROTATION_RIGHT_F || \
		keycode == ROTATION_LEFT_S)
		data->player.turn_direction = 0;
	return (0);
}

int	mousemove(int x, int y, t_data *data)
{
	(void)y;
	data->player.player_rotation_angle -= \
		((data->player.prev_x - x) / (float)data->mlx.win_size_x) * PI;
	data->player.prev_x = x;
	return (0);
}

int	destroy(void)
{
	exit(1);
}

int	update(t_data *data)
{
	clear_img(data);
	cast_all_rays(data);
	move_player(data);
	cast_3d(data);
	mlx_put_image_to_window(data->mlx.mlx_ptr, \
		data->mlx.win_ptr, \
		data->mlx.img_ptr, \
		data->mlx.img_x, \
		data->mlx.img_y);
	return (0);
}
