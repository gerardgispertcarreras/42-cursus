/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:21:01 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/17 17:49:39 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_init(t_fractal *fract)
{
	fract->mlx = mlx_init();
	if (fract->mlx == NULL)
		print_error("ERROR: mlx connection failed.", fract);
	fract->win = mlx_new_window(fract->mlx, X_SIZE, Y_SIZE, "fract-ol");
	if (fract->win == NULL)
		print_error("ERROR: window creation failed.", fract);
	fract->data = malloc(sizeof(t_data));
	if (fract->data == NULL)
		print_error("ERROR: malloc failed.", fract);
	fract->data->img = mlx_new_image(fract->mlx, X_SIZE, Y_SIZE);
	if (fract->data->img == NULL)
		print_error("ERROR: image creation failed.", fract);
	fract->data->addr = mlx_get_data_addr(fract->data->img, &fract->data->bpp,
			&fract->data->line_len, &fract->data->endian);
	if (fract->data->addr == NULL)
		print_error("ERROR: image addressing failed.", fract);
	fract->x = X_MIN;
	fract->y = Y_MIN;
	fract->width = X_MAX - X_MIN;
	fract->height = Y_MAX - Y_MIN;
	fract->color_mode = 1;
	fract->max_iterations = INITIAL_ITERATIONS;
	fract->dx = malloc(X_SIZE * sizeof(double));
	fract->dy = malloc(Y_SIZE * sizeof(double));
	compute_color_palette(fract);
}

void	compute_color_palette(t_fractal *fractal)
{
	int	i;

	fractal->color_palette = malloc(MAX_ITERATIONS * sizeof(double));
	if (!fractal->color_palette)
		print_error("Error: malloc failed", fractal);
	i = -1;
	while (++i < 350)
		fractal->color_palette[i] = (i * 20) % 255 << 16 | (i * 3) % 255 << 8
			| (i * 8) % 255;
}
