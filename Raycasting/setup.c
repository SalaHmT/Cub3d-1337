/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:10:15 by shamsate          #+#    #+#             */
/*   Updated: 2024/05/27 18:02:37 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "raycasting.h"

void player_init_(t_data *data) {
    data->player.x = (float)data->map.player_x * TILE_SIZE;
    data->player.y = (float)data->map.player_y * TILE_SIZE;
    data->player.width = 1;
    data->player.height = 1;
    data->player.turnDirection = 0;
    data->player.walkDirection = 0;
    data->player.rotationAngle = PI / 2;
    data->player.walkSpeed = 100;
    data->player.turnSpeed = 45 * (PI / 180);
    data->mlx.x_win = data->map.map_x * TILE_SIZE;
    data->mlx.y_win = data->map.map_y * TILE_SIZE;
}

void setup(t_data *data)
{
    player_init_(data);
    data->mlx.mlx_ptr = mlx_init(data->mlx.x_win, data->mlx.y_win, "cub3d", false);
    data->mlx.img_ptr = mlx_new_image(data->mlx.mlx_ptr, data->mlx.x_win, data->mlx.y_win);
    
    // Load and convert textures to images
    data->mlx.mlx_texture[0] = mlx_load_png(data->map.so);  // South texture
    data->mlx.mlx_texture[1] = mlx_load_png(data->map.no);  // North texture
    data->mlx.mlx_texture[2] = mlx_load_png(data->map.we);  // West texture
    data->mlx.mlx_texture[3] = mlx_load_png(data->map.ea);  // East texture

    for (int i = 0; i < 4; i++) {
        data->mlx.mlx_texture_img[i] = mlx_texture_to_image(data->mlx.mlx_ptr, data->mlx.mlx_texture[i]);
        mlx_resize_image(data->mlx.mlx_texture_img[i], TEXTURE_WIDTH, TEXTURE_HEIGHT);
    }

    mlx_loop_hook(data->mlx.mlx_ptr, (void *)update, data);
    mlx_image_to_window(data->mlx.mlx_ptr, data->mlx.img_ptr, 0, 0);
    mlx_loop(data->mlx.mlx_ptr);
}