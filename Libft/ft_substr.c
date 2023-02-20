/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:35:48 by ggispert          #+#    #+#             */
/*   Updated: 2023/02/07 19:56:32 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*a;
	char	*b;

	a = (char *)s + start;
	b = malloc((len + 1) * sizeof(char));
	if (b == NULL)
		return (NULL);
	ft_strlcpy(b, a, len + 1);
	return (b);
}
