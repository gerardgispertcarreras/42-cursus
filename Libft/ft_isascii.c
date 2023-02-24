/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:43:18 by ggispert          #+#    #+#             */
/*   Updated: 2023/02/21 19:22:16 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	This function recieves an integer c as entry parameter. It returns 1 if c
	represents a character in the ascii table and 0 otherwise.
*/

#include "libft.h"

int	ft_isascii(int c)
{
	return (c < 128 && c >= 0);
}
