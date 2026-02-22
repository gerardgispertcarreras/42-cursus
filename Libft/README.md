# Libft

A custom C library that reimplements a subset of standard C functions. This is the foundation project of the 42 curriculum — every subsequent project builds on Libft.

## What's Included

### Character & String
- `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_isupper`, `ft_islower`
- `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`
- `ft_strdup`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_strmapi`, `ft_striteri`

### Memory
- `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`
- `ft_calloc`

### Conversion & I/O
- `ft_atoi`, `ft_itoa`
- `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

### Linked List (Bonus)
- `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`, `ft_lstsize`, `ft_lstlast`
- `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

## Build

```bash
make          # Compile libft.a
make bonus    # Include linked list functions
make clean    # Remove object files
make fclean   # Remove objects and library
make re       # Full rebuild
```

## Usage

Link against `libft.a` in your project:

```c
#include "libft.h"

int main(void)
{
    char *s = ft_strjoin("Hello ", "World");
    ft_putendl_fd(s, 1);
    free(s);
    return (0);
}
```

```bash
gcc -I. -L. -lft main.c -o my_program
```
