/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:59:26 by zbendahh          #+#    #+#             */
/*   Updated: 2024/06/04 10:02:11 by zbendahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	horizontal_while(t_data *data)
{
	while (data->cast.next_horz_touch_x >= 0 && \
			data->cast.next_horz_touch_x <= data->mlx.x_win && \
			data->cast.next_horz_touch_y >= 0 && \
			data->cast.next_horz_touch_y <= data->mlx.y_win)
	{
		data->cast.x_to_check = data->cast.next_horz_touch_x;
		if (data->cast.is_ray_facing_up)
			data->cast.y_to_check = data->cast.next_horz_touch_y + (-1);
		else
			data->cast.y_to_check = data->cast.next_horz_touch_y + 0;
		if (check_collisions(data, data->cast.x_to_check, \
			data->cast.y_to_check) != 0)
		{
			data->cast.horz_wall_hit_x = data->cast.next_horz_touch_x;
			data->cast.horz_wall_hit_y = data->cast.next_horz_touch_y;
			data->cast.horz_wall_content = data->map.map \
				[(int)floor(data->cast.y_to_check / TILE_SIZE)] \
				[(int)floor(data->cast.x_to_check / TILE_SIZE)] - 48;
			data->cast.found_horz_wall_hit = 1;
			return ;
		}
		data->cast.next_horz_touch_x += data->cast.x_step;
		data->cast.next_horz_touch_y += data->cast.y_step;
	}
}

void	init_horizontal_trends(t_data *data)
{
	if (data->cast.is_ray_facing_up)
		data->cast.y_step *= -1;
	else if (!data->cast.is_ray_facing_up)
		data->cast.y_step *= 1;
	if (data->cast.is_ray_facing_left && data->cast.x_step > 0)
		data->cast.x_step *= -1;
	else if (!data->cast.is_ray_facing_left && data->cast.x_step > 0)
		data->cast.x_step *= 1;
	if (data->cast.is_ray_facing_right && data->cast.x_step < 0)
		data->cast.x_step *= -1;
	else if (!data->cast.is_ray_facing_right && data->cast.x_step < 0)
		data->cast.x_step *= 1;
}

void	is_horizontal(t_data *data, float ray_angle)
{
	data->cast.found_horz_wall_hit = 0;
	data->cast.horz_wall_hit_x = 0;
	data->cast.horz_wall_hit_y = 0;
	data->cast.horz_wall_content = 0;
	data->cast.y_step = TILE_SIZE;
	data->cast.x_step = TILE_SIZE / tan(ray_angle);
	data->cast.y_intercept = floor(data->player.y / TILE_SIZE) * TILE_SIZE;
	if (data->cast.is_ray_facing_down)
		data->cast.y_intercept += TILE_SIZE;
	else if (!data->cast.is_ray_facing_down)
		data->cast.y_intercept += 0;
	data->cast.x_intercept = data->player.x + \
		(data->cast.y_intercept - data->player.y) / \
		tan(ray_angle);
	init_horizontal_trends(data);
	data->cast.next_horz_touch_x = data->cast.x_intercept;
	data->cast.next_horz_touch_y = data->cast.y_intercept;
	horizontal_while(data);
}
