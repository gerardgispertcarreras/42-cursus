# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/28 23:47:03 by ggispert          #+#    #+#              #
#    Updated: 2024/02/02 15:16:35 by ggispert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
SRCS = srcs/main.c srcs/error_utils.c srcs/exec_utils.c srcs/ft_split_args.c srcs/ft_split_args_utils.c
OBJS = $(SRCS:%.c=%.o)
HEADER = pipex.h
LIBFT_PATH = $(CURDIR)/Libft
LIBFT = ft
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

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
	$(RM) $(OBJS)

fclean:
	$(MAKE) clean -s
	$(RM) $(NAME)

re:	
	$(MAKE) fclean all -s

.PHONY: all clean fclean re
