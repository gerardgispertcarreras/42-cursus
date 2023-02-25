/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:48:03 by ggispert          #+#    #+#             */
/*   Updated: 2023/02/25 17:05:48 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*a;
	size_t	i;
	long	j;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	if (set != NULL && j >= 0)
	{
		while (ft_strchr(set, s1[i]))
			++i;
		while (ft_strchr(set, s1[j]))
			--j;
	}
	a = ft_substr(s1, i, j - i + 1);
	return (a);
}
