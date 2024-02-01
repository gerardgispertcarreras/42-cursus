/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:41:26 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/01 13:19:27 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

size_t	get_word_count_args(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	quote_type;

	i = 0;
	j = 0;
	while (s[j] != '\0')
	{
		if (s[j] != c)
		{
			if (j == 0 || s[j - 1] == c)
				++i;
		}
		if (s[j] == '\'' || s[j] == '\"')
		{
			quote_type = s[j];
			++j;
			while ((s[j] != quote_type && s[j] != '\0') || (s[j] == quote_type && s[j - 1] == '\\'))
				++j;
		}
		++j;
	}
	return (i);
}

long	get_word_length_args(char const *s, char c)
{
	long	i;
	char	quote_type;

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

char	**check_split_args(char a, long i, char **p)
{
	if (!a)
		return (p);
	while (i >= 0)
		free(p[i--]);
	free(p);
	return (NULL);
}

int	concat_strings(char **p, char const *s)
{
	int		i;
	char	*tmp;
	char	end;

	if ((s[0] == '\'' || s[0] == '\"'))
		end = s[0];
	else
		end = ' ';
	i = 1;
	while ((s[i] != end && s[i] != '\0') || (s[i] == end && s[i - 1] == '\\'))
		++i;
	if (*p == NULL)
		tmp = "";
	else
		tmp = *p;
	if (end == ' ')
		*p = ft_strjoin(tmp, ft_substr(s, 0, i));
	else
	{
		*p = ft_strjoin(tmp, ft_substr(s, 1, i - 1));
		++i;
	}
	*p = ft_strtrim(*p, "\\");
	ft_putendl_fd(*p, 2);
	return (i);
}

char	**ft_split_args(char const *s, char c)
{
	long	t;
	long	i;
	size_t	j;
	// size_t	len;
	char	**p;

	if (s == NULL)
		return (NULL);
	t = get_word_count_args(s, c);
	ft_putendl_fd(ft_itoa(t), 2);
	p = malloc((t + 1) * sizeof(char *));
	if (p == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < t)
	{
		p[i] = NULL;
		while (s[j] == c)
			++j;
		while(s[j] != c && s[j] != '\0')
			j += concat_strings(&p[i], s + j);
		// if (len > 0)
		// 	p[i++] = ft_substr(s, j, len);
		// if (i > 0 && p[i - 1] == NULL)
		// 	t = -1;
		// j += len + 1;
		++i;
	}
	p[i] = NULL;
	return (check_split_args(t == -1, i, p));
}
