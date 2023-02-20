/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:56:09 by ggispert          #+#    #+#             */
/*   Updated: 2023/02/09 16:18:58 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	p = malloc((len1 + len2 + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	ft_strlcpy(p, s1, len1 + 1);
	ft_strlcat(p, s2, len1 + len2 + 1);
	return (p);
}
