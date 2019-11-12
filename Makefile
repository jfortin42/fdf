# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfortin <jfortin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 10:29:00 by jfortin           #+#    #+#              #
#    Updated: 2019/11/12 02:02:45 by jfortin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############################## BIN #############################################

NAME = fdf

SRCS =	main.c \
		parse.c \
		draw.c \
		calc.c \
		utils.c

INC_DIR = includes
SRC_DIR = src
BUILD_DIR = obj

INC_LIBFT = libft/includes

INC = -I $(INC_DIR) -I $(INC_LIBFT)

OBJS = $(SRCS:.c=.o)
OBJ = $(addprefix $(BUILD_DIR)/,$(OBJS))
DPD = $(OBJ:.o=.d)

override CFLAGS += -Wall -Wextra -Werror -MMD

MLX = -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

############################## RULES ###########################################

release:
		@make -j all CFLAGS:="-O2"

all: $(NAME)

$(NAME): $(OBJ)
		@make -C libft all
		@make -C minilibx_macos all
		gcc $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) -L libft -lft
		@echo $(NAME) > .gitignore
		@echo "$(NAME) created"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c Makefile
		@mkdir -p $(BUILD_DIR)
		gcc $(CFLAGS) $(INC) -c $< -o $@

############################### DEBUG ##########################################

debug:
	${MAKE} -j all CFLAGS:="-D DEBUG -g"

############################## GENERAL #########################################

clean:
		@make clean -C libft
		@Make clean -C minilibx_macos
		@rm -rf $(BUILD_DIR)
		@echo "$(NAME) OBJ deleted"

fclean: clean
		@make fclean -C libft
		@rm -f $(NAME)
		@echo "$(NAME) deleted"

re :
		@make fclean
		@make release

.PHONY: all, clean, fclean, re

-include $(DPD)
