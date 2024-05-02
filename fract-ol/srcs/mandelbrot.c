/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:30:17 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/17 18:09:54 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_fractal *fractal, t_data *data)
{
	int	x;
	int	y;
	int	i;

	compute_scales(fractal, fractal->dx, fractal->dy);
	x = -1;
	while (++x < X_SIZE)
	{
		y = -1;
		while (++y < Y_SIZE)
		{
			i = compute_iterations_mandelbrot(fractal, fractal->dx[x],
				fractal->dy[y]);
			if (i > fractal->max_iterations)
				my_mlx_pixel_put(data, x, y, 0x00000000);
			else
				my_mlx_pixel_put(data, x, y, fractal->color_palette[i]);
		}
	}
}

int	compute_iterations_mandelbrot(t_fractal *fractal, double dx, double dy)
{
	int		i;
	t_cmplx	c;
	t_cmplx	z;
	double	tmp;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = fractal->x + dx;
	c.y = fractal->y + dy;
	while (++i <= fractal->max_iterations && z.x * z.x + z.y * z.y <= THRESHOLD)
	{
		tmp = z.x * z.x - z.y * z.y + c.x;
		z.y = 2.0 * z.x * z.y + c.y;
		z.x = tmp;
	}
	return (i);
}

void	compute_scales(t_fractal *fractal, double *dx, double *dy)
{
	int		i;
	double	scale;

	i = -1;
	scale = (fractal->width / X_SIZE);
	while (++i < X_SIZE)
		dx[i] = i * scale;
	i = -1;
	scale = (fractal->height / Y_SIZE);
	while (++i < X_SIZE)
		dy[i] = i * scale;
}
