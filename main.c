/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:08:18 by shamsate          #+#    #+#             */
/*   Updated: 2024/05/24 18:28:30 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/Cub3d.h"

void	init_var_mlx(t_data *data)
{
	data->mlx.mlx_ptr = NULL;
	data->mlx.img_x = 0;
	data->mlx.img_y = 0;
	data->mlx.win_x = (data->map.map_x * TILE_SIZE);
	data->mlx.win_y = (data->map.map_y * TILE_SIZE);
}

void	init_var_player(t_data *data)
{
	data->player.turn_direction = 0;
	data->player.walk_direction = 0;
	data->player.x_player = (float)(data->map.player_x * TILE_SIZE);
	data->player.y_player = (float)(data->map.player_y * TILE_SIZE);
	data->player.player_rotation_speed = (2 * (PI / 180));
	data->player.player_rotation_angle = (PI / 2);
	data->player.player_move_speed = 2.0;
	data->player.angle = 0.0;
	data->player.prev_x = 0;
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
	init_var_player(data);
	init_var_mlx(data);
	setup(data);
	return (0);
}
