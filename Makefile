# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfortin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 10:29:00 by jfortin           #+#    #+#              #
#    Updated: 2016/02/20 19:10:03 by jfortin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

NAME = fdf

SRC = 	main.c \
		parse.c \
		draw.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@make -C libft re
		@gcc $(FLAG) -o $(NAME) $(OBJ) -lmlx -framework OpenGL -framework AppKit libft/libft.a
		@echo "$(NAME) created"

clean:
		@rm -f $(OBJ)
		@echo "$(NAME) OBJ deleted"

fclean: clean
		@rm -f $(NAME)
		@echo "$(NAME) deleted"

re : fclean all

.PHONY: all, clean, fclean, re
