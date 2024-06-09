/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 08:48:13 by zbendahh          #+#    #+#             */
/*   Updated: 2024/06/04 10:42:01 by zbendahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	check_collisions(t_data *data, float x, float y)
{
	int	x_;
	int	y_;

	y_ = (int)floor(y / TILE_SIZE);
	x_ = (int)floor(x / TILE_SIZE);
	if (data->map.map[y_][x_] == '1')
		return (1);
	else if (data->map.map[y_][x_] == '0')
		return (0);
	else if (data->map.map[y_][x_] == 'S')
		return (0);
	else if (data->map.map[y_][x_] == 'N')
		return (0);
	else if (data->map.map[y_][x_] == 'E')
		return (0);
	else if (data->map.map[y_][x_] == 'W')
		return (0);
	return (1);
}

void	clear(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->mlx.x_win)
	{
		j = 0;
		while (j < data->mlx.y_win)
			mlx_put_pixel(data->mlx.img_ptr, i, j++, 0xFF000000);
		i++;
	}
}

int32_t	get_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int32_t	mlx_get_pixel(mlx_image_t *image, uint32_t x, uint32_t y)
{
	uint8_t	*pixelstart;
	int32_t	color;

	if (x >= image->width || y >= image->height)
		return (0xFF000000);
	pixelstart = (image->pixels + (y * image->width + x) * sizeof(int32_t));
	color = get_rgba(pixelstart[0], \
	pixelstart[1], \
	pixelstart[2], \
	pixelstart[3]);
	return (color);
}
