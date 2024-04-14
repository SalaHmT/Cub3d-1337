/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:11:49 by zbendahh          #+#    #+#             */
/*   Updated: 2024/03/24 14:11:50 by zbendahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

void    circle(t_data *data) 
{
    int     y;
    int     x;

    y = data->circle.y - data->circle.radius;
    while (y <= data->circle.y + data->circle.radius)
    {
        x = data->circle.x - data->circle.radius;
        while (x <= data->circle.x + data->circle.radius)
        {
            if ((y - data->circle.y) * (y - data->circle.y) + (x - data->circle.x) * (x - data->circle.x) <= data->circle.radius * data->circle.radius)
                put_pixel(&data->mlx, x, y, data->circle.c_color);
            x++;
        }
        y++;
    }
}