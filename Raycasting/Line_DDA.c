/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Line_DDA.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:11:54 by zbendahh          #+#    #+#             */
/*   Updated: 2024/03/24 14:11:55 by zbendahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

void    line_dda(t_data *data)
{
    float   x;
    float   y;
    int     i;
    int     x_int;
    int     y_int;
    int     steps;

    i = 0;
    x_int = data->line.x_last - data->line.x_first;
    y_int = data->line.y_last - data->line.y_first;
    if (abs(x_int) > abs(y_int))
        steps = abs(x_int);
    else
        steps = abs(y_int);
    x = data->line.x_first;
    y = data->line.y_first;
    while (i <= steps)
    {
        put_pixel(&data->mlx, round(x), round(y), data->line.c_color);
        x += (x_int / (float) steps);
        y += (y_int / (float) steps);
        i++;
    }
}