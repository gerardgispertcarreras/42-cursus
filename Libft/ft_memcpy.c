/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:08:00 by ggispert          #+#    #+#             */
/*   Updated: 2023/02/21 19:06:35 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	This function recieves a pointer dst, a pointer src and a size_t n. It copies
	the first n bytes of src on the first n bytes of dst in the same order. It 
	returns a pointer to the first byte of dst. For pointers that overlap it
	should be used ft_memmove.
*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*src2;
	char	*dst2;

	if (dst == src)
		return (dst);
	i = 0;
	src2 = (char *)src;
	dst2 = (char *)dst;
	while (i < n)
	{
		dst2[i] = src2[i];
		++i;
	}
	return (dst);
}
