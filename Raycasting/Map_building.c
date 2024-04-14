/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map_Building.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:42:14 by zbendahh          #+#    #+#             */
/*   Updated: 2024/04/14 12:15:27 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

void	map_building(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.map_y)
	{
		j = 0;
		while (j < data->map.map_x)
		{
			if (data->map.map[i][j] == '0' || data->map.map[i][j] == 'S')
				mlx_rectangle(data, j * TILE_SIZE, i * TILE_SIZE, 0x76ABAE);
			else if (data->map.map[i][j] == '1')
				mlx_rectangle(data, j * TILE_SIZE, i * TILE_SIZE, 0xA0153E);
			j++;
		}
		i++;
	}
}
