# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alazarev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/14 19:26:08 by alazarev          #+#    #+#              #
#    Updated: 2018/05/21 12:20:27 by alazarev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visualisation

SRC_DIR = ./
OBJ_DIR = ./objects/
INC_DIR = ../includes/
LIB_DIR = ../lib/

SRC = draw.c draw_util.c util.c reader.c main.c other.c\

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT = $(LIBFT_DIR)libftprintf.a
LIBFT_DIR = $(LIB_DIR)libft/
LIBFT_INC = $(LIBFT_DIR)$(INC_DIR)

LIBMLX = $(LIB_DIR)libmlx.a

HEADER_FLAGS = -I $(INC_DIR) $(LIBFT_INC)

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
CC_FLAGS = -O3 -Wall -Wextra -Werror
CC = gcc

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(MLX_FLAGS) $(LIBMLX) $(LIBFT) -o $(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADERS_FLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
