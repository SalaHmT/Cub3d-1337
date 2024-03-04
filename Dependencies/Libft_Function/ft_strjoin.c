/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:17:52 by shamsate          #+#    #+#             */
/*   Updated: 2024/03/04 17:40:01 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
	result = (char *)malloc(sizeof(char) * (strlen(first_string) \
		+ strlen(second_string) + 1));
	if (result == NULL)
		return (NULL);
	while (first_string[i] != '\0')
		result[i] = first_string[i++];
	while (second_string[j] != '\0')
		result[i++] = second_string[j++];
	result[i] = '\0';
	free(first_string);
	return (result);
}
