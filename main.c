/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:08:18 by shamsate          #+#    #+#             */
/*   Updated: 2024/03/08 12:28:52 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/Cub3d.h"

 void	print_map(t_map *cub)
 {
    int j = 0;

	while (cub->map[j])
	{
		printf("%s\n", cub->map[j]);
		j++;
	}
 }


int	main(int ac, char **av)
{
	t_map	*cub;
// atexit(v);
	if (ac != 2)
		return (printf("INVALID ARGUMENTS\n"), 1);
	extension_check(av[1]);
	read_file_map(av[1], &cub);
	print_map(cub);
	return (0);
}
