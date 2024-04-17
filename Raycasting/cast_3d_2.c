/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_3d_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:04:57 by shamsate          #+#    #+#             */
/*   Updated: 2024/04/17 11:14:11 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

void	sky_3d(t_data *data, int i)
{
	int	j;

	j = 0;
	while (j < data->cast_3d.wall_top_pixel)
		img_pixel_put(&data->mlx, i, j++, 0x102C57);
}

void	cast_3d(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->mlx.win_size_x)
	{
		walls_3d(data, i);
		render_walls(data, i);
		floor_3d(data, i);
		sky_3d(data, i);
		i++;
	}
}
