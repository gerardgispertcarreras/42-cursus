/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:41:26 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/02 16:44:43 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

size_t	get_word_count(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[j] != '\0')
	{
		if (s[j] != c)
		{
			if (j == 0 || s[j - 1] == c)
				++i;
		}
		++j;
	}
	return (i);
}

long	get_word_length(char const *s, char c)
{
	long	j;

	j = 0;
	while (s[j] != c && s[j] != '\0')
		++j;
	return (j);
}

char	**check_split(char a, long i, char **p)
{
	if (!a)
		return (p);
	while (i >= 0)
		free(p[i--]);
	free(p);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	long	t;
	long	i;
	size_t	j;
	size_t	len;
	char	**p;

	if (s == NULL)
		return (NULL);
	t = get_word_count(s, c);
	p = malloc((t + 1) * sizeof(char *));
	if (p == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < t)
	{
		len = get_word_length(&s[j], c);
		if (len > 0)
			p[i++] = ft_substr(s, j, len);
		if (i > 0 && p[i - 1] == NULL)
			t = -1;
		j += len + 1;
	}
	p[i] = NULL;
	return (check_split(t == -1, i, p));
}
