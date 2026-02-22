# ft_printf

A custom implementation of `printf` from the C standard library. Handles variable arguments with `stdarg` and supports common format specifiers.

## Supported Specifiers

| Specifier | Description |
|-----------|-------------|
| `%c` | Single character |
| `%s` | String |
| `%p` | Pointer (hexadecimal) |
| `%d` / `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x` | Unsigned hexadecimal (lowercase) |
| `%X` | Unsigned hexadecimal (uppercase) |
| `%%` | Literal `%` |

## Build

```bash
make          # Creates libftprintf.a
make clean    # Remove object files
make fclean   # Remove objects and library
make re       # Full rebuild
```

## Usage

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s! Number: %d\n", "World", 42);
    ft_printf("Pointer: %p\n", (void *)main);
    return (0);
}
```

Link with: `-L. -lftprintf`
