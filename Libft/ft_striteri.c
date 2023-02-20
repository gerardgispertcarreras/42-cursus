/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:40:03 by ggispert          #+#    #+#             */
/*   Updated: 2023/02/09 20:48:30 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsifned int, char*))
{
	unsigned int	i;
	unsigned int	len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	while (s[i])
	{
		s[i] = (*f)(i, &s[i]);
		++i;
	}
	p[i] = '\0';
	return (p);
}
