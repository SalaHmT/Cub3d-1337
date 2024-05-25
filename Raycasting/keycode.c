/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 05:44:35 by zbendahh          #+#    #+#             */
/*   Updated: 2024/05/24 22:44:05 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

void	hook(t_data *data)
{
	if (mlx_is_key_down(data->mlx.mlx_ptr, MLX_KEY_RIGHT) || \
		mlx_is_key_down(data->mlx.mlx_ptr, MLX_KEY_LEFT))
		data->player.angle = (PI / 2);
	else
		data->player.angle = 0.0;
	if (mlx_is_key_down(data->mlx.mlx_ptr, MLX_KEY_LEFT))
		data->player.walk_direction = 1;
	if (mlx_is_key_down(data->mlx.mlx_ptr, MLX_KEY_RIGHT))
		data->player.walk_direction = -1;
	if (mlx_is_key_down(data->mlx.mlx_ptr, MLX_KEY_W) || \
		mlx_is_key_down(data->mlx.mlx_ptr, MLX_KEY_UP))
		data->player.walk_direction = 1;
	if (mlx_is_key_down(data->mlx.mlx_ptr, MLX_KEY_S) || \
		mlx_is_key_down(data->mlx.mlx_ptr, MLX_KEY_DOWN))
		data->player.walk_direction = -1;
	if (mlx_is_key_down(data->mlx.mlx_ptr, MLX_KEY_D))
		data->player.turn_direction = 1;
	if (mlx_is_key_down(data->mlx.mlx_ptr, MLX_KEY_A))
		data->player.turn_direction = -1;
	if (mlx_is_key_down(data->mlx.mlx_ptr, MLX_KEY_ESCAPE))
		exit(1);
}

void	mouse(t_data *data)
{
	int	y;
	int	x;

	mlx_get_mouse_pos(data->mlx.mlx_ptr, &x, &y);
	data->player.player_rotation_angle += \
		((x - data->player.prev_x) / (float)data->mlx.win_x) * PI;
	data->player.prev_x = x;
}

void	reset(t_data *data)
{
	data->player.walk_direction = 0;
	data->player.turn_direction = 0;
}

void	update(t_data *data)
{
	clear(data);
	mouse(data);
	hook(data);
	player(data);
	reset(data);
	cast(data);
	texture(data);
}
