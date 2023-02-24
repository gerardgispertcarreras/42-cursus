/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:32:02 by ggispert          #+#    #+#             */
/*   Updated: 2023/02/21 19:24:54 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	This function recieves a integer c. If c represents an uppercase letter in
	the ascii table, it returns its lowercase letter, c otherwise.
*/

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 'a' - 'A';
	return (c);
}
