/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:35:48 by ggispert          #+#    #+#             */
/*   Updated: 2023/02/24 14:39:00 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	n;
	char *a;

	n = ft_strlen(s);
	if (n == 0)
		return (ft_strdup(s));
	if (start > n)
		len = 0;
	else if (n - start < len)
		len = n - start;
	a = malloc ((len + 1) * sizeof(char));
	if (!a)
		return (NULL);
	if (len == 0)
		return (ft_memset(a, '\0', 1));
	ft_strlcpy(a, s + start, len + 1);
	return (a);
}
