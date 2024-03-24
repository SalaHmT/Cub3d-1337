/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:32:12 by zbendahh          #+#    #+#             */
/*   Updated: 2024/03/24 14:12:02 by zbendahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

void    mlx_setup(t_data *data)
{
    data->mlx.mlx_ptr = mlx_init();
    data->mlx.win_ptr = mlx_new_window(data->mlx.mlx_ptr, data->width, data->heigh, ".....C U B 3 D.....");
    data->mlx.img_ptr = mlx_new_image(data->mlx.mlx_ptr, data->heigh, data->width);
    data->mlx.data_addr = mlx_get_data_addr(data->mlx.img_ptr, &data->mlx.bits_per_pixel, &data->mlx.line_length, &data->mlx.endian);

    data->rectangle.y = 0;
    data->rectangle.x = 0;
    data->rectangle.width = 32;
    data->rectangle.height = 32;
    data->rectangle.c_color = 0xFFFFFF;
    rectangle(data);
    mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, data->mlx.img_ptr, 0, 0);
    mlx_loop(data->mlx.mlx_ptr);
    free(data);
}