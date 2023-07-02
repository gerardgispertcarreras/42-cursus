# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/29 13:04:04 by ggispert          #+#    #+#              #
#    Updated: 2023/06/27 12:43:03 by ggispert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = srcs/ft_printf.c srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_putnbr.c srcs/ft_pointerHandler.c
OBJS = $(SRCS:%.c=%.o)
CFLAGS = -Wall -Werror -Wextra
HEADER = libftprintf.h

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@ -L../Libft -lft

all:
	$(MAKE) -C Libft/
	$(MAKE) $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -rf ./srcs/*.o 
	rm -rf ./pruebas/a.out ./pruebas/*.o ./pruebas/d ./pruebas/di ./pruebas/diu ./pruebas/main ./pruebas/c ./pruebas/p ./pruebas/s ./pruebas/xX
fclean:
	$(MAKE) clean
re:
	$(MAKE) fclean $(NAME)
