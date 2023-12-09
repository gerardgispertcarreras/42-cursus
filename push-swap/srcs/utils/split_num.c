/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:26:39 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/09 13:40:43 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
	Evaluate split of a number function
	It moves the number of the block range specified.
	Params:
		A: stack origin.
		B: stack destination.
		pivot_top: threshold number to be moved.
		pivot_bot: threshold number to be moved on the below part.
*/
void split_num(t_stack *A, t_stack *B, int pivot_top, int pivot_bot)
{
	if (A->top->value < pivot_top)
	{
		operate(A, B, "pb");
		if (B->top->value < pivot_bot)
		{
			if (pivot_top > B->size && A->top->value >= pivot_top)
				operate(A, B, "rr");
			else
				operate(A, B, "rb");
		}
	}
	else
	{
		operate(A, B, "ra");
	}
}
