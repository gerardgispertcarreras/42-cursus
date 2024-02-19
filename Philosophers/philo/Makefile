# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 10:15:54 by ggispert          #+#    #+#              #
#    Updated: 2024/02/19 11:24:48 by ggispert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCSDIR = srcs/
OBJSDIR = objs/
INCDIR = inc/
AUXDIRS = string_utils/

SRCS = main.c parser.c \
       string_utils/ft_putchar_fd.c string_utils/ft_putendl_fd.c \
       string_utils/ft_putstr_fd.c string_utils/ft_strlen.c 
SRCS := $(addprefix $(SRCSDIR), $(SRCS))
OBJS = $(SRCS:$(SRCSDIR)%.c=$(OBJSDIR)%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCFLAGS = -I$(INCDIR)

RM = rm -rf

$(OBJSDIR)%.o: $(SRCSDIR)%.c Makefile
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

all:
	@$(MAKE) $(NAME) -s

$(NAME): $(OBJSDIR) $(OBJS)
	@echo "Compiling $@"
	$(CC) $(CFLAGS) $(INCFLAGS) $(OBJS) -o $(NAME)

$(OBJSDIR):
	mkdir -p $(OBJSDIR)
	mkdir -p $(addprefix $(OBJSDIR), $(AUXDIRS))

clean:
	@echo "Removing $(OBJSDIR)"
	$(RM) $(OBJSDIR)

fclean:
	@$(MAKE) clean -s
	@echo "Removing $(NAME)"
	$(RM) $(NAME)

re:
	@echo "Recompiling project"
	@$(MAKE) fclean $(NAME) -s

.PHONY: all clean fclean re