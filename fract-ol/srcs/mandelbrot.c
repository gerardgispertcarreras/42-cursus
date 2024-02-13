/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:30:17 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/13 11:30:29 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void mandelbrot(t_data *data, int max_iterations)
{
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
			c.x = X_MIN + x * ((X_MAX - X_MIN) / X_SIZE);
			c.y = Y_MIN + y * ((Y_MAX - Y_MIN) / Y_SIZE);
			diverged = 0;
			while (++i <= max_iterations && !diverged)
			{
				tmp = z.x * z.x - z.y * z.y + c.x;
				z.y = 2.0 * z.x * z.y + c.y;
				z.x = tmp;
				if (z.x * z.x + z.y * z.y > THRESHOLD)
					diverged = 1;
			}
			if (diverged)
			{
				if (i < 10)	
					my_mlx_pixel_put(data, x, y, 0x00FF0000);
				else if (i < 30)
					my_mlx_pixel_put(data, x, y, 0xFFFFFFFF);
				else
					my_mlx_pixel_put(data, x, y, 0xFFFFFFFF);
			}
			else
				my_mlx_pixel_put(data, x, y, 0x00000000);
		}
	}
}
