/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map_Dependencies.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:44:32 by shamsate          #+#    #+#             */
/*   Updated: 2024/02/27 21:56:57 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

char	*space_skip(char *ln)
{
	while (*ln == ' ' || *ln == '\t')
		ln++;
	return (ln);
}

void	p_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(0);
}

char *trim_whitespace(char *line)
{
	int i;
    int start;
    int end;
	int length;
	char *trimmed;

    while (line[start] == ' ' || line[start] == '\t')
        start++;
    while (end > start && (line[end] == ' ' || line[end] == '\t' || line[end] == '\n'))
        end--;
    length = end - start + 1;
    trimmed = (char *)malloc(sizeof(char) * (length + 1));
    i = 0;
    while (start + i <= end)
    {
        trimmed[i] = line[start + i];
        i++;
    }
    trimmed[i] = '\0';
    return (trimmed);
}

int count_string_array(char **str_array)
{
    int count;

	count = 0;
    while (str_array[count] != NULL)
        count++;
    return count;
}

void free_string_array(char **str_array)
{
    int i;

	i = 0;
    while (str_array[i] != NULL)
    {
        free(str_array[i]);
        i++;
    }
    free(str_array);
}


