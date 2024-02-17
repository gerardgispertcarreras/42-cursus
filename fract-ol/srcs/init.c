/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:21:01 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/17 12:36:24 by ggispert         ###   ########.fr       */
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

void	print_error(char *err_msg, t_fractal *fractal)
{
	ft_putstr_fd(err_msg, 2);
	free(fractal->mlx);
	free(fractal->win);
	free(fractal->data->img);
	free(fractal->data->addr);
	exit(0);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (fractal->mlx == NULL)
		print_error("An error ocurred connecting to the mlx.", fractal);
	fractal->win = mlx_new_window(fractal->mlx, X_SIZE, Y_SIZE, "fract-ol");
	if (fractal->win == NULL)
		print_error("An error ocurred trying to create the window.", fractal);
	fractal->data = malloc(sizeof(t_data));
		if (fractal->data == NULL)
		print_error("An error ocurred allocating the memory of the image.", fractal);
	fractal->data->img = mlx_new_image(fractal->mlx, X_SIZE, Y_SIZE);
	if (fractal->data->img == NULL)
		print_error("An error ocurred creatint the image.", fractal);
	fractal->data->addr = mlx_get_data_addr(fractal->data->img, &fractal->data->bits_per_pixel, &fractal->data->line_length, 
								&fractal->data->endian);
	if (fractal->data->addr == NULL)
		print_error("An error ocurred addressing the image properties.", fractal);
	fractal->x = X_MIN;
	fractal->y = Y_MIN;
	fractal->width = X_MAX - X_MIN;
	fractal->height = Y_MAX - Y_MIN;
	fractal->color_mode = 1;
	fractal->max_iterations = INITIAL_ITERATIONS;
	fractal->dx = malloc(X_SIZE * sizeof(double));
	fractal->dy = malloc(Y_SIZE * sizeof(double));
}
