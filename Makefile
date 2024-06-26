# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 15:45:06 by shamsate          #+#    #+#              #
#    Updated: 2024/06/09 16:53:49 by shamsate         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CFLAGS = -Wall -Wextra -Werror -g
DIROBJ = .o
MLX =  -framework Cocoa -framework OpenGL -framework IOKit
CC = cc #-fsanitize=address
RM = rm -Rf
FILES = main \
        dependencies/get_next_line/get_next_line \
		dependencies/libft_function/duplicate_string \
		dependencies/libft_function/ft_strjoin \
		dependencies/libft_function/ft_strlcpy \
        dependencies/libft_function/ft_isdigit \
		dependencies/libft_function/ft_strlen \
        dependencies/libft_function/ft_strchr \
        dependencies/libft_function/ft_split \
		dependencies/libft_function/ft_atoi \
		parssing/check_map_texture \
        parssing/map_dependencies \
        parssing/check_map_color \
		parssing/read_map_file \
		parssing/player_init \
		parssing/check_map \
        parssing/map_init \
		raycasting/cast_ray \
		raycasting/horizontal \
		raycasting/vertical \
		raycasting/player \
		raycasting/keycode \
		raycasting/cast_to_3d \
		raycasting/utils \
		raycasting/setup

SRC = $(FILES:=.c)
OBJ = $(addprefix $(DIROBJ)/, $(FILES:=.o))

all : $(NAME)

$(NAME) : $(OBJ) $(INCLUDE)
	@$(CC) mlx42/libmlx42.a -lglfw -L"/Users/shamsate/.brew/Cellar/glfw/3.4/lib" \
	-I"/Users/shamsate/.brew/Cellar/glfw/3.4/include/GLFW" -o $(NAME) $(OBJ) $(MLX)

$(DIROBJ)/%.o : %.c parssing/parssing.h dependencies/libft_function/libft.h dependencies/get_next_line/get_next_line.h raycasting/raycasting.h
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(DIROBJ)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
