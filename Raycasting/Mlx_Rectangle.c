/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mlx_Rectangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:12:12 by zbendahh          #+#    #+#             */
/*   Updated: 2024/04/14 12:27:05 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

void	mlx_rectangle(t_data *data, int x_old, int y_old, int color)
{
	int		x_new;
	int		y_new;

	y_new = 0;
	x_new = x_old;
	while (x_new < x_old + TILE_SIZE)
	{
		y_new = y_old;
		while (y_new < y_old + TILE_SIZE)
			img_pix_put(&data->mlx, x_new, y_new++, color);
		x_new++;
	}
}
