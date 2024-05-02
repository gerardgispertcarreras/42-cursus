# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 19:40:22 by ggispert          #+#    #+#              #
#    Updated: 2024/01/29 17:33:46 by ggispert         ###   ########.fr        #
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
LIBFT_NAME = ft
LIBFT =  $(LIBFT_PATH)/lib$(LIBFT_NAME).a
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

%.o : %.c $(HEADER)
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) $< -c -o $@

all:
	@$(MAKE) $(LIBFT) -s
	@$(MAKE) $(NAME) -s

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH) -s

$(NAME): $(LIBFT) $(OBJS)
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) $(OBJS) -o $@ -L$(LIBFT_PATH) -l$(LIBFT_NAME)

clean:
	@$(MAKE) -C $(LIBFT_PATH) fclean -s
	@$(RM) $(OBJS)
	@echo "Removing push-swap object files"

fclean:
	@$(MAKE) clean -s
	@rm -f $(NAME)
	@echo "Removing push-swap executable file"

re:	
	$(MAKE) fclean all -s
	@echo "Recompiled the project"

.PHONY: all clean fclean re
