/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:30:17 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/16 20:48:46 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void mandelbrot(t_fractal *fractal, t_data *data)
{
	int	x;
	int y;
	int	i;

	x = -1;
	while (++x < X_SIZE)
	{
		y = -1;
		while (++y < Y_SIZE)
		{
			i = compute_iterations(fractal, x, y);
			my_mlx_pixel_put(data, x, y, compute_color(fractal, i));
		}
	}
}

int		compute_iterations(t_fractal *fractal, int x, int y)
{
	int i;
	t_cmplx	c;
	t_cmplx	z;
	double	tmp;
	
	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = fractal->x + x * (fractal->width / X_SIZE);
	c.y = fractal->y + y * (fractal->height / Y_SIZE);
	while (++i <= fractal->max_iterations && z.x * z.x + z.y * z.y <= THRESHOLD)
	{
		tmp = z.x * z.x - z.y * z.y + c.x;
		z.y = 2.0 * z.x * z.y + c.y;
		z.x = tmp;
	}
	return (i);
}
