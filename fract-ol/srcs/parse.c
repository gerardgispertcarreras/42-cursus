/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:47:08 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/17 17:58:15 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	usage(void)
{
	ft_putstr_fd("Usage: ./fract-ol [mandelbrot | julia]\n", 2);
	exit(EXIT_FAILURE);
}

double	ft_atof(const char *str)
{
	int		neg;
	double	res;

	neg = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		++str;
	if (*str == '-')
		neg = -1;
	if (*str == '+' || *str == '-')
		++str;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - 48;
		++str;
	}
	if (*str == '.')
	{
		++str;
		res += ft_atof(str) / (pow(10, ft_strlen(str)));
	}
	return (res * neg);
}

void	get_julia_constants(t_fractal *fractal, char **argv)
{
	t_cmplx	c;

	if (argv[2] && argv[3])
	{
		c.x = ft_atof(argv[2]);
		c.y = ft_atof(argv[3]);
		if (c.x < -2.0 || c.x > 2.0 || c.y < -2.0 || c.y > 2.0)
			ft_putstr_fd("The constants must be between -2.0 and 2.0\n", 2);
		else
		{
			fractal->julia_constants->x = c.x;
			fractal->julia_constants->y = c.y;
			return ;
		}
	}
	else
		ft_putstr_fd("Usage: ./fract-ol julia [cx] [cy]\n", 2);
	exit(EXIT_SUCCESS);
}

void	check_parameters(int argc, char **argv, t_fractal *fractal)
{
	(void)fractal;
	if (argc < 2)
		usage();
	if (!ft_strncmp(argv[1], "mandelbrot", 11))
		fractal->name = ft_strdup("mandelbrot");
	else if (!ft_strncmp(argv[1], "julia", 6))
	{
		get_julia_constants(fractal, argv);
		fractal->name = ft_strdup("julia");
	}
	else
		usage();
}
