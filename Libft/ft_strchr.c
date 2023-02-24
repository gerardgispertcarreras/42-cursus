/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:42:32 by ggispert          #+#    #+#             */
/*   Updated: 2023/02/21 19:38:40 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	This function recieves a pointer s and an integer c. It returns  a pointer
	to the first ocurrence of (char)c.
*/

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
