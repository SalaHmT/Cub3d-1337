/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_cast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:24:24 by zbendahh          #+#    #+#             */
/*   Updated: 2024/05/25 02:36:21 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

void	check_horizontal_wall_hit(t_data *data)
{
	if (data->map.map[(int)data->cast.y_to_check / TILE_SIZE] \
		[(int)data->cast.x_to_check / TILE_SIZE] != 48 && \
		data->map.map[(int)data->cast.y_to_check / TILE_SIZE]
		[(int)data->cast.x_to_check / TILE_SIZE] != 83)
	{
		data->cast.horz_wall_hit_x = data->cast.next_horz_touch_x;
		data->cast.horz_wall_hit_y = data->cast.next_horz_touch_y;
		data->cast.horz_wall_content = data->map.map[(int) \
			floor(data->cast.y_to_check / TILE_SIZE)] \
			[(int)floor(data->cast.x_to_check / TILE_SIZE)] - 48;
		data->cast.found_horz_wall_hit = 1;
	}
}

void	horizontal_while(t_data *data)
{
	while (data->cast.next_horz_touch_x >= 0 && \
		data->cast.next_horz_touch_x <= data->mlx.win_x && \
		data->cast.next_horz_touch_y >= 0 && \
		data->cast.next_horz_touch_y <= data->mlx.win_y)
	{
		data->cast.x_to_check = data->cast.next_horz_touch_x;
		if (data->cast.is_ray_facing_up)
			data->cast.y_to_check = data->cast.next_horz_touch_y + -1;
		else
			data->cast.y_to_check = data->cast.next_horz_touch_y + 0;
		check_horizontal_wall_hit(data);
		if (data->cast.found_horz_wall_hit)
			break ;
		else
		{
			data->cast.next_horz_touch_x += data->cast.x_step;
			data->cast.next_horz_touch_y += data->cast.y_step;
		}
	}
}

void	horizontal(t_data *data, float ray_angle)
{
	data->cast.y_intercept = \
		floor(data->player.y_player / TILE_SIZE) * TILE_SIZE;
	if (data->cast.is_ray_facing_down)
		data->cast.y_intercept += TILE_SIZE;
	data->cast.x_intercept = data->player.x_player + \
		(data->cast.y_intercept - data->player.y_player) / tan(ray_angle);
	data->cast.y_step = TILE_SIZE;
	if (data->cast.is_ray_facing_up)
		data->cast.y_step *= -1;
	else
		data->cast.y_step *= 1;
	data->cast.x_step = TILE_SIZE / tan(ray_angle);
	if ((data->cast.is_ray_facing_left && data->cast.x_step > 0) || \
		(data->cast.is_ray_facing_right && data->cast.x_step < 0))
		data->cast.x_step *= -1;
	else
		data->cast.x_step *= 1;
	data->cast.next_horz_touch_x = data->cast.x_intercept;
	data->cast.next_horz_touch_y = data->cast.y_intercept;
	horizontal_while(data);
}
