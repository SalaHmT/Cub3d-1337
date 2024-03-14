/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Read_Map_File.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:28:00 by shamsate          #+#    #+#             */
/*   Updated: 2024/03/14 22:17:56 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

//This function initializes the t_map structure with default values.
void	struct_init(t_map *cub)
{
	cub->map = NULL;
	cub->c = -1;
	cub->f = -1;
	cub->no = NULL;
	cub->so = NULL;
	cub->we = NULL;
	cub->ea = NULL;
	cub->pos_player = '0';
}

void	read_file_map(char *file, t_map *cub3d)
{
	int		fd;
	char	*line;
	char	*line2;

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
