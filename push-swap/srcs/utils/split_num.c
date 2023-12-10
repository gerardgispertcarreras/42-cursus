/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:26:39 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/10 17:04:23 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
	This function checks if the top number in stack a has to be moved to b.
	Params:
		a: stack a.
		b: stack b.
		pivot_top: threshold number to be moved.
		pivot_bot: threshold number to be moved on the below part.
*/
void	split_num(t_stack *a, t_stack *b, int pivot_top, int pivot_bot)
{
	if (a->top->value < pivot_top)
	{
		operate(a, b, "pb");
		if (b->top->value < pivot_bot)
		{
			if (pivot_top > b->size && a->top->value >= pivot_top)
				operate(a, b, "rr");
			else
				operate(a, b, "rb");
		}
	}
	else
	{
		operate(a, b, "ra");
	}
}
