/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:22:34 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/17 12:43:54 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->data->img);
	free(fractal->data);
	mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(0);
}

int	key_handler(int keycode, t_fractal *fractal)
{
	if (keycode == 65307) // Review the keycode
    close_handler(fractal);
	// Review if it scales ok.
	else if (keycode == 65361)
		fractal->x -= fractal->width * 0.05;
	else if (keycode == 65362)
		fractal->y -= fractal->height * 0.05;
	else if (keycode == 65363)
		fractal->x += fractal->width * 0.05;
	else if (keycode == 65364)
		fractal->y += fractal->height * 0.05;
	draw_fractal(fractal, "mandelbrot");
	return(0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;

	if (button == 4)
	{
		fractal->x += 0.15 * fractal->width;
		fractal->width -= 0.3 * fractal->width;
		fractal->y += 0.15 * fractal->height;
		fractal->height -= 0.3 * fractal->height;
		if (fractal->max_iterations < 350)
			fractal->max_iterations += 6;
		draw_fractal(fractal, "mandelbrot");
	}
	if (button == 5)
	{
		fractal->x -= 0.15 * fractal->width;
		fractal->width += 0.3 * fractal->width;
		fractal->y -= 0.15 * fractal->height;
		fractal->height += 0.3 * fractal->height;
		if (fractal->max_iterations > 80)
			fractal->max_iterations -= 6;
		draw_fractal(fractal, "mandelbrot");
	}
	return(0);
}
