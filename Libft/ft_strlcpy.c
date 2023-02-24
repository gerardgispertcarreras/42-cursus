/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:48:52 by ggispert          #+#    #+#             */
/*   Updated: 2023/02/21 19:14:50 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	This function recieves a pointer dst, a pointer src and a size_t dstsize. It
	copies at most dstsize - 1 bytes from src to dst and NUL-terminates the
	string. It returns the length of src string.
*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	i;

	srcsize = ft_strlen(src);
	i = -1;
	if (dstsize-- != 0)
	{
		while (++i < dstsize && i < srcsize)
			dst[i] = src[i];
		dst[i] = '\0';
	}
	return (srcsize);
}
