CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L../ -lftprintf

PRUEBAS_SRC = main.c
PRUEBAS_OBJ = $(PRUEBAS_SRC:.c=.o)

TARGET = main

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(PRUEBAS_OBJ) ../libftprintf.a
	@$(CC) $(CFLAGS) $(PRUEBAS_OBJ) -o $@ $(LDFLAGS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

clean:
	@rm -f $(PRUEBAS_OBJ) $(TARGET)

fclean: clean
	@rm -f ../libftprintf.a

re: fclean all