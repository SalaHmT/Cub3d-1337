/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:19:26 by shamsate          #+#    #+#             */
/*   Updated: 2024/04/17 12:26:57 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

void	check_horizontal_wall_hit(t_data *data)
{
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
	}
}

void	update_next_horizontal_touch(t_data *data)
{
	data->cast_rays.nextHorzTouchX += data->cast_rays.x_step;
	data->cast_rays.nextHorzTouchY += data->cast_rays.y_step;
}

void	horizontal_while_part1(t_data *data)
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
		check_horizontal_wall_hit(data);
		if (data->cast_rays.foundHorzWallHit)
			break ;
		else
			update_next_horizontal_touch(data);
	}
}

void	horizontal_while_part2(t_data *data)
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
		check_horizontal_wall_hit(data);
		if (data->cast_rays.foundHorzWallHit)
			break ;
		else
			update_next_horizontal_touch(data);
	}
}
