/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:29:47 by shamsate          #+#    #+#             */
/*   Updated: 2024/03/07 11:30:15 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/Cub3d.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen_c(src));
	i = -1;
	while (++i < size - 1 && *(src + i) != '\0')
		*(dest + i) = *(src + i);
	*(dest + i) = '\0';
	return (ft_strlen_c(src));
}
