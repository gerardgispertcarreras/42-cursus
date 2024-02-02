/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:41:26 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/02 02:55:01 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

size_t	get_word_count_args(char const *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[j] != '\0')
	{
		if (s[j] != ' ')
		{
			if (j == 0 || s[j - 1] == ' ')
				++i;
		}
		if (s[j] == '\'')
			j += get_single_quote_length(s + j);
		else if (s[j] == '\"')
			j += get_double_quote_length(s + j);
		if (s[j] == '\\')
			++j;
		++j;
	}
	return (i);
}

void	trim_excess_arg(char *p)
{
	int		gap;
	char	single_quote;
	char	double_quote;

	gap = 0;
	single_quote = 0;
	double_quote = 0;
	while (p[gap] != '\0')
	{
		if (p[gap] == '\'' && !double_quote)
		{
			single_quote = !single_quote;
			++gap;
		}
		else if (p[gap] == '\"' && !single_quote)
		{
			double_quote = !double_quote;
			++gap;
		}
		else if (p[gap] == '\\' && !single_quote)
			++gap;
		p[0] = p[gap];
		++p;
	}
	p[0] = '\0';
}

size_t	get_word_length_args(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i] != ' ' && s[i] != '\0')
	{
		if (s[i] == '\'')
			i += get_single_quote_length(s + i);
		else if (s[i] == '\"')
			i += get_double_quote_length(s + i);
		if (s[i] == '\\')
			++i;
		++i;
	}
	return (i);
}

size_t	copy_word(char **p, char const *s)
{
	size_t	len;

	len = get_word_length_args(s);
	*p = ft_substr(s, 0, len);
	if (*p == NULL)
		ft_custom_error(EXIT_FAILURE, PIPEX, MALLOCERR, NULL);
	trim_excess_arg(*p);
	return (len);
}

char	**ft_split_args(char const *s)
{
	size_t	total_words;
	size_t	word_it;
	size_t	letter_it;
	char	**p;

	total_words = get_word_count_args(s);
	p = malloc((total_words + 1) * sizeof(char *));
	if (p == NULL)
		ft_custom_error(EXIT_FAILURE, PIPEX, MALLOCERR, NULL);
	word_it = 0;
	letter_it = 0;
	while (word_it < total_words)
	{
		while (s[letter_it] == ' ')
			++letter_it;
		letter_it += copy_word(&p[word_it], s + letter_it) + 1;
		++word_it;
	}
	p[word_it] = NULL;
	return (p);
}
