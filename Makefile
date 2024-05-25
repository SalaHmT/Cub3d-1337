NAME = cub3d
INCLUDE = Include/Cub3d.h
CFLAGS = -Wall -Wextra -Werror -g
DIROBJ = .o
MLX =  -framework Cocoa -framework OpenGL -framework IOKit
CC = cc -fsanitize=address
RM = rm -Rf
FILES = main \
        Dependencies/Get_Next_Line/Get_Next_Line \
		Dependencies/Libft_Function/duplicate_string \
        Dependencies/Libft_Function/ft_isdigit \
		Dependencies/Libft_Function/ft_atoi\
        Dependencies/Libft_Function/ft_strchr \
		Dependencies/Libft_Function/ft_strlen \
        Dependencies/Libft_Function/ft_split \
		Dependencies/Libft_Function/ft_strjoin \
		Dependencies/Libft_Function/ft_strlcpy \
        Parssing/Check_Map_Color \
		Parssing/Check_Map_texture \
		Parssing/Check_Map \
        Parssing/Map_Dependencies \
		Parssing/Player_Init \
		Raycasting/clear\
        Parssing/Map_Init \
		Parssing/Read_Map_File \
        Raycasting/setup \
		Raycasting/player \
		Raycasting/cast_3d \
		Raycasting/keycode \
		Raycasting/cast_rays \
		Raycasting/vertical_cast \
		Raycasting/horizontal_cast\

SRC = $(FILES:=.c)
OBJ = $(addprefix $(DIROBJ)/, $(FILES:=.o))

all : $(NAME)

$(NAME) : $(OBJ) $(INCLUDE)
	@echo "- Compilation Starting $(NAME)..\n"
	@$(CC) MLX42/build/libmlx42.a -lglfw -L"/Users/shamsate/.brew/Cellar/glfw/3.4/lib" -I"/Users/shamsate/.brew/Cellar/glfw/3.4/include/GLFW" -o $(NAME) $(OBJ) $(MLX)
	@echo "- Execution ready..\n"

$(DIROBJ)/%.o : %.c $(INCLUDE)
	@echo "- Making Object file $(notdir $@) from source file $(notdir $<)...\n"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(DIROBJ)
	@echo "\n- Removing object files ..\n"
	@echo "- Object files Removed..\n"

fclean : clean
	@$(RM) $(NAME)
	@echo "- Removing $(NAME) ..\n"
	@echo "_ Removed..\n"

re : fclean all

.PHONY : all clean fclean re
