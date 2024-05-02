/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 00:25:16 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/17 18:11:23 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define X_SIZE 800
# define Y_SIZE 800
# define X_MIN -2.0
# define X_MAX 2.0
# define Y_MIN -2.0
# define Y_MAX 2.0
# define THRESHOLD 4.0
# define INITIAL_ITERATIONS 200
# define MAX_ITERATIONS 350

# include <math.h>
# include "minilibx/mlx.h"
# include "Libft/libft.h"

typedef struct s_cmplx
{
	double	x;
	double	y;
}				t_cmplx;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_data;

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	t_data	*data;
	double	x;
	double	y;
	double	width;
	double	height;
	int		color_mode;
	int		max_iterations;
	double	*dx;
	double	*dy;
	double	*color_palette;
	char	*name;
	t_cmplx	*julia_constants;
}				t_fractal;

enum
{
	ON_DESTROY = 17
};

int		main(int argc, char **argv);

// Parsing and error handling
void	usage(void);
void	check_parameters(int argc, char **argv, t_fractal *fractal);
void	bind_events(t_fractal *fractal);
void	print_error(char *err_msg, t_fractal *fractal);

// Init
void	fractal_init(t_fractal *fract);
void	compute_color_palette(t_fractal *fractal);

// Event Handlers
int		close_handler(t_fractal *fractal);
int		key_handler(int keycode, t_fractal *fractal);
int		mouse_handler(int button, int x, int y, t_fractal *fractal);


// Fractal calculation
void	draw_fractal(t_fractal *fractal);
void	mandelbrot(t_fractal *fractal, t_data *data);
int		compute_iterations_mandelbrot(t_fractal *fractal, double x, double y);
void	julia(t_fractal *fractal, t_data *data);
int		compute_iterations_julia(t_fractal *fractal, double dx, double dy);
void	compute_scales(t_fractal *fractal, double *dx, double *dy);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
