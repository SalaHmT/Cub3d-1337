/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:49:03 by zbendahh          #+#    #+#             */
/*   Updated: 2024/05/28 02:35:24 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
void	floor_and_ceiling(t_data *data, int pixel_i)
{
	int	pixel_j;

	pixel_j = 0;
	while (pixel_j < data->cast_3d.wallTopPixel)
		mlx_put_pixel(data->mlx.img_ptr, \
			pixel_i, \
			pixel_j++, \
			get_rgba(55, 140, 231, 255));
	pixel_j = data->cast_3d.wallBottomPixel;
	while (pixel_j < data->mlx.y_win)
		mlx_put_pixel(data->mlx.img_ptr, \
			pixel_i, \
			pixel_j++, \
			get_rgba(150, 150, 150, 255));
}

void wall(t_data *data, int pixel_i)
{
    int pixel_j;
    mlx_image_t *current_texture_img;

    // Determine which texture to use based on the wall hit direction
    if (data->rays[pixel_i].wasHitVertical)
    {
        if (data->rays[pixel_i].isRayFacingRight)
            current_texture_img = data->mlx.mlx_texture_img[3];  // East texture
        else
            current_texture_img = data->mlx.mlx_texture_img[2];  // West texture
        data->cast_3d.textureOffsetX = (int)data->rays[pixel_i].wallHitY % TILE_SIZE;
    }
    else
    {
        if (data->rays[pixel_i].isRayFacingDown)
            current_texture_img = data->mlx.mlx_texture_img[0];  // South texture
        else
            current_texture_img = data->mlx.mlx_texture_img[1];  // North texture
        data->cast_3d.textureOffsetX = (int)data->rays[pixel_i].wallHitX % TILE_SIZE;
    }

    pixel_j = data->cast_3d.wallTopPixel;
    while (pixel_j < data->cast_3d.wallBottomPixel)
    {
        data->cast_3d.distanceFromTop = pixel_j + (data->cast_3d.wallStripHeight / 2) - (data->mlx.y_win / 2);
        data->cast_3d.textureOffsetY = data->cast_3d.distanceFromTop * ((float)TEXTURE_HEIGHT / data->cast_3d.wallStripHeight);
        // Ensure texture coordinates are within bounds
        int textureX = data->cast_3d.textureOffsetX % TEXTURE_WIDTH;
        int textureY = data->cast_3d.textureOffsetY % TEXTURE_HEIGHT;

        // Get the color from the texture image
        uint32_t color = mlx_get_pixel(current_texture_img, textureX, textureY);
        // Put the pixel color on the screen image
        mlx_put_pixel(data->mlx.img_ptr, pixel_i, pixel_j++, color);
    }
}

void	cast_3d_init(t_data *data, int pixel_i)
{
	data->cast_3d.perpDistance = data->rays[pixel_i].distance * \
		cos(data->rays[pixel_i].rayAngle - data->player.rotationAngle);
	data->cast_3d.distanceProjPlane = (data->mlx.x_win / 2) / tan(FOV_ANGLE / 2);
	data->cast_3d.projectedWallHeight = (TILE_SIZE / data->cast_3d.perpDistance) \
		* data->cast_3d.distanceProjPlane;
	data->cast_3d.wallStripHeight = (int)data->cast_3d.projectedWallHeight;
	data->cast_3d.wallTopPixel = (data->mlx.y_win / 2) - (data->cast_3d.wallStripHeight / 2);
	if (data->cast_3d.wallTopPixel < 0)
		data->cast_3d.wallTopPixel = 0;
	else
		data->cast_3d.wallTopPixel = data->cast_3d.wallTopPixel;
	data->cast_3d.wallBottomPixel = (data->mlx.y_win / 2) + \
		(data->cast_3d.wallStripHeight / 2);
	if (data->cast_3d.wallBottomPixel > data->mlx.y_win)
		data->cast_3d.wallBottomPixel = data->mlx.y_win;
	else
		data->cast_3d.wallBottomPixel = data->cast_3d.wallBottomPixel;
}


void	cast__3d(t_data *data)
{
	int	pixel_i;

	pixel_i = 0;

	while (pixel_i < data->mlx.x_win)
	{
		floor_and_ceiling(data, pixel_i);
		cast_3d_init(data, pixel_i);
		wall(data, pixel_i);
		pixel_i++;
	}
}