/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 00:24:37 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/13 11:36:18 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_fractal(t_data *data, char *fractal_name)
{
	if (!ft_strncmp(fractal_name, "mandelbrot", 11))
		mandelbrot(data, 50);
}

int	main(int argc, char **argv)
{
	t_fractal 	fractal;

	check_parameters(argc, argv);
	fractal.mlx = mlx_init();
	fractal.win = mlx_new_window(fractal.mlx, X_SIZE, Y_SIZE, "fract-ol");
	fractal.data = malloc(sizeof(t_data));
	fractal.data->img = mlx_new_image(fractal.mlx, X_SIZE, Y_SIZE);
	fractal.data->addr = mlx_get_data_addr(fractal.data->img, &fractal.data->bits_per_pixel, &fractal.data->line_length, 
								&fractal.data->endian);
	bind_events(&fractal);
	draw_fractal(fractal.data, argv[1]);
	mlx_put_image_to_window(fractal.mlx, fractal.win, fractal.data->img, 0, 0);
	mlx_loop(fractal.mlx);
}
