/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get_Next_Line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:07:29 by shamsate          #+#    #+#             */
/*   Updated: 2024/03/07 11:21:24 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/Cub3d.h"

char	*read_ln(int fd, char *backup)
{
	char	*str;
	int		count;

	str = malloc(BUFFER_SIZE + 1 * sizeof(char ));
	if (!str)
		return (str);
	count = 1;
	while (!ft_strchr(backup, '\n') && count != 0)
	{
		count = read(fd, str, BUFFER_SIZE);
		if (count == -1)
			return (free(str), free(backup), NULL);
		str[count] = '\0';
		backup = ft_strjoin_l(backup, str);
	}
	return (free(str), backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*final;

	if (fd < 0 || fd == 1 || fd == 2 || BUFFER_SIZE <= 0)
		return (NULL);
	final = 0;
	backup = read_ln(fd, backup);
	if (!backup)
		return (backup);
	final = get_ln(backup);
	backup = get_sv_and_fr(backup);
	return (final);
}
