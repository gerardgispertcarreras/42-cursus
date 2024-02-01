/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:41:26 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/01 18:13:08 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// int	get_quote_length(char const *s)
// {
// 	int		i;
// 	char	quote_type;

// 	i = 1;
// 	quote_type = s[0];
// 	while (s[i] != quote_type)
// 		++i;
// 	if (ft_escaped(s, i))
// 		i += get_quote_length(s + i);
// 	return (i);
// }

char is_escaped(char const *s, int i)
{
	int j;
	int escaped;

	j = i;
	escaped = 0;
	while (j > 0 && s[j - 1] == '\\')
	{
		escaped = !escaped;
		--j;
	}
	return (escaped);
}

int get_single_quote_length(char const *s)
{
	int i;

	i = 1;
	while (s[i] != '\'')
		++i;
	return (i);
}

int get_double_quote_length(char const *s)
{
	int i;

	i = 1;
	while (s[i] != '\"')
	{
		if (s[i] == '\\')
			++i;
		++i;
	}
	return (i);
}

size_t get_word_count_args(char const *s)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s[j] != '\0')
	{
		if (s[j] != ' ')
		{
			if (j == 0 || (s[j - 1] == ' ' && !is_escaped(s, j - 1)))
				++i;
		}
		if (s[j] == '\\')
			++j;
		else if (s[j] == '\'')
			j += get_single_quote_length(s + j);
		else if (s[j] == '\"')
			j += get_double_quote_length(s + j);
		++j;
	}
	return (i);
}

long get_word_length_args(char const *s, char c)
{
	long i;
	char quote_type;

	i = 0;
	quote_type = '\0';
	while (s[i] != c && s[i] != '\'' && s[i] != '\"' && s[i] != '\0')
	{
		if (s[i - 1] == '\'' || s[i - 1] == '\"')
		{
			quote_type = s[i - 1];
			++i;
			while (s[i] != quote_type && s[i] != '\0')
				++i;
		}
		++i;
	}
	return (i);
}

char **check_split_args(char a, long i, char **p)
{
	if (!a)
		return (p);
	while (i >= 0)
		free(p[i--]);
	free(p);
	return (NULL);
}

char *ft_check_escaped(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\\')
		{
			ft_strlcpy(s + i, s + i + 1, ft_strlen(s + i + 1) + 1);
		}
		++i;
	}
	return (s);
}

int concat_strings(char **p, char const *s)
{
	int i;

	if (*p == NULL)
		*p = ft_strdup("");
	if (s[0] == '\'')
	{
		i = get_single_quote_length(s) + 1;
		*p = ft_strjoin(*p, ft_substr(s, 1, i - 2));
	}
	else if (s[0] == '\"')
	{
		i = get_double_quote_length(s) + 1;
		*p = ft_strjoin(*p, ft_check_escaped(ft_substr(s, 1, i - 2)));
	}
	else
	{
		i = 0;
		while (s[i] != ' ' && s[i] != '\0' && s[i] != '\'' && s[i] != '\"')
		{
			if (s[i] == '\\')
			{
				*p = ft_strjoin(*p, ft_substr(s, 0, i));
				*p = ft_strjoin(*p, ft_substr(s, i + 1, 1));
				return (i + 2);
			}
			++i;
		}
		*p = ft_strjoin(*p, ft_substr(s, 0, i));
	}
	return (i);
}

char **ft_split_args(char const *s)
{
	long total_words;
	long word_iterator;
	size_t j;
	char **p;

	if (s == NULL)
		return (NULL);
	total_words = get_word_count_args(s);
	p = malloc((total_words + 1) * sizeof(char *));
	if (p == NULL)
		return (NULL); // exit
	word_iterator = 0;
	j = 0;
	while (word_iterator < total_words)
	{
		p[word_iterator] = NULL;
		while (s[j] == ' ')
			++j;
		while (s[j] != ' ' && s[j] != '\0')
			j += concat_strings(&p[word_iterator], s + j);
		// if (word_iterator > 0 && p[word_iterator - 1] == NULL)
		// 	total_words = -1;
		++word_iterator;
	}
	p[word_iterator] = NULL;
	return (check_split_args(total_words == -1, word_iterator, p));
}
