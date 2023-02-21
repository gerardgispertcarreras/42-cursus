/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:42:53 by ggispert          #+#    #+#             */
/*   Updated: 2023/02/01 20:58:26 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*t;

	i = -1;
	t = NULL;
	while (s[++i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			t = (char *)(s + i);
	}
	if ((unsigned char)c == '\0')
		t = (char *)(s + i);
	return (t);
}
