# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/29 13:04:04 by ggispert          #+#    #+#              #
#    Updated: 2023/07/29 18:27:23 by ggispert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = srcs/ft_printf.c srcs/ft_pointhandl.c srcs/ft_putchar.c srcs/ft_putnbr.c srcs/ft_putstr.c srcs/ft_strlen.c
OBJS = $(SRCS:%.c=%.o)
CFLAGS = -Wall -Werror -Wextra
HEADER = ft_printf.h

%.o : %.c $(HEADER)
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) $< -c -o $@

all:
	@$(MAKE) $(NAME)

$(NAME): $(OBJS)
	@echo "Creating $@"
	@ar -rcs $(NAME) $(OBJS)

$(LIBFT_PATH)/lib$(LIBFT_NAME).a:
	@$(MAKE) -C $(LIBFT_PATH)

clean:
	@echo "Removing libftprintf sources"
	@rm -f ./srcs/*.o 

fclean:
	@$(MAKE) clean
	@rm -f $(NAME)

re:
	@echo "Recompiling"
	@$(MAKE) fclean $(NAME)
