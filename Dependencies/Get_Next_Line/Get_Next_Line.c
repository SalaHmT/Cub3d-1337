/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:07:29 by shamsate          #+#    #+#             */
/*   Updated: 2024/05/24 03:49:41 by zbendahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft_function/libft.h"

char	*ft_get_ln(int fd, char *str)
{
	int		byte_read;
	char	*buff;

	byte_read = 1;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (!ft_strchr(str, '\n') && byte_read)
	{
		byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free (buff);
			return (0);
		}
		buff[byte_read] = '\0';
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

char	*remove_extracted_line(char *str)
{
	int		i;
	int		j;
	int		remaining_length;
	char	*new_str;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!str[i])
	{
		free (str);
		return (0);
	}
	remaining_length = (ft_strlen(str) - i);
	new_str = (char *)malloc(sizeof(char) * (remaining_length + 1));
	if (!new_str)
		return (0);
	i++;
	while (str[i])
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	free (str);
	return (new_str);
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
	str = remove_extracted_line(str);
	return (ln);
}
