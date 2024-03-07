/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:15:49 by shamsate          #+#    #+#             */
/*   Updated: 2024/03/07 11:26:12 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/Cub3d.h"

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
