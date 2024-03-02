/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Check_Map_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 00:24:26 by shamsate          #+#    #+#             */
/*   Updated: 2024/02/27 22:04:34 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"


void	check_extension(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] != 'b' || str[i - 1] != 'u' \
	|| str[i - 2] != 'c' || str[i - 3] != '.')
		p_error("Error \nWrong extension");
}
void check_texture_color(t_map *cub3d ,char *line)
{

    if (line[0] == '\0' || line[0] == '\n')
        return;
    if (line[0] == 'N' && line[1] == 'O' && (line[2] == ' ' || line[2] == '\t'))
        check_texture(line, cub3d);
    else if (line[0] == 'S' && line[1] == 'O' && (line[2] == ' ' || line[2] == '\t'))
        check_texture(line, cub3d);
    else if (line[0] == 'W' && line[1] == 'E' && (line[2] == ' ' || line[2] == '\t'))
        check_texture(line, cub3d);
    else if (line[0] == 'E' && line[1] == 'A' && (line[2] == ' ' || line[2] == '\t'))
        check_texture(line, cub3d);
    else if (line[0] == 'F' && (line[1] == ' ' || line[1] == '\t'))
        check_color(line, cub3d, 'F');
    else if (line[0] == 'C' && (line[1] == ' ' || line[1] == '\t'))
        check_color(line, cub3d, 'C');
    else if (line[0] == '1')
        count_map(line, cub3d);

    else if (line[0] == '\0')
        return;

    else
        p_error("Error : Wrong format");
}
void init_texture(t_map *cub3d, char *line, char *texture)
{
    if (line[0] == 'N' && line[1] == 'O')
    {
        if (cub3d->no != NULL)
            p_error("Error: NO texture already defined");
        cub3d->no = duplicate_string(texture);
    }
    else if (line[0] == 'S' && line[1] == 'O')
    {
        if (cub3d->so != NULL)
            p_error("Error: SO texture already defined");
        cub3d->so = duplicate_string(texture);
    }
    else if (line[0] == 'W' && line[1] == 'E')
    {
        if (cub3d->we != NULL)
            p_error("Error: WE texture already defined");
        cub3d->we = duplicate_string(texture);
    }
    else if (line[0] == 'E' && line[1] == 'A')
    {
        if (cub3d->ea != NULL)
            p_error("Error: EA texture already defined");
        cub3d->ea = duplicate_string(texture);
    }
}

void	check_texture(char *line, t_map *cub3d)
{
	int		i;
	char	**texture;
	char	*tmp;

	i = 0;
	tmp = trim_whitespace(line);
	if (line[2] != ' ')
		texture = ft_split(tmp, '\t');
	else
		texture = ft_split(tmp, ' ');
	if (count_string_array(texture) != 2)
		p_error("Error : texture format is wrong");
	if (access(texture[1], F_OK) == -1)
		p_error(texture[1]);
	init_texture(cub3d, line, texture[1]);
	free(tmp);
	free_string_array(texture);
}
