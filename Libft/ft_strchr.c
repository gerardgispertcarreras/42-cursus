/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:42:32 by ggispert          #+#    #+#             */
/*   Updated: 2023/02/26 16:20:44 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
	}
	if ((unsigned char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}
