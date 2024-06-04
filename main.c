/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 08:10:27 by zbendahh          #+#    #+#             */
/*   Updated: 2024/06/04 10:27:21 by zbendahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting/raycasting.h"
#include "parssing/parssing.h"

void	data_init(t_data *data)
{
	data->player.width = 1;
	data->player.height = 1;
	data->player.turn_direction = 0;
	data->player.walk_direction = 0;
	data->player.rotation_angle = PI / 2;
	data->player.walk_speed = 200;
	data->player.turn_speed = 90 * (PI / 180);
	data->player.x = (float)data->map.player_x * TILE_SIZE;
	data->player.y = (float)data->map.player_y * TILE_SIZE;
	data->mlx.x_win = data->map.map_x * TILE_SIZE;
	data->mlx.y_win = data->map.map_y * TILE_SIZE;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		return (write(2, "INVALID ARGUMENTS\n", 18), 1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (free(data), 0);
	data->map.map_x = 0;
	data->map.map_y = 0;
	extension_check(argv[1]);
	read_file_map(argv[1], &data->map);
	data_init(data);
	data->rays = malloc(data->mlx.x_win * sizeof(t_rays));
	if (!data->rays)
		return (free(data), 0);
	setup(data);
	return (0);
}
