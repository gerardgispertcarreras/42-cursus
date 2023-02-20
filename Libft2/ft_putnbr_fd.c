/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:02:17 by ggispert          #+#    #+#             */
/*   Updated: 2023/02/13 19:16:41 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		write(fd, '-', sizeof(char));
		ft_putnbr_fd((n / 10) * -1, fd);
		ft_putchar_fd((n * -1) % 10 + '0', fd);
	}
	else
	{
		if (n / 10 != 0)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		ft_putchar_fd(n % 10 + '0', fd);
	}
}