/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 00:24:37 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/12 11:26:09 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_usage()
{
	ft_putstr_fd("Usage: ./fract-ol [mandelbrot | julia]\n", 2);
	exit(EXIT_FAILURE);
}

void mandelbrot(t_data *img, int max_iterations)
{
	t_cmplx	c;
	t_cmplx	z;
	int i;
	int	x;
	int y;
	char diverged;
	double	tmp;

	x = -1;
	while (++x < X_SIZE)
	{
		y = -1;
		while (++y < Y_SIZE)
		{
			i = 0;
			z.x = 0.0;
			z.y = 0.0;
			c.x = X_MIN + x * ((X_MAX - X_MIN) / X_SIZE);
			c.y = Y_MIN + y * ((Y_MAX - Y_MIN) / Y_SIZE);
			diverged = 0;
			while (++i <= max_iterations && !diverged)
			{
				tmp = z.x * z.x - z.y * z.y + c.x;
				z.y = 2.0 * z.x * z.y + c.y;
				z.x = tmp;
				if (z.x * z.x + z.y * z.y > THRESHOLD)
					diverged = 1;
			}
			if (diverged)
			{
				if (i < 10)	
					my_mlx_pixel_put(img, x, y, 0x00FF0000);
				else if (i < 30)
					my_mlx_pixel_put(img, x, y, 0xFFFFFFFF);
				else
					my_mlx_pixel_put(img, x, y, 0xFFFFFFFF);
			}
			else
				my_mlx_pixel_put(img, x, y, 0x00000000);
		}
	}
}

void	draw_fractal(t_data *img, char *fractal_name)
{
	if (!ft_strncmp(fractal_name, "mandelbrot", 11))
		mandelbrot(img, 50);
	else
	{
		ft_usage();
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_vars 	vars;
	t_data	img;

	if (argc != 2)
		ft_usage();
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, X_SIZE, Y_SIZE, "Hello world!");
	img.img = mlx_new_image(vars.mlx, X_SIZE, Y_SIZE);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	draw_fractal(&img, argv[1]);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}