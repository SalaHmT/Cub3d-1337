/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:36:18 by shamsate          #+#    #+#             */
/*   Updated: 2024/03/05 11:51:38 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	if (ft_atoi(str) > 255 || ft_atoi(str) < 0)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}