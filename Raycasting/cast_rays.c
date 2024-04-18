/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 05:44:23 by zbendahh          #+#    #+#             */
/*   Updated: 2024/04/18 11:21:18 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

void	horizontal(t_data *data, float ray_angle)
{
	data->cast_rays.y_intercept = \
		floor(data->player.y_player / TILE_SIZE) * TILE_SIZE;
	if (data->cast_rays.isRayFacingDown)
		data->cast_rays.y_intercept += TILE_SIZE;
	data->cast_rays.x_intercept = data->player.x_player + \
		(data->cast_rays.y_intercept - data->player.y_player) / tan(ray_angle);
	data->cast_rays.y_step = TILE_SIZE;
	if (data->cast_rays.isRayFacingUp)
		data->cast_rays.y_step *= -1;
	else
		data->cast_rays.y_step *= 1;
	data->cast_rays.x_step = TILE_SIZE / tan(ray_angle);
	if ((data->cast_rays.isRayFacingLeft && data->cast_rays.x_step > 0) || \
		(data->cast_rays.isRayFacingRight && data->cast_rays.x_step < 0))
		data->cast_rays.x_step *= -1;
	else
		data->cast_rays.x_step *= 1;
	data->cast_rays.nextHorzTouchX = data->cast_rays.x_intercept;
	data->cast_rays.nextHorzTouchY = data->cast_rays.y_intercept;
	horizontal_while_part1(data);
	horizontal_while_part2(data);
}

void	vertical(t_data *data, float ray_angle)
{
	data->cast_rays.x_intercept = \
		floor(data->player.x_player / TILE_SIZE) * TILE_SIZE;
	if (data->cast_rays.isRayFacingRight)
		data->cast_rays.x_intercept += TILE_SIZE;
	else
		data->cast_rays.x_intercept += 0;
	data->cast_rays.y_intercept = data->player.y_player + \
		(data->cast_rays.x_intercept - data->player.x_player) * tan(ray_angle);
	data->cast_rays.x_step = TILE_SIZE;
	if (data->cast_rays.isRayFacingLeft)
		data->cast_rays.x_step *= -1;
	else
		data->cast_rays.x_step *= 1;
	data->cast_rays.y_step = TILE_SIZE * tan(ray_angle);
	if ((data->cast_rays.isRayFacingUp && data->cast_rays.y_step > 0) || \
		(data->cast_rays.isRayFacingDown && data->cast_rays.y_step < 0))
		data->cast_rays.y_step *= -1;
	else
		data->cast_rays.y_step *= 1;
	data->cast_rays.nextVertTouchX = data->cast_rays.x_intercept;
	data->cast_rays.nextVertTouchY = data->cast_rays.y_intercept;
	vertical_while_part1(data);
	vertical_while_part2(data);
}

void	cast_ray(t_data *data, float ray_angle, int index)
{
	data->cast_rays.foundHorzWallHit = 0;
	data->cast_rays.horzWallHitX = 0;
	data->cast_rays.horzWallHitY = 0;
	data->cast_rays.horzWallContent = 0;
	data->cast_rays.foundVertWallHit = 0;
	data->cast_rays.vertWallHitX = 0;
	data->cast_rays.vertWallHitY = 0;
	data->cast_rays.vertWallContent = 0;
	data->cast_rays.isRayFacingDown = (ray_angle > 0 && ray_angle < PI);
	data->cast_rays.isRayFacingUp = !data->cast_rays.isRayFacingDown;
	data->cast_rays.isRayFacingRight = (ray_angle < 0.5 * PI \
		|| ray_angle > 1.5 * PI);
	data->cast_rays.isRayFacingLeft = !data->cast_rays.isRayFacingRight;
	horizontal(data, ray_angle);
	vertical(data, ray_angle);
	calculate_horizontal_distance(data, data->player.x_player, \
		data->player.y_player);
	calculate_vertical_distance(data, data->player.x_player, \
		data->player.y_player);
	init_var_rays(data, ray_angle, index);
}

void	cast_all_rays(t_data *data)
{
	int		index;
	float	ray_angle;

	index = 0;
	ray_angle = data->player.player_rotation_angle - (FOV_ANGLE / 2);
	while (index < NUM_RAYS)
	{
		cast_ray(data, normal_angle(ray_angle), index);
		ray_angle += FOV_ANGLE / NUM_RAYS;
		index++;
	}
}
