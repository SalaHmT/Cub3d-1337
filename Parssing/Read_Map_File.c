/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Read_Map_File.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:28:00 by shamsate          #+#    #+#             */
/*   Updated: 2024/03/06 17:46:06 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

void	read_file_map(char *file, t_map *cub3d)
{
	int		fd;
	char	*line;
	char	*line2;
	int		i;

	i = 0;
	init_struct(cub3d);
	fd = open(file, O_RDWR);
	if (fd == -1)
		p_error("Error: Can't open file");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line2 = skip_space(line);
		texture_color_check(cub3d, line2);
		free(line);
	}
	close(fd);
	map_init(cub3d, file);
}
