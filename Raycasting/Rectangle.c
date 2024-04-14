/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:12:12 by zbendahh          #+#    #+#             */
/*   Updated: 2024/03/24 14:12:13 by zbendahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

void    rectangle(t_data *data)
{
    int     y;
    int     x;

    y = data->rectangle.y;
    while (y < data->rectangle.y + data->rectangle.height)
    {
        x = data->rectangle.x;
        while (x < data->rectangle.x + data->rectangle.width)
            put_pixel(&data->mlx, x++, y, data->rectangle.c_color);
        ++y;
    }
}