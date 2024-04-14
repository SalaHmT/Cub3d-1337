/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mlx_Circle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:11:49 by zbendahh          #+#    #+#             */
/*   Updated: 2024/04/14 12:17:11 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

void	mlx_circle(t_data *data, int y, int x, int color)
{
	int	y_new;
	int	x_new;

	y_new = y - RADIUS_PLAYER;
	while (y_new <= y + RADIUS_PLAYER)
	{
		x_new = x - RADIUS_PLAYER;
		while (x_new <= x + RADIUS_PLAYER)
		{
			if ((y_new - y) * (y_new - y) + (x_new - x) * (x_new - x) \
				<= RADIUS_PLAYER * RADIUS_PLAYER)
				img_pix_put(&data->mlx, y_new, x_new, color);
			x_new++;
		}
		y_new++;
	}
}
