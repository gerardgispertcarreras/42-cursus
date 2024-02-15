/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:22:34 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/15 16:10:59 by ggispert         ###   ########.fr       */
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
	double x_center = (fractal->x_max + fractal->x_min) / 2.0;
	double y_center = (fractal->y_max + fractal->y_min) / 2.0;
	if (keycode == 65307) // Review the keycode
    close_handler(fractal);
	else if (keycode == 65361)
	{
		fractal->x_min = x_center - (x_center - fractal->x_min) / 0.9;
		fractal->x_max = x_center + (fractal->x_max - x_center) / 1.1;
	}
	else if (keycode == 65362)
	{
		fractal->y_min = y_center - (y_center - fractal->y_min) / 0.9;
		fractal->y_max = y_center + (fractal->y_max - y_center) / 1.1;
	}
	else if (keycode == 65363)
	{
		fractal->x_min = x_center - (x_center - fractal->x_min) * 0.9;
		fractal->x_max = x_center + (fractal->x_max - x_center) * 1.1;
	}
	else if (keycode == 65364)
	{
		fractal->y_min = y_center - (y_center - fractal->y_min) * 0.9;
		fractal->y_max = y_center + (fractal->y_max - y_center) * 1.1;
	}
	draw_fractal(fractal, fractal->data, "mandelbrot");
		mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->data->img, 0, 0);
	return(0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == 1)
	{
		// Calculate the current center point
		double x_center = (fractal->x_max + fractal->x_min) / 2.0;
		double y_center = (fractal->y_max + fractal->y_min) / 2.0;

		// Adjust the boundaries
		fractal->x_min = x_center - (x_center - fractal->x_min) / 1.1;
		fractal->x_max = x_center + (fractal->x_max - x_center) / 1.1;
		fractal->y_min = y_center - (y_center - fractal->y_min) / 1.1;
		fractal->y_max = y_center + (fractal->y_max - y_center) / 1.1;
		draw_fractal(fractal, fractal->data, "mandelbrot");
		mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->data->img, 0, 0);
	}
	if (button == 2)
	{
		// Calculate the current center point
		double x_center = (fractal->x_max + fractal->x_min) / 2.0;
		double y_center = (fractal->y_max + fractal->y_min) / 2.0;

		// Adjust the boundaries
		fractal->x_min = x_center - (x_center - fractal->x_min) * 1.1;
		fractal->x_max = x_center + (fractal->x_max - x_center) * 1.1;
		fractal->y_min = y_center - (y_center - fractal->y_min) * 1.1;
		fractal->y_max = y_center + (fractal->y_max - y_center) * 1.1;
		draw_fractal(fractal, fractal->data, "mandelbrot");
		mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->data->img, 0, 0);
	}
	return(0);
}
