/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:21:01 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/15 16:15:05 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	usage()
{
	ft_putstr_fd("Usage: ./fract-ol [mandelbrot | julia]\n", 2);
	exit(EXIT_FAILURE);
}

void	check_parameters(int argc, char **argv)
{
	if (argc < 2)
		usage();
	if (ft_strncmp(argv[1], "mandelbrot", 11))
		usage();
}

void	bind_events(t_fractal *fractal)
{
	mlx_hook(fractal->win, ON_DESTROY, 0, close_handler, fractal);
	mlx_key_hook(fractal->win, key_handler, fractal);
	mlx_mouse_hook(fractal->win, mouse_handler, fractal);
}

void	fractal_init(t_fractal *fractal)
{
	int	i;

	fractal->x_min = X_MIN;
	fractal->x_max = X_MAX;
	fractal->y_min = Y_MIN;
	fractal->y_max = Y_MAX;
	fractal->colors = malloc(MAX_ITERATIONS * (sizeof(int)));
	i = 0;
	while (i < MAX_ITERATIONS - 5)
	{
		fractal->colors[i] = (0xFF << 24 | i % 0xFF << 16 | 0x00 << 8 | 0x00);
		i++;
	}
	while (i < MAX_ITERATIONS)
	{
		fractal->colors[i] = (0xFF << 24 | i % 0xFF << 16 | 0xFF << 8 | 0xFF);
		i++;
	}
}
