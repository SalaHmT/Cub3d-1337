/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:08:18 by shamsate          #+#    #+#             */
/*   Updated: 2024/03/23 21:41:22 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/Cub3d.h"

// void v(void)
// {
// 	system("leaks Cub3d");
// }

int	main(int ac, char **av)
{
	t_map	cub;
//  atexit(v);
	if (ac != 2)
		return (printf("INVALID ARGUMENTS :(\n"), 1);
	cub.map_x = 0;
	cub.map_y = 0;
	extension_check(av[1]);
	read_file_map(av[1], &cub);
	return (0);
}
