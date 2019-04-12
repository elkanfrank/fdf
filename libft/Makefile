# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: efrank <efrank@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/10 13:52:34 by efrank         #+#    #+#                 #
#    Updated: 2019/04/01 12:27:21 by efrank        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_putnbr.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr_fd.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_bzero.c ft_memdel.c \
	  ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_memset.c ft_memcpy.c \
	  ft_memccpy.c ft_memmove.c ft_memchr.c ft_memalloc.c ft_strdup.c ft_strchr.c \
	  ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
	  ft_strncat.c ft_strnew.c ft_strmap.c ft_strmapi.c ft_strsub.c ft_strjoin.c \
	  ft_strtrim.c ft_itoa.c ft_strsplit.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
	  ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_atoi.c ft_strcmp.c \
	  ft_strncmp.c ft_memcmp.c ft_strequ.c ft_strnequ.c ft_strlen.c ft_strlcat.c \
	  ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
	  ft_islower.c ft_isupper.c ft_strndup.c get_next_line.c ft_malloc_grid.c \
	  ft_free_arrays.c ft_putfloat.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(SRC)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f *.o

fclean: clean
	@rm -f libft.a

re: fclean all
