# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/29 13:04:04 by ggispert          #+#    #+#              #
#    Updated: 2023/05/18 18:42:49 by ggispert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = srcs/ft_printf.c
OBJS = $(SRCS:%.c=%.o)
CFLAGS = -Wall -Werror -Wextra
HEADER = libftprintf.h

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

all:
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
