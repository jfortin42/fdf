# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfortin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 10:29:00 by jfortin           #+#    #+#              #
#    Updated: 2016/02/10 18:13:17 by jfortin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

NAME = fdf

SRC = main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		@make -C libft re
		@gcc $(FLAG) -o $(NAME) $(SRC) -lmlx -framework OpenGL -framework AppKit
		@echo "$(NAME) created"

clean:
		@rm -f $(OBJ)
		@echo "$(NAME) OBJ deleted"

fclean: clean
		@rm -f $(NAME)
		@echo "$(NAME) deleted"

re : fclean all

.PHONY: all, clean, fclean, re
