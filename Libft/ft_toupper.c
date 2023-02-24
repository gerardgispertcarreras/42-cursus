/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:30:16 by ggispert          #+#    #+#             */
/*   Updated: 2023/02/21 19:25:01 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	This function recieves a integer c. If c represents a lowercase letter in
	the ascii table, it returns its uppercase letter, c otherwise.
*/

#include "libft.h"

int	ft_toupper(int c)
{
	if (ft_islower(c))
		c -= 'a' - 'A';
	return (c);
}
