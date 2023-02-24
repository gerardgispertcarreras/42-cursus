/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:53:10 by ggispert          #+#    #+#             */
/*   Updated: 2023/02/21 19:06:34 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	This function recieves a pointer dst, a pointer src and a size_t n. It copies
	the first n bytes of src on the first n bytes of dst in the same order. It 
	returns a pointer to the first byte of dst. It can be used when overlapping.
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*src2;
	char	*dst2;

	if (dst == NULL && src == NULL)
		return (dst);
	src2 = (char *)src;
	dst2 = (char *)dst;
	if (dst <= src)
		ft_memcpy(dst, src, n);
	else
	{
		while (n-- > 0)
		{
			dst2[n] = src2[n];
		}
	}
	return (dst);
}
