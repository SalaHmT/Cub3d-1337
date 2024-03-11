/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Check_Map_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 00:24:26 by shamsate          #+#    #+#             */
/*   Updated: 2024/03/11 12:28:52 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

void	extension_check(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] != 'b' || str[i - 1] != 'u' \
	|| str[i - 2] != 'c' || str[i - 3] != '.')
		p_error("Error \nWrong extension :(\n");
}

void	texture_init(t_map *cub3d, char *line, char *texture)
{
	if (line[0] == 'N' && line[1] == 'O')
	{
		if (cub3d->no != NULL)
			p_error("Error: NO texture already defined :(\n");
		cub3d->no = duplicate_string(texture);
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		if (cub3d->so != NULL)
			p_error("Error: SO texture already defined :(\n");
		cub3d->so = duplicate_string(texture);
	}
	else if (line[0] == 'W' && line[1] == 'E')
	{
		if (cub3d->we != NULL)
			p_error("Error: WE texture already defined :(\n");
		cub3d->we = duplicate_string(texture);
	}
	else if (line[0] == 'E' && line[1] == 'A')
	{
		if (cub3d->ea != NULL)
			p_error("Error: EA texture already defined :(\n");
		cub3d->ea = duplicate_string(texture);
	}
}

void	texture_check(char *line, t_map *cub3d)
{
	char	**texture;
	char	*tmp;

	tmp = remove_leading_and_trailing_spaces(line);
	if (line[2] != ' ')
		texture = ft_split(tmp, '\t');
	else
		texture = ft_split(tmp, ' ');
	if (count_string_array(texture) != 2)
		p_error("Error : texture format is wrong :(\n");
	// printf("texture[0] = %s\n", texture[0]);
	// printf("texture[1] = %s\n", texture[1]);
	if (access(texture[1], F_OK) == -1)
	{
		printf("Error : texture file not found :(\n");
		p_error(texture[1]);
	}
	texture_init(cub3d, line, texture[1]);
	free(tmp);
	free_string_array(texture);
}

void	texture_color_check(t_map *cub3d, char *line)
{
	if (line[0] == '\0' || line[0] == '\n')
		return ;
	if (line[0] == 'N' && line[1] == 'O' && (line[2] == ' ' || line[2] == '\t'))
		texture_check(line, cub3d);
	else if (line[0] == 'S' && line[1] == 'O' && \
		(line[2] == ' ' || line[2] == '\t'))
		texture_check(line, cub3d);
	else if (line[0] == 'W' && line[1] == 'E' && \
		(line[2] == ' ' || line[2] == '\t'))
		texture_check(line, cub3d);
	else if (line[0] == 'E' && line[1] == 'A' && \
		(line[2] == ' ' || line[2] == '\t'))
		texture_check(line, cub3d);
	else if (line[0] == 'F' && \
		(line[1] == ' ' || line[1] == '\t'))
		color_check(line, 'F', cub3d);
	else if (line[0] == 'C' && \
		(line[1] == ' ' || line[1] == '\t'))
		color_check(line, 'C', cub3d);
	else if (line[0] == '1')
		map_check(line, cub3d);
	else if (line[0] == '\0')
		return ;
	else
		p_error("Error : Wrong format :(\n");
}

char	*remove_leading_and_trailing_spaces(char *line)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;

	i = 0;
	j = ft_strlen(line) - 2;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	while (line[j] == ' ' || line[j] == '\t')
		j--;
	tmp = malloc(sizeof(char) * (j - i + 2));
	k = 0;
	while (i <= j && line[i] != '\n')
		tmp[k++] = line[i++];
	tmp[k] = '\0';
	return (tmp);
}
