# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Include directories
INCLUDES = -I../Libft

# Library directories
LIB_DIRS = -L../ -L../Libft

# Libraries to link
LIBS = -lftprintf -lft

# Object files
OBJ_FILES = main.o ../srcs/ft_printf.o

# Build rule
all: main

# Target executable
main: $(OBJ_FILES)
	$(CC) $(CFLAGS)  $(LIB_DIRS) $(OBJ_FILES) $(LIBS) -o $@

# Object file compilation rule
%.o: %.c
	$(CC) $(CFLAGS)  -c $< -o $@

../srcs/%.o: ../srcs/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJ_FILES)

# Full clean rule
fclean: clean
	rm -f main

# Rebuild rule
re: fclean all

.PHONY: all clean fclean re