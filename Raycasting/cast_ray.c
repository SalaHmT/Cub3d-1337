/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:29:39 by zbendahh          #+#    #+#             */
/*   Updated: 2024/06/04 10:21:48 by zbendahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

float	normalize_angle(float angle)
{
	angle = remainder(angle, PI_2);
	if (angle < 0)
		angle = PI_2 + angle;
	return (angle);
}

void	check_derction(t_data *data, float ray_angle)
{
	data->cast.is_ray_facing_down = \
		ray_angle > 0 && ray_angle < PI;
	data->cast.is_ray_facing_up = \
		!data->cast.is_ray_facing_down;
	data->cast.is_ray_facing_right = \
		ray_angle < 0.5 * PI || ray_angle > 1.5 * PI;
	data->cast.is_ray_facing_left = \
		!data->cast.is_ray_facing_right;
}

void	incidence_distances(t_data *data)
{
	if (data->cast.found_horz_wall_hit)
		data->cast.horz_hit_distance = \
			sqrt((data->cast.horz_wall_hit_x - data->player.x) * \
			(data->cast.horz_wall_hit_x - data->player.x) + \
			(data->cast.horz_wall_hit_y - data->player.y) * \
			(data->cast.horz_wall_hit_y - data->player.y));
	else
		data->cast.horz_hit_distance = FLT_MAX;
	if (data->cast.found_vert_wall_hit)
		data->cast.vert_hit_distance = \
			sqrt((data->cast.vert_wall_hit_x - data->player.x) * \
			(data->cast.vert_wall_hit_x - data->player.x) + \
			(data->cast.vert_wall_hit_y - data->player.y) * \
			(data->cast.vert_wall_hit_y - data->player.y));
	else
		data->cast.vert_hit_distance = FLT_MAX;
}

void	cast_ray(t_data *data, float ray_angle, int strip_id)
{
	check_derction(data, ray_angle);
	is_horizontal(data, ray_angle);
	is_vertical(data, ray_angle);
	incidence_distances(data);
	if (data->cast.vert_hit_distance < data->cast.horz_hit_distance)
	{
		data->rays[strip_id].distance = data->cast.vert_hit_distance;
		data->rays[strip_id].wall_hit_x = data->cast.vert_wall_hit_x;
		data->rays[strip_id].wall_hit_y = data->cast.vert_wall_hit_y;
		data->rays[strip_id].wall_hit_content = data->cast.vert_wall_content;
		data->rays[strip_id].was_hit_vertical = 1;
	}
	else
	{
		data->rays[strip_id].distance = data->cast.horz_hit_distance;
		data->rays[strip_id].wall_hit_x = data->cast.horz_wall_hit_x;
		data->rays[strip_id].wall_hit_y = data->cast.horz_wall_hit_y;
		data->rays[strip_id].wall_hit_content = data->cast.horz_wall_content;
		data->rays[strip_id].was_hit_vertical = 0;
	}
	data->rays[strip_id].ray_angle = ray_angle;
	data->rays[strip_id].is_ray_facing_down = data->cast.is_ray_facing_down;
	data->rays[strip_id].is_ray_facing_up = data->cast.is_ray_facing_up;
	data->rays[strip_id].is_ray_facing_left = data->cast.is_ray_facing_left;
	data->rays[strip_id].is_ray_facing_right = data->cast.is_ray_facing_right;
}

void	cast_rays(t_data *data)
{
	float	ray_angle;
	int		strip_id;

	strip_id = 0;
	ray_angle = data->player.rotation_angle - (FOV_ANGLE / 2);
	while (strip_id < data->mlx.x_win)
	{
		cast_ray(data, \
			(normalize_angle(ray_angle += \
			FOV_ANGLE / data->mlx.x_win)), \
			strip_id++);
	}
}
