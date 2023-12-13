# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 19:40:22 by ggispert          #+#    #+#              #
#    Updated: 2023/12/13 21:52:58 by ggispert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = srcs/main.c srcs/convert_arg_to_stack.c srcs/init_finish.c \
       srcs/push_swap.c srcs/algorithm_complex.c srcs/algorithm_simple.c \
			 srcs/operation_handler.c  srcs/stack_operations.c \
			 srcs/utils/are_swapable.c srcs/utils/calc_moves.c \
			 srcs/utils/decide_move_flow.c srcs/utils/eval_sort.c \
			 srcs/utils/execute_moves.c srcs/utils/get_index_top_stack.c \
			 srcs/utils/is_sorted.c srcs/utils/operation_conversor.c \
			 srcs/utils/reset_stack.c srcs/utils/split_num.c \
			 srcs/utils/stack_selector.c
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