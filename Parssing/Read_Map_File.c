/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Read_Map_File.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:28:00 by shamsate          #+#    #+#             */
/*   Updated: 2024/03/07 12:25:33 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

void	read_file_map(char *file, t_map **cub3d)
{
	int		fd;
	char	*line;
	char	*line2;
	int		i;

	i = 0;
	struct_init(cub3d);
	fd = open(file, O_RDWR);
	if (fd == -1)
		p_error("Error: Can't open file");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line2 = space_skip(line);
		texture_color_check(cub3d, line2);
		free(line);
	}
	close(fd);
	map_init(cub3d, file);
}
