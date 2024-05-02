# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/28 23:47:03 by ggispert          #+#    #+#              #
#    Updated: 2024/02/02 16:29:14 by ggispert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
SRCS = srcs/main.c srcs/error_utils.c srcs/exec_utils.c srcs/ft_split_args.c srcs/ft_split_args_utils.c
OBJS = $(SRCS:%.c=%.o)
HEADER = pipex.h
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

$(NAME): $(OBJS) $(LIBFT)
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) $(OBJS) -o $@ -L$(LIBFT_PATH) -l$(LIBFT_NAME)

clean:
	@$(MAKE) -C $(LIBFT_PATH) fclean -s
	@removed_files=`$(RM) -v $(OBJS) 2>&1`; \
	if [ -n "$$removed_files" ]; then \
		echo "Object files removed."; \
	fi

fclean:
	@$(MAKE) clean -s
	@removed_files=`$(RM) -v $(NAME) 2>&1`; \
	if [ -n "$$removed_files" ]; then \
		echo "Executable removed."; \
	fi

re:	
	@$(MAKE) fclean all -s
	@echo "The program has been recompiled."

.PHONY: all clean fclean re
