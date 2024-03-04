/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:15:49 by shamsate          #+#    #+#             */
/*   Updated: 2024/03/04 17:38:06 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*ft_strchr(char *str, int character)
{
	if (!str)
		return (NULL);
	while (*str != character && *str)
		str++;
	if (*str == (unsigned char)character)
		return (str);
	else
		return (NULL);
}
