/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 00:25:16 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/15 16:11:55 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# define X_SIZE 1080
# define Y_SIZE 1080
# define X_MIN -2.5
# define X_MAX 1.5
# define Y_MIN -2.0
# define Y_MAX 2.0
# define THRESHOLD 4.0
# define MAX_ITERATIONS 250

# include <math.h>
# include <stdio.h>

// # include "minilibx/mlx.h"
# include "minilibx-linux/mlx.h"
# include "Libft/libft.h"


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_fractal {
	void	*mlx;
	void	*win;
	t_data	*data;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	int		*colors;
}				t_fractal;

typedef struct s_cmplx {
	double	x;
	double	y;
}				t_cmplx;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

int	main(int argc, char **argv);

// Init
void	usage();
void	check_parameters(int argc, char **argv);
void	bind_events(t_fractal *fractal);
void	fractal_init(t_fractal *fractal);

// Event Handlers
int	close_handler(t_fractal *fractal);
int	key_handler(int keycode, t_fractal *fractal);
int	mouse_handler(int button, int x, int y, t_fractal *fractal);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	create_trgb(int t, int r, int g, int b);
int	get_t(int trgb);
int	get_r(int trgb);
int	get_g(int trgb);
int	get_b(int trgb);

// Fractal calculation
void	draw_fractal(t_fractal *fractal, t_data *data, char *fractal_name);
void	mandelbrot(t_fractal *fractal, t_data *data, int max_iterations);

#endif
