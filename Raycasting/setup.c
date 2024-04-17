/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:18:50 by shamsate          #+#    #+#             */
/*   Updated: 2024/04/17 10:19:03 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

void	mlx_setup(t_data *data)
{
	data->mlx.mlx_ptr = mlx_init();
	data->mlx.win_ptr = mlx_new_window(data->mlx.mlx_ptr, \
		data->mlx.win_size_x, \
		data->mlx.win_size_y, \
		"CUB 3D");
	data->mlx.img_ptr = mlx_new_image(data->mlx.mlx_ptr, \
		data->mlx.win_size_x, \
		data->mlx.win_size_y);
	data->mlx.addr_ptr = mlx_get_data_addr(data->mlx.img_ptr, \
		&data->mlx.bits_per_pixel, \
		&data->mlx.line_length, \
		&data->mlx.endian);
	mlx_hook(data->mlx.win_ptr, ON_KEYDOWN, 0L, pressed, data);
	mlx_hook(data->mlx.win_ptr, ON_KEYUP, 0L, released, data);
	mlx_hook(data->mlx.win_ptr, ON_MOUSEMOVE, 0L, mousemove, data);
	mlx_hook(data->mlx.win_ptr, ON_DESTROY, 0L, destroy, NULL);
	mlx_loop_hook(data->mlx.mlx_ptr, update, data);
	mlx_loop(data->mlx.mlx_ptr);
}
