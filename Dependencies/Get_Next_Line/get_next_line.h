#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
char	*read_ln(char *str);
char	*ft_get_ln(int fd, char *str);
char	*remove_extracted_line(char *str);
char	*get_next_line(int fd);

#endif