# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 19:40:22 by ggispert          #+#    #+#              #
#    Updated: 2023/09/01 11:26:28 by ggispert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = srcs/main.c srcs/push_swap.c srcs/convert_arg_to_stack.c srcs/operations.c
HEADER = push_swap.h
LIBFT_PATH = $(CURDIR)/Libft
LIBFT = ft
CFLAGS = -Wall -Werror -Wextra

all:
	@$(MAKE) $(NAME)
	
$(NAME): $(SRCS) $(LIBFT)
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) $(SRCS) -o $@ -L$(LIBFT_PATH) -l$(LIBFT)

$(LIBFT):
	$(MAKE) -C Libft

clean:
	$(MAKE) -C Libft fclean
	rm -rf srcs/*.o

.PHONY: all