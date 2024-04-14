/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map_building.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:11:57 by zbendahh          #+#    #+#             */
/*   Updated: 2024/03/24 14:11:58 by zbendahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

// void    map_building(t_data *data, t_map map)
// {
//     int     i;
//     int     j;

//     i = 0;
//     while (i < map.map_y)
//     {
//         j = 0;
//         while (j < map.map_x)
//         {
//             if (map.map[i][j] == '0')
//     	        draw_rectangle(data->mlx, (t_rectangle){i * data->size, j * data->size, data->size, data->size, 0x9CAFAA});
//             else if (map.map[i][j] == '1')
//     	        draw_rectangle(data->mlx, (t_rectangle){i * data->size, j * data->size, data->size, data->size, 0x824D74});
//             else if (map.map[i][j] == 'S')
//             {
//     	        rectangle(data->(t_rectangle){map.player_y * data->size, map.player_x * data->size, data->size, data->size, 0x9CAFAA});
//                 circle(data->mlx, (t_circle){map.player_y * data->size, map.player_x * data->size, 4, 0xFFFFFF});
//                 line(data->mlx, (t_line){map.player_y * data->size, map.player_x * data->size, 200 , 200, 0xFFFFFF});
//             }
//             j++;
//         }
//         i++;
//     }    
// }