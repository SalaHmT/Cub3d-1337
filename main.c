/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:08:18 by shamsate          #+#    #+#             */
/*   Updated: 2024/03/08 11:07:54 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/Cub3d.h"



 void	print_map(t_map *cub)
 {
    int j = 0;
	printf("NO: %s\n", cub->no);
	printf("SO: %s\n", cub->so);
	printf("WE: %s\n", cub->we);
	printf("EA: %s\n", cub->ea);
	printf("C: %i\n", cub->c);
	printf("F: %i\n", cub->f);
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
