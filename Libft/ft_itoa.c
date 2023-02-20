/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:30:02 by ggispert          #+#    #+#             */
/*   Updated: 2023/02/09 17:49:59 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_digits(int n)
{
	if (n % 10 == 0)
		return 0;
	return (get_digits(n/10) + 1);
}

char	*ft_itoa(int n)
{
	char	*a;
	int		m;

	m = get_digits(n);
	a = malloc((m + 1) * sizeof(char));
	a[m] = '\0';
	while (--m >= 0)
	{
		a[m] = n % 10;
		n /= 10;
	}
	return (a);
}
