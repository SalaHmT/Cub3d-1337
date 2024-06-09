/* ************************************************************************** */
/*		                                                                    */
/*                                                        :::      ::::::::   */
/*   cast_to_3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:49:03 by zbendahh          #+#    #+#             */
/*   Updated: 2024/06/04 10:37:45 by zbendahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	floor_and_ceiling(t_data *data, int pixel_i)
{
	int	pixel_j;

	pixel_j = 0;
	while (pixel_j < data->cast_3d.wall_top_pixel)
		mlx_put_pixel(data->mlx.img_ptr, \
			pixel_i, \
			pixel_j++, \
			data->map.ceiling_color);
	pixel_j = data->cast_3d.wall_bottom_pixel;
	if (pixel_j < 0)
		pixel_j = data->mlx.y_win;
	while (pixel_j < data->mlx.y_win)
		mlx_put_pixel(data->mlx.img_ptr, \
			pixel_i, \
			pixel_j++, \
			data->map.floor_color);
}

mlx_image_t	*is_ver_or_horiz(t_data *data, int pixel_i)
{
	mlx_image_t	*current_texture_img;

	if (data->rays[pixel_i].was_hit_vertical)
	{
		if (data->rays[pixel_i].is_ray_facing_right)
			current_texture_img = data->mlx.mlx_texture_img[3];
		else
			current_texture_img = data->mlx.mlx_texture_img[2];
		data->cast_3d.texture_offset_x = \
			(int)data->rays[pixel_i].wall_hit_y % TILE_SIZE;
	}
	else
	{
		if (data->rays[pixel_i].is_ray_facing_down)
			current_texture_img = data->mlx.mlx_texture_img[0];
		else
			current_texture_img = data->mlx.mlx_texture_img[1];
		data->cast_3d.texture_offset_x = \
			(int)data->rays[pixel_i].wall_hit_x % TILE_SIZE;
	}
	return (current_texture_img);
}

void	wall(t_data *data, int pixel_i)
{
	int			pixel_j;
	int			texture_x;
	int			texture_y;
	mlx_image_t	*current_texture_img;

	current_texture_img = is_ver_or_horiz(data, pixel_i);
	pixel_j = data->cast_3d.wall_top_pixel;
	while (pixel_j < data->cast_3d.wall_bottom_pixel)
	{
		data->cast_3d.distance_from_top = pixel_j + \
			(data->cast_3d.wall_strip_height / 2) - (data->mlx.y_win / 2);
		data->cast_3d.texture_offset_y = \
			data->cast_3d.distance_from_top * \
			((float)TEXTURE_HEIGHT / data->cast_3d.wall_strip_height);
		texture_x = data->cast_3d.texture_offset_x % TEXTURE_WIDTH;
		texture_y = data->cast_3d.texture_offset_y % TEXTURE_HEIGHT;
		mlx_put_pixel(data->mlx.img_ptr, \
			pixel_i, pixel_j++, \
			mlx_get_pixel(current_texture_img, \
			texture_x, \
			texture_y));
	}
}

void	cast_3d_init(t_data *data, int pixel_i)
{
	data->cast_3d.perp_distance = data->rays[pixel_i].distance * \
		cos(data->rays[pixel_i].ray_angle - data->player.rotation_angle);
	data->cast_3d.distance_proj_plane = \
		(data->mlx.x_win / 2) / tan(FOV_ANGLE / 2);
	data->cast_3d.projected_wall_height = \
		(TILE_SIZE / data->cast_3d.perp_distance) \
		* data->cast_3d.distance_proj_plane;
	data->cast_3d.wall_strip_height = (int)data->cast_3d.projected_wall_height;
	data->cast_3d.wall_top_pixel = \
		(data->mlx.y_win / 2) - (data->cast_3d.wall_strip_height / 2);
	if (data->cast_3d.wall_top_pixel < 0)
		data->cast_3d.wall_top_pixel = 0;
	else
		data->cast_3d.wall_top_pixel = data->cast_3d.wall_top_pixel;
	data->cast_3d.wall_bottom_pixel = (data->mlx.y_win / 2) + \
		(data->cast_3d.wall_strip_height / 2);
	if (data->cast_3d.wall_bottom_pixel > data->mlx.y_win)
		data->cast_3d.wall_bottom_pixel = data->mlx.y_win;
	else
		data->cast_3d.wall_bottom_pixel = data->cast_3d.wall_bottom_pixel;
}

void	cast_to_3d(t_data *data)
{
	int	pixel_i;

	pixel_i = 0;
	while (pixel_i < data->mlx.x_win)
	{
		floor_and_ceiling(data, pixel_i);
		cast_3d_init(data, pixel_i);
		wall(data, pixel_i++);
	}
}
