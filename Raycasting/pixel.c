/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:12:09 by zbendahh          #+#    #+#             */
/*   Updated: 2024/04/15 07:22:52 by zbendahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

void	img_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*pixel;

	pixel = mlx->addr_ptr + \
		(y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(int *)pixel = color;
}
