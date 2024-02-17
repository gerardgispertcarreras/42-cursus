/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:25:46 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/17 14:30:28 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int compute_color(t_fractal *fractal, int iter)
{
	if (iter > fractal->max_iterations)
		return (0x00000000);
	if (fractal->color_mode == 1)
	{
		return (fractal->color_palette[iter]);
	}
	return (0);
}

void compute_color_palette(t_fractal *fractal)
{
	int	i;

	fractal->color_palette = malloc(MAX_ITERATIONS * sizeof(double)); // Protect malloc
	i = -1;
	while (++i < 350)
		fractal->color_palette[i] = (i * 20) % 255 << 16 | (i * 3) % 255 << 8 | (i * 8) % 255;
}