/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 00:25:16 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/12 11:19:34 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# define X_SIZE 1920
# define Y_SIZE 1080
# define X_MIN -3.0
# define X_MAX 1.5
# define Y_MIN -1.5
# define Y_MAX 1.5
# define THRESHOLD 4.0
# define MAX_ITERATIONS 40000000

# include <math.h>

// # include "minilibx/mlx.h"
# include "minilibx-linux/mlx.h"
# include "Libft/libft.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

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
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	create_trgb(int t, int r, int g, int b);
int	get_t(int trgb);
int	get_r(int trgb);
int	get_g(int trgb);
int	get_b(int trgb);

void	draw_fractal(t_data *img, char *fractal_name);
void	mandelbrot(t_data *img, int max_iterations);

#endif
