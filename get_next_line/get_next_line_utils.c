/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:14:30 by ggispert          #+#    #+#             */
/*   Updated: 2023/08/04 15:21:20 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*p;
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (s1)
		len1 = ft_strlen(s1);
	else
		len1 = 0;
	if (s2)
		len2 = ft_strlen(s2);
	else
		len2 = 0;
	if (len1 == 0 && len2 == 0)
		return (NULL);
	p = malloc((len1 + len2 + 1) * sizeof(char));
	if (p != NULL)
	{
		i = -1;
		while (++i < len1)
			p[i] = s1[i];
		ft_strlcpy(p + len1, s2, len2 + 1);
	}
	free(s1);
	return (p);
}

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

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size])
		++size;
	return (size);
}
