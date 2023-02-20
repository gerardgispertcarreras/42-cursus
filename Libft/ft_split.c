/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:41:26 by ggispert          #+#    #+#             */
/*   Updated: 2023/02/09 17:29:22 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_word_count(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[j] != '\0')
	{
		if (s[j] == c)
		{
			if (j > 0 && s[j - 1] != c)
				++i;
		}
		++j;
	}
	return (i);
}

size_t	get_word_length(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		++i;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	t;
	size_t	i;
	size_t	j;
	size_t	len;
	char **p;

	t = get_word_count(s, c);
	p = malloc((t + 1) * sizeof(char *));
	if (p == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < t)
	{
		len = get_word_length(s[j], c);
		if (len > 0)
			p[i++] = ft_substr(s, j, len);
		j += len + 1;;
	}
	p[i] = NULL;
	return (p);
}