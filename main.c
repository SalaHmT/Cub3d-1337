/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:08:18 by shamsate          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/04/14 12:36:34 by shamsate         ###   ########.fr       */
=======
/*   Updated: 2024/03/23 17:50:25 by zbendahh         ###   ########.fr       */
>>>>>>> b10567c01136b06cd4627b58ee4eea32a3c15d00
/*                                                                            */
/* ************************************************************************** */

#include "Include/Cub3d.h"

<<<<<<< HEAD
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
=======
void init_data(t_data *data, t_map map)
{
	data->size = 32;
    data->width = map.map_x * data->size;
    data->heigh = map.map_y * data->size;
	data->player.player_rotation_angle = M_PI / 2;
    data->player.player_move_speed = 2.0;
    data->player.player_rotation_speed = 2 * (M_PI / 180);
    data->player.walk_direction = 0;
    data->player.turn_direction = 0;
>>>>>>> b10567c01136b06cd4627b58ee4eea32a3c15d00
}

int	main(int ac, char **av)
{
<<<<<<< HEAD
=======
	t_map		map;
>>>>>>> b10567c01136b06cd4627b58ee4eea32a3c15d00
	t_data		*data;

	if (ac != 2)
		return (printf("INVALID ARGUMENTS\n"), 1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
<<<<<<< HEAD
	data->map.map_x = 0;
	data->map.map_y = 0;
	extension_check(av[1]);
	read_file_map(av[1], &data->map);
	init_data_first(data, data->map.map_x, data->map.map_y);
=======
	map.map_x = 0;
	map.map_y = 0;
	extension_check(av[1]);
	read_file_map(av[1], &map);
	init_data(data, map);
>>>>>>> b10567c01136b06cd4627b58ee4eea32a3c15d00
	mlx_setup(data);
	return (0);
}