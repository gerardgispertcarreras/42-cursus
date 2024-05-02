# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 23:04:59 by ggispert          #+#    #+#              #
#    Updated: 2024/02/17 17:52:59 by ggispert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = srcs/main.c srcs/init.c srcs/events.c srcs/mandelbrot.c srcs/julia.c \
       srcs/parse.c
OBJS = $(SRCS:srcs/%.c=objs/%.o)

SRCSDIR = ./srcs/
OBJSDIR = ./objs/
INCDIR = ./inc/

HEADER = inc/fractol.h

LIBFT_PATH = ./inc/Libft/
LIBFT_NAME = ft
LIBFT = $(LIBFT_PATH)lib$(LIBFT_NAME).a

MINILIBX_PATH = ./inc/minilibx/
MINILIBX_NAME = mlx
MINILIBX = $(MINILIBX_PATH)lib$(MINILIBX_NAME).a

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3

RM = rm -rf

$(OBJSDIR)%.o: $(SRCSDIR)%.c $(HEADER) Makefile
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(MINILIBX_PATH) -I$(LIBFT_PATH) $< -c -o $@

all:
	@$(MAKE) -C $(LIBFT_PATH) -s
	@$(MAKE) -C $(MINILIBX_PATH) -s
	@$(MAKE) $(NAME) -s

$(NAME): $(OBJSDIR) $(OBJS) $(LIBFT) $(MINILIBX)
	@mkdir -p objs
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) $(OBJS) -I$(INCDIR) -I$(MINILIBX_PATH) -I$(LIBFT_PATH) -o $@ -L$(LIBFT_PATH) -l$(LIBFT_NAME) -L$(MINILIBX_PATH) -l$(MINILIBX_NAME) -framework OpenGL -framework AppKit

$(OBJSDIR):
	@mkdir -p $(OBJSDIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH) -s

$(MINILIBX):
	@$(MAKE) -C $(MINILIBX_PATH) -s

clean:
	$(MAKE) -C $(LIBFT_PATH) fclean -s
	$(MAKE) -C $(MINILIBX_PATH) clean -s
	$(RM) $(OBJSDIR)

fclean:
	$(MAKE) clean -s
	$(RM) $(NAME)

re:	
	$(MAKE) fclean all -s

.PHONY: all clean fclean re