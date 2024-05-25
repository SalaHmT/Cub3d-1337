/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:18:50 by shamsate          #+#    #+#             */
/*   Updated: 2024/05/25 02:34:42 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

void	setup(t_data *data)
{
	data->mlx.mlx_ptr = mlx_init(data->mlx.win_x, \
	data->mlx.win_y, "CUB 3D", false);
	data->mlx.img_ptr = mlx_new_image(data->mlx.mlx_ptr, \
		data->mlx.win_x, \
		data->mlx.win_y);
	mlx_image_to_window(data->mlx.mlx_ptr, \
		data->mlx.img_ptr, \
		data->mlx.img_x, \
		data->mlx.img_y);
	mlx_loop_hook(data->mlx.mlx_ptr, (void *)update, data);
	mlx_loop(data->mlx.mlx_ptr);
}
