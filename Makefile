# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osabir <osabir@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 21:08:21 by shamsate          #+#    #+#              #
#    Updated: 2024/03/07 12:10:20 by osabir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3d

INCLUDE = Include/Cub3d.h


CFLAGS	= -Wall -Wextra -Werror
CC = cc
RM = rm -Rf



FILES = main  \
		Dependencies/Get_Next_Line/Get_Next_Line Dependencies/Libft_Function/duplicate_string \
		Dependencies/Libft_Function/ft_atoi Dependencies/Libft_Function/ft_isdigit \
		Dependencies/Libft_Function/ft_strchr Dependencies/Libft_Function/ft_strlen \
		Dependencies/Libft_Function/ft_split Dependencies/Libft_Function/ft_strjoin \
		Parssing/Check_Map_Color Parssing/Check_Map_texture Parssing/Check_Map \
		Parssing/Map_Dependencies Parssing/Map_Init Parssing/Player_Init \
		Parssing/Read_Map_File Dependencies/Get_Next_Line/Get_Next_Line_Depen \
		Dependencies/Libft_Function/ft_strlcpy

SRC		= $(FILES:=.c)
OBJ		= $(FILES:=.o)


all :   $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
		@echo "  - Compilation Starting $(NAME)..\n"
		@ $(CC) -o $(NAME) $(OBJ)
		@echo " - Execution ready..\n"

%.o: %.c $(INCLUDE)
	@echo "- Making Object file $(notdir $@) from source file $(notdir $<)...\n"
	@ $(CC) -Wall -Wextra -Werror  -c $< -o $@

clean:
	@ $(RM) $(OBJ)
	@echo "\n -Removing object file ..\n"
	@echo "-Object file Removed..\n"

fclean: clean
	@ $(RM) $(NAME)
	@echo "-Removing $(NAME) ..\n"
	@echo " Removed..\n"

re: fclean clean

.PHONY: all clean fclean re