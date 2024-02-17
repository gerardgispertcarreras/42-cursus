/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:25:46 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/16 19:52:55 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int compute_color(t_fractal *fractal, int iter)
{
	if (iter > fractal->max_iterations)
		return (0x00000000);
	if (fractal->color_mode == 1)
	{
		return ((iter * 3) % 255 << 16 | (iter * 20) % 255 << 8 | (iter * 4) % 255);
	}
	return (0);
}