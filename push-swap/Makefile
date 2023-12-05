# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 19:40:22 by ggispert          #+#    #+#              #
#    Updated: 2023/12/05 20:23:20 by ggispert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = srcs/main.c srcs/convert_arg_to_stack.c srcs/temporary.c srcs/ft_error.c srcs/operations.c srcs/push_swap.c srcs/stack_operations.c\
# srcs/split_stack.c srcs/reorder.c srcs/t_stack_utils.c
HEADER = push_swap.h
LIBFT_PATH = $(CURDIR)/Libft
LIBFT = ft
CFLAGS = -Wall -Werror -Wextra -g -O0
# Add the AddressSanitizer flag
ASAN_FLAGS = -fsanitize=address

all:
	@$(MAKE) $(NAME)
	
$(NAME): $(SRCS) $(LIBFT)
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) $(ASAN_FLAGS) $(SRCS) -o $@ -L$(LIBFT_PATH) -l$(LIBFT)

$(LIBFT):
	$(MAKE) -C Libft

clean:
	$(MAKE) -C Libft fclean
	rm -rf srcs/*.o

.PHONY: all