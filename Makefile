# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsugita <tsugita@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/17 10:13:20 by kkamashi          #+#    #+#              #
#    Updated: 2021/02/26 13:01:41 by tsugita          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -g # -fsanitize=address
DEPENDENCY_OPTION = -MMD -MP -MF
LIBS_DIR = ./libs

SRCS = main.c \
	$(LIBS_DIR)/get_next_line/get_next_line.c
SRCS += ${shell find ./srcs/initialize -type f -name "*.c"}
SRCS += ${shell find ./srcs/env_list_units -type f -name "*.c"}
SRCS += ${shell find ./srcs/utilities -type f -name "*.c"}
SRCS += ${shell find ./srcs/builtins -type f -name "*.c"}
# SRCS += ${shell find ./srcs/debug -type f -name "*.c"}
SRCS += ${shell find ./srcs/parsing -type f -name "*.c"}
SRCS += ${shell find ./srcs/command_list_units -type f -name "*.c"}
SRCS += ${shell find ./srcs/execution -type f -name "*.c"}
SRCS += ${shell find ./srcs/shell -type f -name "*.c"}
SRCS += ${shell find ./srcs/bin_list_units -type f -name "*.c"}
SRCS += ${shell find ./srcs/error -type f -name "*.c"}

INCLUDE = -I./includes/ \
			-I./libs/get_next_line/ \
			-I./libs/libft/

OBJS = $(SRCS:.c=.o)
DEPS = ${SRCS:.c=.d}
LIBFT = ./libs/libft/libft.a

.c.o:
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDE) -c $(DEPENDENCY_OPTION) ${<:.c=.d} \
	$< -o ${<:.c=.o}

$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libs/libft
	${CC} ${CFLAGS} $(DEBUG) ${OBJS} $(LIBFT) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(MAKE) fclean -C ./libs/libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)
