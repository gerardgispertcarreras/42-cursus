/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:30:17 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/15 09:10:22 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void mandelbrot(t_fractal *fractal, t_data *data, int max_iterations)
{
	(void)max_iterations;
	t_cmplx	c;
	t_cmplx	z;
	int i;
	int	x;
	int y;
	char diverged;
	double	tmp;

	x = -1;
	while (++x < X_SIZE)
	{
		y = -1;
		while (++y < Y_SIZE)
		{
			i = 0;
			z.x = 0.0;
			z.y = 0.0;
			c.x = fractal->x_min + x * ((fractal->x_max - fractal->x_min) / X_SIZE);
			c.y = fractal->y_min + y * ((fractal->y_max - fractal->y_min) / Y_SIZE);
			diverged = 0;
			while (++i <= MAX_ITERATIONS && !diverged)
			{
				tmp = z.x * z.x - z.y * z.y + c.x;
				z.y = 2.0 * z.x * z.y + c.y;
				z.x = tmp;
				if (z.x * z.x + z.y * z.y > THRESHOLD)
					diverged = 1;
			}
			if (diverged)
			{
				my_mlx_pixel_put(data, x, y, fractal->colors[i - 1]);
			}
			else
				my_mlx_pixel_put(data, x, y, 0x00000000);
		}
	}
}
