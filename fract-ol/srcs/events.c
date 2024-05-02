/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:22:34 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/17 17:38:30 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	bind_events(t_fractal *fractal)
{
	mlx_hook(fractal->win, ON_DESTROY, 0, close_handler, fractal);
	mlx_key_hook(fractal->win, key_handler, fractal);
	mlx_mouse_hook(fractal->win, mouse_handler, fractal);
}

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->data->img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	exit(0);
}

int	key_handler(int keycode, t_fractal *fractal)
{
	if (keycode == 53)
		close_handler(fractal);
	else if (keycode == 123)
		fractal->x -= fractal->width * 0.05;
	else if (keycode == 126)
		fractal->y -= fractal->height * 0.05;
	else if (keycode == 124)
		fractal->x += fractal->width * 0.05;
	else if (keycode == 125)
		fractal->y += fractal->height * 0.05;
	draw_fractal(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		fractal->x += 0.1 * fractal->width;
		fractal->width -= 0.2 * fractal->width;
		fractal->y += 0.1 * fractal->height;
		fractal->height -= 0.2 * fractal->height;
		if (fractal->max_iterations < MAX_ITERATIONS)
			fractal->max_iterations += 1;
		draw_fractal(fractal);
	}
	if (button == 5)
	{
		fractal->x -= 0.1 * fractal->width;
		fractal->width += 0.2 * fractal->width;
		fractal->y -= 0.1 * fractal->height;
		fractal->height += 0.2 * fractal->height;
		if (fractal->max_iterations > INITIAL_ITERATIONS)
			fractal->max_iterations -= 1;
		draw_fractal(fractal);
	}
	return (0);
}
