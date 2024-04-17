/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 00:17:57 by zbendahh          #+#    #+#             */
/*   Updated: 2024/04/17 11:18:47 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

void	walls_3d(t_data *data, int i)
{
	data->cast_3d.perp_distance = data->ray[i].distance * \
		cos(data->ray[i].ray_angle - data->player.player_rotation_angle);
	data->cast_3d.distance_proj_plane = (data->mlx.win_size_x / 2) \
		/ tan(FOV_ANGLE / 2);
	data->cast_3d.projected_wall_height = (TILE_SIZE \
		/ data->cast_3d.perp_distance) * data->cast_3d.distance_proj_plane;
	data->cast_3d.wall_strip_height = \
		(int)data->cast_3d.projected_wall_height;
	data->cast_3d.wall_top_pixel = (data->mlx.win_size_y / 2) \
		- (data->cast_3d.wall_strip_height / 2);
	data->cast_3d.wall_bottom_pixel = (data->mlx.win_size_y / 2) \
		+ (data->cast_3d.wall_strip_height / 2);
	data->cast_3d.wall_strip_height = data->cast_3d.wall_strip_height;
	data->cast_3d.wall_top_pixel = (data->mlx.win_size_y / 2) \
		- (data->cast_3d.wall_strip_height / 2);
	if (data->cast_3d.wall_top_pixel < 0)
		data->cast_3d.wall_top_pixel = 0;
	data->cast_3d.wall_bottom_pixel = (data->mlx.win_size_y / 2) + \
		(data->cast_3d.wall_strip_height / 2);
	if (data->cast_3d.wall_bottom_pixel > data->mlx.win_size_y)
		data->cast_3d.wall_bottom_pixel = data->mlx.win_size_y;
}

void	render_walls(t_data *data, int i)
{
	int	j;

	j = data->cast_3d.wall_top_pixel;
	while (j < data->cast_3d.wall_bottom_pixel)
	{
		if (data->ray[i].was_hit_vertical)
			img_pixel_put(&data->mlx, i, j, 0x003C43);
		else if (!(data->ray[i].was_hit_vertical))
			img_pixel_put(&data->mlx, i, j, 0x135D66);
		j++;
	}
}

void	floor_3d(t_data *data, int i)
{
	int	j;

	j = data->cast_3d.wall_bottom_pixel;
	while (j < data->mlx.win_size_y)
		img_pixel_put(&data->mlx, i, j++, 0xDEAC80);
}
