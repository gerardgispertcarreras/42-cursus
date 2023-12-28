/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:29:59 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/10 12:45:30 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
	This function checks if 2 numbers are sorted.
	Params:
		a: first number.
		b: second number.
		ascending: if the sorting has to be ascending, 1. 0 otherwise.
*/
char	eval_sort(int a, int b, char ascending)
{
	if (ascending)
		return (a < b);
	return (a > b);
}
