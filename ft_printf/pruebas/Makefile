CFLAGS = -Wall -Wextra -Werror

%.o : %.c libftprintf.h
	$(CC) $(CFLAGS) $< -c -o $@

all: c diu xX p main

c: ../srcs/ft_putchar.o ../Libft/srcs/ft_putchar_fd.o c.o
	$(CC) $(CFLAGS) -o $@ $^
diu: ../srcs/ft_putnbr.o ../srcs/ft_putnbr.o diu.o
	$(CC) $(CFLAGS) -o $@ $^
xX: ../srcs/x_format.o ../srcs/X_format.o xX.o
	$(CC) $(CFLAGS) -o $@ $^

p: ../srcs/p_format.o p.o
	$(CC) $(CFLAGS) -o $@ $^
main: main.o ../ft_printf.o ../srcs/ft_putchar.o ../srcs/ft_putnbr.o ../srcs/ft_pointerHandler.o ../srcs/ft_putstr.o ../Libft/srcs/ft_strlen.o 
	$(CC) $(CFLAGS) -o $@ $^