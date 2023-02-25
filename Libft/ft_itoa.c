/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:30:02 by ggispert          #+#    #+#             */
/*   Updated: 2023/02/25 19:22:07 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_digits(int n)
{
	if (n / 10 == 0)
		return 1;
	return (get_digits(n/10) + 1);
}

char	*ft_itoa(int n)
{
	char	*a;
	int		m;
	int		sig;

	m = get_digits(n);
	if (n < 0)
	{
		sig = -1;
		++m;
	}
	else
		sig = 1;
	a = malloc((m + 1) * sizeof(char));
	if (!a)
		return (NULL);
	a[m] = '\0';
	while (--m >= 0)
	{
		a[m] = (n % 10) * sig + '0';
		n /= 10;
	}
	if (sig == -1)
		a[0] = '-';
	return (a);
}
