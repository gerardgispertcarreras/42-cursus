/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_args_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 02:54:55 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/02 02:56:01 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

size_t	get_single_quote_length(char const *s)
{
	size_t	i;

	i = 1;
	while (s[i] != '\'')
		++i;
	return (i);
}

size_t	get_double_quote_length(char const *s)
{
	size_t	i;

	i = 1;
	while (s[i] != '\"')
	{
		if (s[i] == '\\')
			++i;
		++i;
	}
	return (i);
}
