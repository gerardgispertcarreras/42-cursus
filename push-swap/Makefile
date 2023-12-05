# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 19:40:22 by ggispert          #+#    #+#              #
#    Updated: 2023/12/03 16:05:07 by ggispert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = srcs/main.c srcs/convert_arg_to_stack.c srcs/push_swap.c srcs/split_stack.c srcs/reorder.c srcs/t_stack_utils.c  srcs/operations.c
HEADER = push_swap.h
LIBFT_PATH = $(CURDIR)/Libft
LIBFT = ft
CFLAGS = -Wall -Werror -Wextra -g -O0

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