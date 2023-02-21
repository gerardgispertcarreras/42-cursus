/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:33:02 by ggispert          #+#    #+#             */
/*   Updated: 2023/02/02 16:06:38 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s3;
	unsigned char	*s4;

	i = -1;
	s3 = (unsigned char *)s1;
	s4 = (unsigned char *)s2;
	while (++i < n && s3[i] == s4[i])
		;
	if (i == n)
		return (0);
	return (s3[i] - s4[i]);
}
