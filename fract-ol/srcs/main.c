/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 00:24:37 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/17 15:00:16 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_fractal(t_fractal *fractal, char *fractal_name)
{
	if (!ft_strncmp(fractal_name, "mandelbrot", 11))
		mandelbrot(fractal, fractal->data);
	if (!ft_strncmp(fractal_name, "julia", 6))
		julia(fractal, fractal->data);
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->data->img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_fractal 	fractal;

	check_parameters(argc, argv);
	fractal_init(&fractal);
	bind_events(&fractal);
	draw_fractal(&fractal, argv[1]);
	mlx_put_image_to_window(fractal.mlx, fractal.win, fractal.data->img, 0, 0);
	mlx_loop(fractal.mlx);
}
