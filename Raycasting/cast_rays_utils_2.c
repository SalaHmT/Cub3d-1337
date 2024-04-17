/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:06:07 by shamsate          #+#    #+#             */
/*   Updated: 2024/04/17 12:27:36 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

void	update_vertical_check_position(t_data *data)
{
	if (data->cast_rays.isRayFacingLeft)
		data->cast_rays.xToCheck = data->cast_rays.nextVertTouchX + -1;
	else
		data->cast_rays.xToCheck = data->cast_rays.nextVertTouchX + 0;
	data->cast_rays.yToCheck = data->cast_rays.nextVertTouchY;
}

void	check_vertical_wall_hit(t_data *data)
{
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
	}
}

void	update_next_vertical_touch(t_data *data)
{
	data->cast_rays.nextVertTouchX += data->cast_rays.x_step;
	data->cast_rays.nextVertTouchY += data->cast_rays.y_step;
}

void	vertical_while_part1(t_data *data)
{
	while (data->cast_rays.nextVertTouchX >= 0 && \
		data->cast_rays.nextVertTouchX <= data->mlx.win_size_x && \
		data->cast_rays.nextVertTouchY >= 0 && \
		data->cast_rays.nextVertTouchY <= data->mlx.win_size_y)
	{
		update_vertical_check_position(data);
		check_vertical_wall_hit(data);
		if (data->cast_rays.foundVertWallHit)
			break ;
		else
			update_next_vertical_touch(data);
	}
}

void	vertical_while_part2(t_data *data)
{
	while (data->cast_rays.nextVertTouchX >= 0 && \
		data->cast_rays.nextVertTouchX <= data->mlx.win_size_x && \
		data->cast_rays.nextVertTouchY >= 0 && \
		data->cast_rays.nextVertTouchY <= data->mlx.win_size_y)
	{
		update_vertical_check_position(data);
		check_vertical_wall_hit(data);
		if (data->cast_rays.foundVertWallHit)
			break ;
		else
			update_next_vertical_touch(data);
	}
}
