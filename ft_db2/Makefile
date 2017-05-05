# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sleung <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/01 10:15:53 by sleung            #+#    #+#              #
#    Updated: 2017/05/05 13:40:51 by sleung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean all index re

NAME = whatisdb
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -o

LLDB = whatisdb.dSYM

INC_DIR =  ./includes
SRC_DIR = ./srcs

SRC_FILES = add_columns.c \
			add_rows.c \
			clear_screen.c \
			copy_rows.c \
			del_column.c \
			del_row.c \
			get_file.c \
			get_schema.c \
			main.c \
			mod_row.c \
			read_schema.c \
			view_schema.c

INC = $(addprefix -I , $(INC_DIR))
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(NAME) $(INC) $(SRCS)
	@echo "\x1B[36m*** Compilation successfully finished ***\033[0m"

clean:
	@echo "\x1B[35m***** Cleaning lldb folder *****\033[0m"
	rm -rf $(LLDB)

fclean: clean
	@echo "\x1B[32m***** Destroying Executable File *****\033[0m"
	rm -f $(NAME)

re: fclean all
