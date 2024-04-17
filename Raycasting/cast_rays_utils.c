/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 06:59:32 by zbendahh          #+#    #+#             */
/*   Updated: 2024/04/17 12:27:14 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

float	normal_angle(float ray_angle)
{
	ray_angle = remainder(ray_angle, TWO_PI);
	if (ray_angle < 0)
		ray_angle = TWO_PI + ray_angle;
	return (ray_angle);
}

void	init_var_rays(t_data *data, float ray_angle, int index)
{
	if (data->cast_rays.vertHitDistance < data->cast_rays.horzHitDistance)
	{
		data->ray[index].distance = data->cast_rays.vertHitDistance;
		data->ray[index].wall_hit_x = data->cast_rays.vertWallHitX;
		data->ray[index].wall_hit_y = data->cast_rays.vertWallHitY;
		data->ray[index].wall_hit_content = data->cast_rays.vertWallContent;
		data->ray[index].was_hit_vertical = 0;
	}
	else
	{
		data->ray[index].distance = data->cast_rays.horzHitDistance;
		data->ray[index].wall_hit_x = data->cast_rays.horzWallHitX;
		data->ray[index].wall_hit_y = data->cast_rays.horzWallHitY;
		data->ray[index].wall_hit_content = data->cast_rays.horzWallContent;
		data->ray[index].was_hit_vertical = 1;
	}
	data->ray[index].ray_angle = ray_angle;
	data->ray[index].is_ray_facing_down = data->cast_rays.isRayFacingDown;
	data->ray[index].is_ray_facing_up = data->cast_rays.isRayFacingUp;
	data->ray[index].is_ray_facing_left = data->cast_rays.isRayFacingLeft;
	data->ray[index].is_ray_facing_right = data->cast_rays.isRayFacingRight;
}
