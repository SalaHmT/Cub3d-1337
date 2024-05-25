/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 05:44:23 by zbendahh          #+#    #+#             */
/*   Updated: 2024/05/25 21:16:02 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

void	init_cast(t_data *data, float ray_angle)
{
	data->cast.found_horz_wall_hit = 0;
	data->cast.found_vert_wall_hit = 0;
	data->cast.horz_wall_hit_x = 0;
	data->cast.horz_wall_hit_y = 0;
	data->cast.vert_wall_hit_x = 0;
	data->cast.vert_wall_hit_y = 0;
	data->cast.horz_wall_content = 0;
	data->cast.vert_wall_content = 0;
	data->cast.is_ray_facing_down = ray_angle > 0 && ray_angle < PI;
	data->cast.is_ray_facing_up = !data->cast.is_ray_facing_down;
	data->cast.is_ray_facing_left = !data->cast.is_ray_facing_right;
	data->cast.is_ray_facing_right = ray_angle < 0.5 * PI || ray_angle > 1.5 * PI;
}

float	normal_angle(float ray_angle)
{
	ray_angle = remainder(ray_angle, PI_2);
	if (ray_angle < 0)
		ray_angle = PI_2 + ray_angle;
	return (ray_angle);
}

void incidence_distances(t_data *data) {
    if (data->cast.found_horz_wall_hit)
		data->cast.horz_hit_distance = \
			sqrt((data->cast.horz_wall_hit_x - data->player.x_player) * \
			(data->cast.horz_wall_hit_x - data->player.x_player) + \
			(data->cast.horz_wall_hit_y - data->player.y_player) * \
			(data->cast.horz_wall_hit_y - data->player.y_player));
	else
		data->cast.horz_hit_distance = FLT_MAX;
	if (data->cast.found_vert_wall_hit)
		data->cast.vert_hit_distance = \
			sqrt((data->cast.vert_wall_hit_x - data->player.x_player) * \
			(data->cast.vert_wall_hit_x - data->player.x_player) + \
			(data->cast.vert_wall_hit_y - data->player.y_player) * \
			(data->cast.vert_wall_hit_y - data->player.y_player));
	else
		data->cast.vert_hit_distance = FLT_MAX;
}
void	init_ray(t_data *data, float ray_angle, int index)
{
	if (data->cast.vert_hit_distance < data->cast.horz_hit_distance)
	{
		data->ray[index].distance = data->cast.vert_hit_distance;
		data->ray[index].wall_hit_x = data->cast.vert_wall_hit_x;
		data->ray[index].wall_hit_y = data->cast.vert_wall_hit_y;
		data->ray[index].wall_hit_content = data->cast.vert_wall_content;
		data->ray[index].was_hit_vertical = 0;
	}
	else
	{
		data->ray[index].distance = data->cast.horz_hit_distance;
		data->ray[index].wall_hit_x = data->cast.horz_wall_hit_x;
		data->ray[index].wall_hit_y = data->cast.horz_wall_hit_y;
		data->ray[index].wall_hit_content = data->cast.horz_wall_content;
		data->ray[index].was_hit_vertical = 1;
	}
	data->ray[index].ray_angle = ray_angle;
	data->ray[index].is_ray_facing_down = data->cast.is_ray_facing_down;
	data->ray[index].is_ray_facing_up = data->cast.is_ray_facing_up;
	data->ray[index].is_ray_facing_left = data->cast.is_ray_facing_left;
	data->ray[index].is_ray_facing_right = data->cast.is_ray_facing_right;
}

void	cast(t_data *data)
{
	int		index;
	float	ray_angle;

	index = 0;
	ray_angle = data->player.player_rotation_angle - (FOV_ANGLE / 2);
	while (index < data->mlx.win_x)
	{
		init_cast(data, normal_angle(ray_angle));
		horizontal(data, ray_angle);
		vertical(data, ray_angle);
		incidence_distances(data);
		init_ray(data, ray_angle, index++);
		ray_angle += FOV_ANGLE / data->mlx.win_x;
	}
}

