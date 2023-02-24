/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:43:40 by ggispert          #+#    #+#             */
/*   Updated: 2023/02/21 19:21:49 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	This function recieves an integer c as entry parameter. It returns 1 if c
	represents an uppercase letter in the ascii table, 0 otherwise.
*/

#include "libft.h"

int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}
