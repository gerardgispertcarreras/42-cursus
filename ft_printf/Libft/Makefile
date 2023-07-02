# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 18:43:48 by ggispert          #+#    #+#              #
#    Updated: 2023/06/27 11:43:20 by ggispert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a
SRCS = 	srcs/ft_isalpha.c srcs/ft_isupper.c srcs/ft_islower.c srcs/ft_isdigit.c srcs/ft_isalnum.c  srcs/ft_isascii.c srcs/ft_isprint.c\
		srcs/ft_strlen.c srcs/ft_memset.c srcs/ft_bzero.c srcs/ft_memcpy.c srcs/ft_memmove.c srcs/ft_strlcpy.c srcs/ft_strlcat.c\
		srcs/ft_toupper.c srcs/ft_tolower.c srcs/ft_strchr.c srcs/ft_strrchr.c srcs/ft_strncmp.c srcs/ft_memchr.c srcs/ft_memcmp.c\
		srcs/ft_strnstr.c  srcs/ft_atoi.c srcs/ft_calloc.c srcs/ft_strdup.c srcs/ft_substr.c srcs/ft_strjoin.c srcs/ft_strtrim.c\
		srcs/ft_split.c srcs/ft_itoa.c srcs/ft_strmapi.c srcs/ft_striteri.c srcs/ft_putchar_fd.c srcs/ft_putstr_fd.c\
		srcs/ft_putendl_fd.c srcs/ft_putnbr_fd.c
SRCS_BONUS = srcs_bonus/ft_lstnew_bonus.c srcs_bonus/ft_lstadd_front_bonus.c srcs_bonus/ft_lstsize_bonus.c srcs_bonus/ft_lstlast_bonus.c\
			 srcs_bonus/ft_lstadd_back_bonus.c srcs_bonus/ft_lstdelone_bonus.c srcs_bonus/ft_lstclear_bonus.c srcs_bonus/ft_lstiter_bonus.c\
			 srcs_bonus/ft_lstmap_bonus.c
OBJS =	$(SRCS:%.c=%.o)
OBJS_BONUS =	$(SRCS_BONUS:.c=.o)
CFLAGS = -Wall -Werror -Wextra
HEADER = libft.h

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

all: 
	$(MAKE) $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

bonus: $(OBJS_BONUS) $(OBJS)
	ar -rcs $(NAME) $(OBJS) $(OBJS_BONUS)
	touch bonus

clean:
	rm -f ./srcs/*.o ./srcs/bonus

fclean:
	$(MAKE) clean
	rm -f $(NAME)

re:	
	$(MAKE) fclean $(NAME)

.PHONY : all clean fclean re
