# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: efrank <efrank@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/18 12:15:56 by efrank         #+#    #+#                 #
#    Updated: 2019/04/01 15:53:43 by efrank        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = src/color.c src/control.c src/convert_input.c src/draw.c src/get_input.c \
	  src/helpers.c src/isometric.c src/main.c src/rotate.c
INCLUDES = minilibx_macos
FLAGS = -Wall -Wextra -Werror
LIB = minilibx_macos
OBJECT = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@echo "compiling..."
	@make -C libft/
	@gcc -o $(NAME) $(SRC) libft/libft.a -I $(INCLUDES) -lmlx -L $(LIB) \
		-framework OpenGL -framework AppKit
	@echo "done!"

clean:
	@make clean -C libft/
	@rm -f $(OBJECT)

fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)

re: fclean all
