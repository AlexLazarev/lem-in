# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alazarev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/09 15:31:29 by alazarev          #+#    #+#              #
#    Updated: 2018/05/15 18:34:05 by alazarev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_DIR = ./sources/
OBJ_DIR = ./objects/
INC_DIR = ./includes/
LIB_DIR = ./lib/

SRC = get_next_line.c util_setter.c util_getter.c conversion_percent_pointer.c ft_printf.c util.c unicode.c conversion.c conversion_unicode.c\
		ft_bzero.c ft_memcpy.c ft_memccpy.c ft_strcpy.c ft_strcat.c ft_strchr.c \
	  ft_strrchr.c ft_strcmp.c ft_isprint.c ft_strncpy.c ft_strncat.c \
	  ft_isascii.c ft_strncmp.c ft_memchr.c ft_strnstr.c ft_atoi.c \
	  ft_memcmp.c ft_strlen.c ft_strlcat.c ft_memalloc.c ft_memdel.c \
	  ft_strnew.c ft_strdel.c ft_strclr.c ft_strstr.c ft_strmap.c ft_striter.c \
	  ft_striteri.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
	  ft_strjoin.c ft_strtrim.c ft_putchar.c ft_putstr.c ft_putendl.c \
	  ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	  ft_putnbr_fd.c ft_strsplit.c ft_memmove.c ft_strdup.c ft_tolower.c \
	  ft_toupper.c ft_isdigit.c ft_isalnum.c ft_isalpha.c ft_itoa.c ft_memset.c \
	  ft_lstnew.c ft_lstdelone.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
	  ft_lstdel.c ft_strnsplit.c ft_strrvrs.c ft_strrealloc.c ft_error.c \
	  ft_atoi_base.c ft_itoa_base.c ft_ranknumber.c ft_strmasnew.c ft_strndup.c ft_charcount.c ft_strmasfree.c\

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
HEADER_FLAGS = -I $(INC_DIR)
STANDART = -std=c99

CC_FLAGS = -Wall -Wextra -Wextra -O3
CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	ar rc  $(NAME) $(OBJ)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) -c $< -o $@ $(CC_FLAGS) $(STANDART) $(HEADERS_FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re
