/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:18:55 by zbendahh          #+#    #+#             */
/*   Updated: 2024/05/27 20:55:10 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	vertical_while(t_data *data)
{
	while (data->cast.next_vert_touch_x >= 0 && \
			data->cast.next_vert_touch_x <= data->mlx.x_win && \
			data->cast.next_vert_touch_y >= 0 && \
			data->cast.next_vert_touch_y <= data->mlx.y_win)
	{
		data->cast.y_to_check = data->cast.next_vert_touch_y;
		if (data->cast.is_ray_facing_left)
			data->cast.x_to_check = data->cast.next_vert_touch_x + (-1);
		else
			data->cast.x_to_check = data->cast.next_vert_touch_x + 0;
		if (data->map.map[(int)data->cast.y_to_check / TILE_SIZE][(int)data->cast.x_to_check / TILE_SIZE] != 48 && data->map.map[(int)data->cast.y_to_check / TILE_SIZE][(int)data->cast.x_to_check / TILE_SIZE] != 83)
		{
			data->cast.vert_wall_hit_x = data->cast.next_vert_touch_x;
			data->cast.vert_wall_hit_y = \
			data->cast.next_vert_touch_y;
			data->cast.vert_wall_content = data->map.map[(int)floor(data->cast.y_to_check \
				/ TILE_SIZE)][(int)floor(data->cast.x_to_check / TILE_SIZE)] - 48;
			data->cast.found_vert_wall_hit = 1;
			break ;
		}
		else
		{
			data->cast.next_vert_touch_x += data->cast.x_step;
			data->cast.next_vert_touch_y += data->cast.y_step;
		}
	}
}

void	init_vertical_derction(t_data *data)
{
	if (data->cast.is_ray_facing_left)
		data->cast.x_step *= -1;
	else if (!data->cast.is_ray_facing_left)
		data->cast.x_step *= 1;
	if (data->cast.is_ray_facing_up && data->cast.y_step > 0)
		data->cast.y_step *= -1;
	else if (!data->cast.is_ray_facing_up && data->cast.y_step > 0)
		data->cast.y_step *= 1;
	if (data->cast.is_ray_facing_down && data->cast.y_step < 0)
		data->cast.y_step *= -1;
	else if (!data->cast.is_ray_facing_down && data->cast.y_step < 0)
		data->cast.y_step *= 1;
}

void	is_vertical(t_data *data, float ray_angle)
{
	data->cast.found_vert_wall_hit = 0;
	data->cast.vert_wall_hit_x = 0;
	data->cast.vert_wall_hit_y = 0;
	data->cast.vert_wall_content = 0;
	data->cast.x_step = TILE_SIZE;
	data->cast.y_step = TILE_SIZE * tan(ray_angle);
	data->cast.x_intercept = floor(data->player.x / TILE_SIZE) * TILE_SIZE;
	if (data->cast.is_ray_facing_right)
		data->cast.x_intercept += TILE_SIZE;
	else if (!data->cast.is_ray_facing_right)
		data->cast.x_intercept += 0;
	data->cast.y_intercept = data->player.y + \
		(data->cast.x_intercept - data->player.x) \
		* tan(ray_angle);
	init_vertical_derction(data);
	data->cast.next_vert_touch_x = data->cast.x_intercept;
	data->cast.next_vert_touch_y = data->cast.y_intercept;
	vertical_while(data);

}
