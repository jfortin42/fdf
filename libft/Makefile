# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfortin <jfortin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 10:29:00 by jfortin           #+#    #+#              #
#    Updated: 2019/11/10 17:02:09 by jfortin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############################## BIN #############################################

NAME = libft.a

FLAG = -Wall -Wextra -Werror

SRCS = ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strnjoin.c \
		get_next_line.c \
		ft_error.c


INC_DIR = includes
SRC_DIR = src
BUILD_DIR = obj

OBJS = $(SRCS:.c=.o)
OBJ = $(addprefix $(BUILD_DIR)/,$(OBJS))
DPD = $(OBJ:.o=.d)

override CFLAGS += -Wall -Wextra -Werror -MMD

############################## RULES ###########################################

release:
		@make -j all CFLAGS:="-O2"

all: $(NAME)

$(NAME): $(OBJ)
				ar rc $(NAME) $(OBJ)
				@echo "$(NAME) created"
				@ranlib $(NAME)
				@echo $(NAME) > .gitignore
				@echo "$(NAME) indexed"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c Makefile
				@mkdir -p $(BUILD_DIR)
				gcc $(CFLAGS) -I $(INC_DIR) -c $< -o $@

############################### DEBUG ##########################################

debug:
	${MAKE} -j all CFLAGS:="-DDEBUG -g"

############################## GENERAL #########################################

clean:
		@rm -rf $(BUILD_DIR)
		@echo "libft OBJ deleted"

fclean: clean
		@rm -f $(NAME)
		@echo "$(NAME) deleted"

re : fclean all

.PHONY: all, clean, fclean, re
