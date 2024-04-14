/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Backround.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:07:50 by zbendahh          #+#    #+#             */
/*   Updated: 2024/04/14 12:14:22 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

void	backround(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->mlx.size_x)
	{
		j = 0;
		while (j < data->mlx.size_y)
			img_pix_put(&data->mlx, i, j++, 0x000000);
		i++;
	}
}
