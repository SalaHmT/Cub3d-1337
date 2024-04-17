/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:07:50 by zbendahh          #+#    #+#             */
/*   Updated: 2024/04/15 07:28:43 by zbendahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

void	clear_img(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->mlx.win_size_x)
	{
		j = 0;
		while (j < data->mlx.win_size_y)
		{
			img_pixel_put(&data->mlx, i, j, 0x000000);
			j++;
		}
		i++;
	}
}
