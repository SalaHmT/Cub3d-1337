/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mlx_Put_Pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:12:09 by zbendahh          #+#    #+#             */
/*   Updated: 2024/04/14 12:29:02 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

void	img_pix_put(t_mlx *mlx, int x, int y, int color)
{
	char	*pixel;

	pixel = mlx->addr_ptr + (y * mlx->line_length + x \
		* (mlx->bits_per_pixel / 8));
	*(int *)pixel = color;
}
