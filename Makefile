# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alazarev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/21 19:55:56 by alazarev          #+#    #+#              #
#    Updated: 2018/05/15 19:08:57 by alazarev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC_DIR = ./sources/
OBJ_DIR = ./objects/
INC_DIR = ./includes/
LIB_DIR = ./lib/

SRC = main.c parser.c valid.c util.c list.c init.c algorithm.c  util_path.c\

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT = $(LIBFT_DIR)libftprintf.a
LIBFT_DIR = $(LIB_DIR)libft/
LIBFT_INC = $(LIBFT_DIR)$(INC_DIR)

HEADER_FLAGS = -I $(INC_DIR) $(LIBFT_INC)

CC_FLAGS = -O3 -Wall -Wextra -Werror
CC = gcc

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)

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
