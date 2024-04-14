/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:12:09 by zbendahh          #+#    #+#             */
/*   Updated: 2024/03/24 14:12:10 by zbendahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

void    put_pixel(t_mlx *mlx, int x, int y, int color)
{
    mlx->pixel_ptr = mlx->data_addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
    *(unsigned int*)mlx->pixel_ptr = color;
}