# get_next_line

Read a file descriptor line by line. Uses a static buffer to preserve unread data between calls, so it works correctly regardless of `BUFFER_SIZE`.

## How It Works

- Reads from `fd` in chunks of `BUFFER_SIZE` bytes
- Keeps leftover data in a static buffer between calls
- Returns the next line (including the `\n`) or `NULL` on EOF/error
- Configurable via `BUFFER_SIZE` (default: 256)

## Build

This project is a library meant to be included in other projects. The `tester/` folder contains a test harness.

```bash
# From project root - compile with your main
gcc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c your_main.c -o test
```

## Usage

```c
#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Key Concepts

- **Static variable**: Persists across calls to remember unread data
- **Buffer management**: Handles partial lines when `read()` doesn't return a full line
- **Edge cases**: EOF, empty file, multiple file descriptors (with project extension)
