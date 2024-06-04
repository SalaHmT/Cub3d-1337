/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dependencies.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:44:32 by shamsate          #+#    #+#             */
/*   Updated: 2024/05/24 03:29:01 by zbendahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parssing.h"

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

char	*trim_whitespace(char *line)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(line) + 1));
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != ' ')
		{
			str[j] = line[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

int	count_string_array(char **str_array)
{
	int	count;

	count = 0;
	while (str_array[count] != NULL)
		count++;
	return (count);
}

void	free_string_array(char **str_array)
{
	int	i;

	i = 0;
	while (str_array[i] != NULL)
	{
		free(str_array[i]);
		i++;
	}
	free(str_array);
}
