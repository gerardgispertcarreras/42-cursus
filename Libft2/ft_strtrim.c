/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:48:03 by ggispert          #+#    #+#             */
/*   Updated: 2023/02/09 16:19:00 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*a;
	size_t	i;
	size_t	j;

	i = -1;
	while (ft_strchr(s1[++i], set))
		;
	j = ft_strlen(s1);
	while (ft_strchr(s1[--j], set))
		;
	j -= i;
	i = 0;
	a = ft_substr(s1, i, j);
	return (a);
}
