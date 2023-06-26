/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:40:27 by ggispert          #+#    #+#             */
/*   Updated: 2023/04/29 12:34:16 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s2;

	i = -1;
	s2 = (unsigned char *)s;
	while (++i < n)
	{
		if (s2[i] == (unsigned char)c)
			return ((char *)(s + i));
	}
	return (NULL);
}
