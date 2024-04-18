/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:56:45 by shamsate          #+#    #+#             */
/*   Updated: 2024/04/18 11:18:49 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

void	calculate_horizontal_distance(t_data *data, \
	float playerX, float playerY)
{
	float	horz_distance;

	if (data->cast_rays.foundHorzWallHit)
	{
		horz_distance = sqrt((data->cast_rays.horzWallHitX - playerX) * \
			(data->cast_rays.horzWallHitX - playerX) \
				+ (data->cast_rays.horzWallHitY - playerY) \
				* (data->cast_rays.horzWallHitY - playerY));
		data->cast_rays.horzHitDistance = horz_distance;
	}
	else
		data->cast_rays.horzHitDistance = FLT_MAX;
}

void	calculate_vertical_distance(t_data *data, float playerX, float playerY)
{
	float	vert_distance;

	if (data->cast_rays.foundVertWallHit)
	{
		vert_distance = sqrt((data->cast_rays.vertWallHitX - playerX) \
			* (data->cast_rays.vertWallHitX - playerX) \
				+ (data->cast_rays.vertWallHitY - playerY) \
					* (data->cast_rays.vertWallHitY - playerY));
		data->cast_rays.vertHitDistance = vert_distance;
	}
	else
		data->cast_rays.vertHitDistance = FLT_MAX;
}
