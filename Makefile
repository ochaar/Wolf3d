# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/07 11:13:09 by prastoin          #+#    #+#              #
#    Updated: 2019/03/15 17:06:52 by ochaar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH)) -I./libft/ -I/usr/local/include

OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = wolf.h

SRC_NAME = main.c ft_verif.c ft_error.c ft_free.c ft_draw.c ft_ray.c menu.c \
ft_detect.c ft_thread.c ft_load_wall.c ft_mini_map.c ft_init.c ft_move.c

FLAG = -Wall -Wextra -Werror

LIB = libft/libft.a

LIBX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
		@gcc $(FLAG) -o $(NAME) $(OBJ) $(LIB) $(INC) $(LIBX)
		@echo "\033[0;31mExecutable wolf3d \033[0m \033[0;32m [OK] \033[0m"

$(LIB):
		@echo "\033[0;33mCompiling...\033[0m"
		@make -C libft/ fclean
		@make -C ./libft/
		@echo "\033[0;34mCompilation libft \033[0m \033[0;32m [OK] \033[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c include/wolf.h
		@mkdir -p $(OBJ_PATH)
		@gcc $(FLAG) $(INC) -o $@ -c $<

clean:
		@make -C libft/ clean
		@rm -rf $(OBJ_PATH)
		@echo "deleted ./obj/"

fclean: clean
		@make -C libft/ fclean
		@rm -rf $(NAME)
		@echo "deleted ./wolf3d"

re: fclean all

.PHONY: clean fclean re all
