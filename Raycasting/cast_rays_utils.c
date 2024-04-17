/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 06:59:32 by zbendahh          #+#    #+#             */
/*   Updated: 2024/04/17 07:15:10 by zbendahh         ###   ########.fr       */
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

void	horizontal_while(t_data *data)
{
	while (data->cast_rays.nextHorzTouchX >= 0 && \
		data->cast_rays.nextHorzTouchX <= data->mlx.win_size_x && \
		data->cast_rays.nextHorzTouchY >= 0 && \
		data->cast_rays.nextHorzTouchY <= data->mlx.win_size_y)
	{
		data->cast_rays.xToCheck = data->cast_rays.nextHorzTouchX;
		if (data->cast_rays.isRayFacingUp)
			data->cast_rays.yToCheck = data->cast_rays.nextHorzTouchY + -1;
		else
			data->cast_rays.yToCheck = data->cast_rays.nextHorzTouchY + 0;
		if (data->map.map[(int)data->cast_rays.yToCheck / TILE_SIZE] \
			[(int)data->cast_rays.xToCheck / TILE_SIZE] != 48 \
			&& data->map.map[(int)data->cast_rays.yToCheck / TILE_SIZE] \
			[(int)data->cast_rays.xToCheck / TILE_SIZE] != 83)
		{
			data->cast_rays.horzWallHitX = data->cast_rays.nextHorzTouchX;
			data->cast_rays.horzWallHitY = data->cast_rays.nextHorzTouchY;
			data->cast_rays.horzWallContent = data->map.map[(int) \
				floor(data->cast_rays.yToCheck / TILE_SIZE)] \
				[(int)floor(data->cast_rays.xToCheck / TILE_SIZE)] - 48;
			data->cast_rays.foundHorzWallHit = 1;
			break ;
		}
		else
		{
			data->cast_rays.nextHorzTouchX += data->cast_rays.x_step;
			data->cast_rays.nextHorzTouchY += data->cast_rays.y_step;
		}
	}
}

void	vertical_while(t_data *data)
{
	while (data->cast_rays.nextVertTouchX >= 0 && \
		data->cast_rays.nextVertTouchX <= data->mlx.win_size_x && \
		data->cast_rays.nextVertTouchY >= 0 && \
		data->cast_rays.nextVertTouchY <= data->mlx.win_size_y)
	{
		if (data->cast_rays.isRayFacingLeft)
			data->cast_rays.xToCheck = data->cast_rays.nextVertTouchX + -1;
		else
			data->cast_rays.xToCheck = data->cast_rays.nextVertTouchX + 0;
		data->cast_rays.yToCheck = data->cast_rays.nextVertTouchY;
		if (data->map.map[(int)data->cast_rays.yToCheck / TILE_SIZE] \
			[(int)data->cast_rays.xToCheck / TILE_SIZE] != 48 && \
			data->map.map[(int)data->cast_rays.yToCheck / TILE_SIZE] \
			[(int)data->cast_rays.xToCheck / TILE_SIZE] != 83)
		{
			data->cast_rays.vertWallHitX = data->cast_rays.nextVertTouchX;
			data->cast_rays.vertWallHitY = data->cast_rays.nextVertTouchY;
			data->cast_rays.vertWallContent = data->map.map[(int) \
				floor(data->cast_rays.yToCheck / TILE_SIZE)] \
				[(int)floor(data->cast_rays.xToCheck / TILE_SIZE)] - 48;
			data->cast_rays.foundVertWallHit = 1;
			break ;
		}
		else
		{
			data->cast_rays.nextVertTouchX += data->cast_rays.x_step;
			data->cast_rays.nextVertTouchY += data->cast_rays.y_step;
		}
	}
}
