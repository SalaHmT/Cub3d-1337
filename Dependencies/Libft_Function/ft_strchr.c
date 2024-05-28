/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:15:49 by shamsate          #+#    #+#             */
/*   Updated: 2024/05/24 03:11:53 by zbendahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
