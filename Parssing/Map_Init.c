/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map_Init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 00:31:33 by shamsate          #+#    #+#             */
/*   Updated: 2024/03/02 11:15:00 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

void init_struct(t_map *cub)
{
    cub->map = NULL;
    cub->map_y = 0;
    cub->map_x = 0;
    cub->c = -1;
    cub->f = -1;
    cub->no = NULL;
    cub->so = NULL;
    cub->we = NULL;
    cub->ea = NULL;
}
