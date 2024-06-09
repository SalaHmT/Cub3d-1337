/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:17:52 by shamsate          #+#    #+#             */
/*   Updated: 2024/05/24 03:11:56 by zbendahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *first_string, char *second_string)
{
	int		i ;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	if (!first_string)
	{
		first_string = (char *)malloc(sizeof(char));
		first_string[0] = '\0';
	}
	result = (char *)malloc(sizeof(char) * (ft_strlen(first_string) \
		+ ft_strlen(second_string) + 1));
	if (result == NULL)
		return (NULL);
	while (first_string[i] != '\0')
	{
		result[i] = first_string[i];
		i++;
	}
	while (second_string[j] != '\0')
		result[i++] = second_string[j++];
	result[ft_strlen(first_string) + ft_strlen(second_string)] = '\0';
	free(first_string);
	return (result);
}
