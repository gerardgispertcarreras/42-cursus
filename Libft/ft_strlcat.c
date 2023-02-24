/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:41:38 by ggispert          #+#    #+#             */
/*   Updated: 2023/02/21 19:17:19 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	This function recieves a pointer dst, a pointer src and a size_t dstsize. It
	concatenates dstsize - (length of dst) - 1 bytes from src to dst and
	NUL-terminates the string if dstsize is bigger than the length of dst. It
	returns (length of src) + (length of dst) if it concatenated something,
	otherwise it returns (length of src) + dstsize.
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dstsize <= dlen)
		return (dstsize + slen);
	ft_strlcpy(dst + dlen, src, dstsize - dlen);
	return (dlen + slen);
}
