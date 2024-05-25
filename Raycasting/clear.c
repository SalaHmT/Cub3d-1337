/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:07:50 by zbendahh          #+#    #+#             */
/*   Updated: 2024/04/20 07:51:55 by zbendahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

void	clear(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->mlx.win_x)
	{
		j = 0;
		while (j < data->mlx.win_y)
			mlx_put_pixel(data->mlx.img_ptr, i, j++, 0x00000000);
		i++;
	}
}
