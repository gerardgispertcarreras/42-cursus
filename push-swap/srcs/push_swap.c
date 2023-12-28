/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:59:46 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/10 14:01:38 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	This function decides the algorithm to use by size.
	Params:
		a: stack a. (all the number list)
		b: stack b. (empty)
*/
void	push_swap(t_stack *a, t_stack *b)
{
	if (is_sorted(a, 1))
		reset_stack(a, b, 'a', 1);
	else if (a->size <= 8)
		algorithm_simple(a, b);
	else if (a->size <= 12)
		algorithm_complex(a, b, 1);
	else if (a->size <= 50)
		algorithm_complex(a, b, 2);
	else if (a->size <= 200)
		algorithm_complex(a, b, 4);
	else if (a->size <= 1100)
		algorithm_complex(a, b, 8);
	else
		algorithm_complex(a, b, 20);
}
