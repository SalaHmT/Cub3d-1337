/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:08:18 by shamsate          #+#    #+#             */
/*   Updated: 2024/03/23 17:50:25 by zbendahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/Cub3d.h"

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
}

int	main(int ac, char **av)
{
	t_map		map;
	t_data		*data;

	if (ac != 2)
		return (printf("INVALID ARGUMENTS\n"), 1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	map.map_x = 0;
	map.map_y = 0;
	extension_check(av[1]);
	read_file_map(av[1], &map);
	init_data(data, map);
	mlx_setup(data);
	return (0);
}