# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pben <pben@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/18 20:38:00 by pben              #+#    #+#              #
#    Updated: 2019/04/18 20:47:16 by pben             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fractol

CFLAGS=#-Wall -Wextra -Werror
FFLAGS= -lXext -lX11 -lm#-framework OpenGL -framework AppKit

SRC_PATH=./src
INC_PATH=./include
MLX_PATH=./minilibx
MLX_PATH=/usr/local/lib
MLX_INC_PATH=/usr/local/include
FT_PATH=./libft


BIN_PATH=./bin

SRC= draw.c fractol.c hook.c init.c
OBJ:= $(addprefix $(BIN_PATH)/,$(SRC:.c=.o))

.PHONY: all clean fclean re

all: $(BIN_PATH) $(NAME)

$(BIN_PATH):
	mkdir -p bin

$(NAME): $(OBJ) $(INC_PATH)/fractol.h
	@make -s -C $(FT_PATH)
	gcc -g -o $@ $(OBJ) -L$(MLX_PATH) -lmlx -I$(MLX_INC_PATH) -L$(FT_PATH) -lft -I$(FT_PATH) $(FFLAGS)

$(BIN_PATH)/%.o: $(SRC_PATH)/%.c
	gcc -g $(CFLAGS) -o $@ -c $< -I$(INC_PATH) -I$(FT_PATH)

clean:
	@make -s -C $(FT_PATH) fclean
	rm -rf $(BIN_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all
