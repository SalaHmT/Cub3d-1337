/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:08:18 by shamsate          #+#    #+#             */
/*   Updated: 2024/03/07 12:44:24 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/Cub3d.h"

// void v()
// {
// 	system("leaks cub3D");
// }

// void	print_map(t_map **cub)
// {
//     int i, j;
//     for (i = 0; i < cub->map_x; i++) {
//         for (j = 0; j < cub->map_y; j++)
// 		{
//             printf("%c ", cub->map[i][j]);
//         }
//         printf("\n");
//     }
// }

int	main(int ac, char **av)
{
	t_map	*cub;
// atexit(v);
	if (ac != 2)
		return (printf("INVALID ARGUMENTS\n"), 1);
	extension_check(av[1]);
	read_file_map(av[1], &cub);
	// print_map(&cub);
	return (0);
}
