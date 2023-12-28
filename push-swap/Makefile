# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 19:40:22 by ggispert          #+#    #+#              #
#    Updated: 2023/12/14 09:35:15 by ggispert         ###   ########.fr        #
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
OBJS = $(SRCS:%.c=%.o)
HEADER = push_swap.h
LIBFT_PATH = $(CURDIR)/Libft
LIBFT = ft
CFLAGS = -Wall -Werror -Wextra 

%.o : %.c $(HEADER)
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) $< -c -o $@

all:
	@$(MAKE) -C Libft -s
	@$(MAKE) $(NAME) -s

$(NAME): $(OBJS) $(LIBFT_PATH)/lib$(LIBFT).a
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) $(OBJS) -o $@ -L$(LIBFT_PATH) -l$(LIBFT)

clean:
	$(MAKE) -C Libft fclean -s
	@find srcs -type f -name "*.o" -exec rm -f {} \;
	@find srcs -type f -name "*.d" -exec rm -f {} \;

fclean:
	$(MAKE) clean -s
	rm -f $(NAME)

re:	
	$(MAKE) fclean all -s

.PHONY: all clean fclean re
