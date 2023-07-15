# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/29 13:04:04 by ggispert          #+#    #+#              #
#    Updated: 2023/07/15 19:20:45 by ggispert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = srcs/ft_printf.c srcs/ft_pointerHandler.c srcs/ft_putchar.c srcs/ft_putnbr.c srcs/ft_putstr.c
OBJS = $(SRCS:%.c=%.o)
CFLAGS = -Wall -Werror -Wextra
HEADER = libftprintf.h
LIBFT_PATH = $(CURDIR)/Libft

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

all:
	$(MAKE) $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_PATH)
	cp $(LIBFT_PATH)/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -rf ./srcs/*.o 

fclean:
	$(MAKE) clean
	rm -f $(NAME)

re:
	$(MAKE) fclean $(NAME)
