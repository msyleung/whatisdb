# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sleung <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/01 10:15:53 by sleung            #+#    #+#              #
#    Updated: 2017/04/27 19:04:57 by sleung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean all index re

NAME = whatisdb
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -o

LLDB = whatisdb.dSYM

INC_DIR =  ./includes
SRC_DIR = ./srcs

SRC_FILES = ft_add_save.c \
			ft_welcome_msg.c \
			ft_del.c \
			ft_secure.c \
			ft_error.c \
			ft_view.c \
			ft_mod.c \
			main.c \

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
