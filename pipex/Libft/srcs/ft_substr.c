/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:35:48 by ggispert          #+#    #+#             */
/*   Updated: 2023/04/29 12:34:16 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	n;
	char	*a;

	n = ft_strlen(s);
	if (start > n - 1 || n == 0)
		len = 0;
	else if (n - start < len)
		len = n - start;
	a = malloc ((len + 1) * sizeof(char));
	if (!a)
		return (NULL);
	if (len == 0)
		ft_bzero(a, 1);
	else
		ft_strlcpy(a, s + start, len + 1);
	return (a);
}
