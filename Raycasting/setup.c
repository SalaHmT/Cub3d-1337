/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 08:33:07 by zbendahh          #+#    #+#             */
/*   Updated: 2024/06/04 10:42:20 by zbendahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	loading_png(t_data *data)
{
	int	index;

	index = 0;
	data->mlx.mlx_texture[0] = mlx_load_png(data->map.so);
	data->mlx.mlx_texture[1] = mlx_load_png(data->map.no);
	data->mlx.mlx_texture[2] = mlx_load_png(data->map.we);
	data->mlx.mlx_texture[3] = mlx_load_png(data->map.ea);
	while (index < 4)
	{
		data->mlx.mlx_texture_img[index] = \
			mlx_texture_to_image(data->mlx.mlx_ptr, \
			data->mlx.mlx_texture[index]);
		mlx_resize_image(data->mlx.mlx_texture_img[index++], \
			TEXTURE_WIDTH, \
			TEXTURE_HEIGHT);
	}
}

void	setup(t_data *data)
{
	data->mlx.mlx_ptr = \
		mlx_init(data->mlx.x_win, \
		data->mlx.y_win, \
		"cub3d", false);
	data->mlx.img_ptr = \
		mlx_new_image(data->mlx.mlx_ptr, \
		data->mlx.x_win, \
		data->mlx.y_win);
	loading_png(data);
	mlx_loop_hook(data->mlx.mlx_ptr, (void *)update, data);
	mlx_image_to_window(data->mlx.mlx_ptr, data->mlx.img_ptr, 0, 0);
	mlx_loop(data->mlx.mlx_ptr);
}
