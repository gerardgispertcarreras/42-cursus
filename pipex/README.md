# pipex

**★ Favorite Project** — Reimplementation of the shell pipe (`|`). Given an input file, two commands, and an output file, pipex connects the two commands with a pipe and redirects stdin/stdout to the files — mimicking `file1 cmd1 | cmd2 file2`.

## Usage

```bash
./pipex infile "cmd1" "cmd2" outfile
```

**Equivalent to:**
```bash
< infile cmd1 | cmd2 > outfile
```

### Examples

```bash
./pipex input.txt "cat" "wc -l" output.txt
# Counts lines: input.txt → cat → wc -l → output.txt

./pipex file.txt "grep hello" "sort -u" result.txt
# Grep then sort unique lines
```

---

## How It Works

### Process Model

```
[Parent]
    │
    ├── fork() → [Child 1]  first_child()
    │               │
    │               ├── stdin  ← infile
    │               └── stdout → pipe write end
    │
    ├── fork() → [Child 2]  second_child()
    │               │
    │               ├── stdin  ← pipe read end
    │               └── stdout → outfile
    │
    └── waitpid() x2
```

1. **Create pipe**: `pipe(pipe_fd)` → `pipe_fd[0]` (read), `pipe_fd[1]` (write).
2. **Fork first child**: Opens `infile`, redirects stdin to it and stdout to `pipe_fd[1]`, closes the read end, then `execve`s `cmd1`.
3. **Fork second child**: Redirects stdin to `pipe_fd[0]` and stdout to `outfile`, closes the write end, then `execve`s `cmd2`.
4. **Parent**: Closes both pipe ends (children have their copies), then `waitpid`s for both children.

### Key Code Flow

**`main.c`** — Setup and process creation:

```c
pipe(pipe_fd);           // Create pipe
child1 = fork();
if (child1 == 0)
    first_child(argv[1], pipe_fd, argv[2], envp);  // infile, pipe, cmd1
child2 = fork();
if (child2 == 0)
    second_child(argv[4], pipe_fd, argv[3], envp); // outfile, pipe, cmd2
// Parent closes pipe ends (important for EOF on read side)
_close(pipe_fd[0]);
_close(pipe_fd[1]);
waitpid(child1, &status, 0);
waitpid(child2, &status, 0);
```

**`first_child`** / **`second_child`** — Redirect and exec:

- First child: `dup2(input_fd, STDIN_FILENO)`, `dup2(pipe_fd[1], STDOUT_FILENO)`, close unused fds, then `exec_child`.
- Second child: `dup2(pipe_fd[0], STDIN_FILENO)`, `dup2(output_fd, STDOUT_FILENO)`, close unused fds, then `exec_child`.

**`exec_child`** — Resolve and run the command:

1. Parse the command string with `ft_split_args` (supports quoted arguments).
2. If the command contains `/` (e.g. `/usr/bin/ls`), call `exec_command_directly` — use it as an absolute path.
3. Otherwise, get `PATH` from `envp`, iterate over each directory, `ft_strjoin(path, cmd)`, and `execve` until one succeeds.
4. If all fail → exit 127 with "command not found".

---

## Argument Parsing: `ft_split_args`

Unlike simple `ft_split` on spaces, this handles **quoted strings** and escape sequences, similar to the shell.

**`ft_split_args.c`**:

- **`get_word_count_args`**: Counts words, skipping over `'...'` and `"..."` and handling `\`.
- **`get_word_length_args`**: Length of the next word, respecting quotes.
- **`copy_word`** + **`trim_excess_arg`**: Copy the word and remove quote characters from the result (quotes are for grouping, not part of the final argument).

**Utils** (`ft_split_args_utils.c`):

- `get_single_quote_length`: Skip until closing `'`.
- `get_double_quote_length`: Skip until closing `"`, treating `\` as escape.

**Example:**
```c
ft_split_args("grep 'hello world'")  →  ["grep", "hello world"]
ft_split_args("echo \"foo\\\"bar\"") →  ["echo", "foo\"bar"]
```

---

## Code Structure

```
pipex/
├── pipex.h
├── srcs/
│   ├── main.c              # fork, pipe, wait; exec_child, first_child, second_child, get_path
│   ├── exec_utils.c        # exec_command_directly, add_slash (PATH)
│   ├── error_utils.c       # _open, _close, ft_error, ft_custom_error
│   ├── ft_split_args.c     # Quoted/escaped argument parsing
│   └── ft_split_args_utils.c
└── Libft/
```

### Error Handling

- **`_open`**: Opens file for read or write (O_RDONLY vs O_WRONLY|O_CREAT|O_TRUNC). Exits on failure.
- **`_close`**: Wraps `close`, exits on error.
- **`ft_error`**: Uses `perror` for system errors.
- **`ft_custom_error`**: Custom messages (e.g. "command not found", "Invalid number of arguments").

### PATH Resolution

- **`get_path`**: Finds `PATH=` in `envp`, splits on `:`, and adds `/` to each directory (e.g. `/usr/bin` → `/usr/bin/`).
- **`add_slash`**: Ensures each path ends with `/` for concatenation with the command name.

---

## Build

```bash
make
```

Requires the bundled Libft (with `ft_split`, `ft_strjoin`, etc.).
