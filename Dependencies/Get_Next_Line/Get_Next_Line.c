/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get_Next_Line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:07:29 by shamsate          #+#    #+#             */
/*   Updated: 2024/03/08 12:19:09 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/Cub3d.h"

char	*ft_get_ln(int fd, char *str)
{
	char	*buff;
	int		b_read;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	b_read = 1;
	while (!ft_strchr(str, '\n') && b_read)
	{
		b_read = read(fd, buff, BUFFER_SIZE);
		if (b_read == -1)
		{
			free (buff);
			return (0);
		}
		buff[b_read] = '\0';
		str = ft_strjoin(str, buff);
	}
	free (buff);
	return (str);
}

char	*read_ln(char *str)
{
	int		i;
	char	*ln;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	ln = (char *)malloc(sizeof(char) * (i + 1));
	if (!ln)
		return (0);
	i = -1;
	while (str[++i] && str[i] != '\n')
		ln[i] = str[i];
	if (str[i] == '\n')
	{
		ln[i] = str[i];
		i++;
	}
	ln[i] = '\0';
	return (ln);
}

char	*ft_re(char *str)
{
	int		i;
	int		j;
	int		h;
	char	*p;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!str[i])
	{
		free (str);
		return (0);
	}
	h = (ft_strlen(str) - i);
	p = (char *)malloc(sizeof(char) * (h + 1));
	if (!p)
		return (0);
	i++;
	while (str[i])
		p[j++] = str[i++];
	p[j] = '\0';
	free (str);
	return (p);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*ln;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_get_ln(fd, str);
	if (str == NULL)
		return (NULL);
	ln = read_ln(str);
	str = ft_re(str);
	return (ln);
}
