# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 18:43:48 by ggispert          #+#    #+#              #
#    Updated: 2023/08/30 16:42:55 by ggispert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a
SRCS = 	srcs/ft_isalpha.c srcs/ft_isupper.c srcs/ft_islower.c srcs/ft_isdigit.c srcs/ft_isalnum.c  srcs/ft_isascii.c srcs/ft_isprint.c\
				srcs/ft_strlen.c srcs/ft_memset.c srcs/ft_bzero.c srcs/ft_memcpy.c srcs/ft_memmove.c srcs/ft_strlcpy.c srcs/ft_strlcat.c\
				srcs/ft_toupper.c srcs/ft_tolower.c srcs/ft_strchr.c srcs/ft_strrchr.c srcs/ft_strncmp.c srcs/ft_memchr.c srcs/ft_memcmp.c\
				srcs/ft_strnstr.c  srcs/ft_atoi.c srcs/ft_calloc.c srcs/ft_strdup.c srcs/ft_substr.c srcs/ft_strjoin.c srcs/ft_strtrim.c\
				srcs/ft_split.c srcs/ft_itoa.c srcs/ft_strmapi.c srcs/ft_striteri.c srcs/ft_putchar_fd.c srcs/ft_putstr_fd.c\
				srcs/ft_putendl_fd.c srcs/ft_putnbr_fd.c srcs/ft_lstnew_bonus.c srcs/ft_lstadd_front_bonus.c srcs/ft_lstsize_bonus.c srcs/ft_lstlast_bonus.c\
				srcs/ft_lstadd_back_bonus.c srcs/ft_lstdelone_bonus.c srcs/ft_lstclear_bonus.c srcs/ft_lstiter_bonus.c\
				srcs/ft_lstmap_bonus.c srcs/ft_printf.c srcs/ft_pointhandl.c srcs/ft_putchar.c srcs/ft_putnbr.c srcs/ft_putstr.c srcs/ft_strlen.c
OBJS =	$(SRCS:%.c=%.o)
CFLAGS = -Wall -Werror -Wextra
HEADER = libft.h

%.o : %.c $(HEADER)
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) $< -c -o $@

all: 
	@$(MAKE) $(NAME)

$(NAME): $(OBJS)
	@echo "Creating $@"
	@ar -rcs $(NAME) $(OBJS)

clean:
	@echo "Removing libft sources"
	@rm -f ./srcs/*.o

fclean:
	@$(MAKE) clean
	@rm -f $(NAME)

re:	
	$(MAKE) fclean $(NAME)

.PHONY : all clean fclean re
