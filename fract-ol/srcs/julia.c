/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:54:56 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/17 17:56:27 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_fractal *fractal, t_data *data)
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
			i = compute_iterations_julia(fractal, fractal->dx[x],
					fractal->dy[y]);
			if (i > fractal->max_iterations)
				my_mlx_pixel_put(data, x, y, 0x00000000);
			else
				my_mlx_pixel_put(data, x, y, fractal->color_palette[i]);
		}
	}
}

int	compute_iterations_julia(t_fractal *fractal, double dx, double dy)
{
	int		i;
	t_cmplx	z;
	t_cmplx	c;
	double	tmp;

	i = 0;
	z.x = fractal->x + dx;
	z.y = fractal->y + dy;
	c.x = fractal->julia_constants->x;
	c.y = fractal->julia_constants->y;
	while (++i <= fractal->max_iterations && z.x * z.x + z.y * z.y <= THRESHOLD)
	{
		tmp = z.x * z.x - z.y * z.y + c.x;
		z.y = 2.0 * z.x * z.y + c.y;
		z.x = tmp;
	}
	return (i);
}
