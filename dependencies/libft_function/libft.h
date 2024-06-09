/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:03:05 by shamsate          #+#    #+#             */
/*   Updated: 2024/06/04 15:03:23 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi( char *str);
int		ft_isdigit(char *str);
int		ft_strlen(char *s);
char	**ft_split(const char *s, char c);
char	*ft_strchr(char *str, int character);
char	*ft_strjoin(char *first_string, char *second_string);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

#endif