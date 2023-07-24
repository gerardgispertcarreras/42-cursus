/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointhandl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:24:28 by ggispert          #+#    #+#             */
/*   Updated: 2023/07/15 20:24:12 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_putpointer(unsigned long long x, int *printed, int *error)
{
	int	wr;

	if (x / 16 != 0)
		ft_putpointer(x / 16, printed, error);
	if (*error != -1)
	{
		if (x % 16 < 10)
			wr = write(1, &(char){'0' + x % 16}, 1);
		else
			wr = write(1, &(char){'a' + x % 16 - 10}, 1);
		if (wr == -1)
			*error = -1;
		else
			++(*printed);
	}
}

int	ft_pointhandl(unsigned long long p, int *error)
{
	int	printed;

	printed = write(1, "0x", 2);
	if (printed == -1)
		*error = -1;
	ft_putpointer(p, &printed, error);
	return (printed);
}
