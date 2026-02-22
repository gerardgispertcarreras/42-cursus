# 42 Barcelona Cursus

All my work from the **42 Barcelona** programming school. This repository contains projects completed during the curriculum, covering systems programming in C, algorithms, Unix concepts, and graphics.

## Projects Overview

| Project | Description | Difficulty |
|---------|-------------|------------|
| [Libft](./Libft) | Custom C library (reimplementation of libc functions) | ⭐ |
| [ft_printf](./ft_printf) | Custom printf implementation with format specifiers | ⭐ |
| [get_next_line](./get_next_line) | Read a file line by line with a static variable | ⭐ |
| [Born2BeRoot](./Born2BeRoot) | System administration & virtualization (Debian) | ⭐⭐ |
| [pipex](./pipex) | **★ Favorite** — Unix pipes, `execve`, process management | ⭐⭐ |
| [push-swap](./push-swap) | **★ Favorite** — Sorting algorithm with limited operations | ⭐⭐ |
| [fract-ol](./fract-ol) | Fractal renderer (Mandelbrot, Julia) with MinilibX | ⭐⭐ |

---

## ★ Favorite Projects

### [push-swap](./push-swap)
A sorting algorithm challenge where you can only use two stacks and a limited set of operations (push, swap, rotate). Features a well-structured, adaptive algorithm that scales from 2 to 1100+ elements with pivot-based partitioning and smart move optimization.

**[→ Read the detailed explanation](./push-swap/README.md)**

### [pipex](./pipex)
Reimplementation of the shell pipe (`|`) behavior. Connects two commands via a pipe, handling `fork`, `execve`, file redirection, and `PATH` resolution. Includes robust argument parsing with quoted strings support.

**[→ Read the detailed explanation](./pipex/README.md)**

---

## Quick Start

Each project has its own `Makefile`. Navigate to a project folder and run:

```bash
make
```

Some projects have additional targets (e.g., `make bonus` for Libft). Check each project's README for specifics.

## Requirements

- **C compiler** (gcc/clang)
- **Make**
- **macOS** for fract-ol (MinilibX uses Cocoa/OpenGL)

## License

42 projects are typically shared for educational purposes. Check individual project headers for authorship.
