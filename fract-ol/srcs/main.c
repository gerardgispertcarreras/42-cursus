/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 00:24:37 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/17 17:38:43 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	print_error(char *err_msg, t_fractal *fractal)
{
	ft_putstr_fd(err_msg, 2);
	close_handler(fractal);
}

void	draw_fractal(t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "mandelbrot", 11))
		mandelbrot(fractal, fractal->data);
	if (!ft_strncmp(fractal->name, "julia", 6))
		julia(fractal, fractal->data);
	mlx_put_image_to_window(fractal->mlx, fractal->win,
		fractal->data->img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	check_parameters(argc, argv, &fractal);
	fractal_init(&fractal);
	bind_events(&fractal);
	draw_fractal(&fractal);
	mlx_put_image_to_window(fractal.mlx, fractal.win, fractal.data->img, 0, 0);
	mlx_loop(fractal.mlx);
}
