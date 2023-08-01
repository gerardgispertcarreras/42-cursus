# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/29 19:34:52 by ggispert          #+#    #+#              #
#    Updated: 2023/08/01 20:02:43 by ggispert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = main
HEADER = ../get_next_line.h
SRCS = ../get_next_line.c ../get_next_line_utils.c main.c
CFLAGS = -Wall -Werror -Wextra -g -D BUFFER_SIZE=10

all:
	@$(MAKE) $(NAME)

$(NAME): $(SRCS)
	@echo "Creating $@"
	@$(CC) $(CFLAGS) $(SRCS) -o $@

fclean:
	@rm -rf main

re:
	@echo "Recompiling"
	@$(MAKE) fclean $(NAME)
