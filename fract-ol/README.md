# fract-ol

A fractal renderer using the **MinilibX** graphics library. Renders the Mandelbrot and Julia sets with zoom, pan, and color customization.

## Features

- **Mandelbrot set**: The classic `z = z² + c` fractal
- **Julia set**: Parameterized by mouse position or constants
- **Interactions**: Zoom (scroll), pan (arrow keys), color mode changes
- **Smooth coloring**: Gradient based on iteration count

## Build

Requires **macOS** (MinilibX uses Cocoa/OpenGL). The project includes a bundled MinilibX.

```bash
make          # Compile fractol
make clean    # Remove object files
make fclean   # Full clean
make re       # Rebuild
```

## Usage

```bash
./fractol mandelbrot
./fractol julia [real] [imaginary]   # Optional Julia constants
```

## Controls

| Action | Input |
|--------|-------|
| Zoom in/out | Mouse scroll |
| Pan | Arrow keys |
| Change color mode | Key (see program) |
| Close | ESC or window close |

## Technical Notes

- Uses double-precision math for fractal calculations
- Configurable max iterations (default 200–350)
- Color palette computed at init for performance
