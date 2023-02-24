/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:37:56 by ggispert          #+#    #+#             */
/*   Updated: 2023/02/24 13:21:24 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)b;
	while (i < n)
	{
		s[i] = (unsigned char)c;
		++i;
	}
	return (b);
}
