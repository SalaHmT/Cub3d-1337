/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:47:07 by shamsate          #+#    #+#             */
/*   Updated: 2024/03/08 13:45:26 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/Cub3d.h"

char	*duplicate_string(const char *src)
{
	int		i;
	int		length;
	char	*dest;

	length = 0;
	while (src[length] != '\0')
		length++;
	dest = malloc(sizeof(char) * (length + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = (char)src[i];
		i++;
	}
	dest[length] = '\0';
	return (dest);
}
