NAME = Cub3d

INCLUDE = Include/Cub3d.h


CFLAGS	= -Wall -Wextra -Werror
CC = cc  -fsanitize=address
RM = rm -Rf



FILES = main \
        Dependencies/Get_Next_Line/Get_Next_Line Dependencies/Libft_Function/duplicate_string \
        Dependencies/Libft_Function/ft_isdigit \
        Dependencies/Libft_Function/ft_strchr Dependencies/Libft_Function/ft_strlen \
        Dependencies/Libft_Function/ft_split Dependencies/Libft_Function/ft_strjoin \
        Parssing/Check_Map_Color Parssing/Check_Map_texture Parssing/Check_Map \
        Parssing/Map_Dependencies  Parssing/Player_Init \
        Parssing/Map_Init Parssing/Read_Map_File Dependencies/Libft_Function/ft_strlcpy \
        Dependencies/Libft_Function/ft_atoi \
        Raycasting/Mlx_setup Raycasting/Mlx_Circle Raycasting/Mlx_Line_DDA Raycasting/Mlx_Rectangle \
		Raycasting/Mlx_Put_Pixel Raycasting/Map_Building Raycasting/Backround\
		Raycasting/Player_building

SRC		= $(FILES:=.c)
OBJ		= $(FILES:=.o)


all :   $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
		@echo "Compilation Starting $(NAME) ..\n"
		@ $(CC) -o $(NAME) $(OBJ)  -lmlx -framework OpenGL -framework AppKit
		@echo ":) Execution ready . ✔️\n"

%.o: %.c $(INCLUDE)
	@echo "Making Object file $(notdir $@) from source file $(notdir $<)...\n"
	@ $(CC) -Wall -Wextra -Werror  -c $< -o $@

clean:
	@ $(RM) $(OBJ)
	@echo "\nRemoving object file ..\n"
	@echo "Object file Removed . ✔️\n"

fclean: clean
	@ $(RM) $(NAME)
	@echo "Removing $(NAME) ..\n"
	@echo "Removed . ✔️\n"

re: fclean clean

.PHONY: all clean fclean re
