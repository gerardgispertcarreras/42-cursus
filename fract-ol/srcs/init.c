/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:21:01 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/13 11:35:57 by ggispert         ###   ########.fr       */
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
}
