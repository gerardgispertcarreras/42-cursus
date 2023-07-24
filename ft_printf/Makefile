# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/29 13:04:04 by ggispert          #+#    #+#              #
#    Updated: 2023/07/15 20:30:19 by ggispert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = srcs/ft_printf.c srcs/ft_pointhandl.c srcs/ft_putchar.c srcs/ft_putnbr.c srcs/ft_putstr.c
OBJS = $(SRCS:%.c=%.o)
CFLAGS = -Wall -Werror -Wextra
HEADER = libftprintf.h
LIBFT_PATH = $(CURDIR)/Libft
LIBFT_NAME = ft

%.o : %.c $(HEADER)
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) $< -c -o $@

all:
	@$(MAKE) $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH)
	@cp $(LIBFT_PATH)/lib$(LIBFT_NAME).a $(NAME)
	@echo "Creating $@"
	@ar -rcs $(NAME) $(OBJS)

clean:
	@echo "Removing libftprintf sources"
	@rm -f ./srcs/*.o 

fclean:
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) clean
	@rm -f $(NAME)

re:
	@echo "Recompiling"
	@$(MAKE) fclean $(NAME)
