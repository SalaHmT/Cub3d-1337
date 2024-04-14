/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:08:18 by shamsate          #+#    #+#             */
/*   Updated: 2024/04/14 12:36:34 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/Cub3d.h"

// x--> --- y--> |
void	init_data_first(t_data *data, int map_x, int map_y)
{
	data->player.turn_direction = 0;
	data->player.walk_direction = 0;
	data->player.x_player = (data->map.player_x * TILE_SIZE);
	data->player.y_player = (data->map.player_y * TILE_SIZE);
	data->player.player_rotation_speed = (2 * (M_PI / 180));
	data->player.player_rotation_angle = (180);
	data->player.player_move_speed = 3.0;
	data->mlx.size_x = (map_x * TILE_SIZE);
	data->mlx.size_y = (map_y * TILE_SIZE);
}

int	main(int ac, char **av)
{
	t_data		*data;

	if (ac != 2)
		return (printf("INVALID ARGUMENTS\n"), 1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->map.map_x = 0;
	data->map.map_y = 0;
	extension_check(av[1]);
	read_file_map(av[1], &data->map);
	init_data_first(data, data->map.map_x, data->map.map_y);
	mlx_setup(data);
	return (0);
}
