/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mlx_Line_DDA.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:11:54 by zbendahh          #+#    #+#             */
/*   Updated: 2024/04/14 12:25:34 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

void	mlx_line_dda(t_data *data, int y_first, int x_first, int y_last, int x_last, int color)
{
	float	x;
	float	y;
	int		i;
	int		x_int;
	int		y_int;
	int		steps;


	i = 0;
	x_int = x_last - x_first;
	y_int = y_last - y_first;
	if (abs(x_int) > abs(y_int))
		steps = abs(x_int);
	else
		steps = abs(y_int);
	x = x_first;
	y = y_first;
	while (i <= steps)
	{
		img_pix_put(&data->mlx, round(y), round(x), color);
		x += (x_int / (float) steps);
		y += (y_int / (float) steps);
		i++;
	}
}