/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:22:34 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/13 11:22:47 by ggispert         ###   ########.fr       */
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
	if (keycode == 65307) // Review the keycode
    close_handler(fractal);
	return(0);
}
