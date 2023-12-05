/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:04:42 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/04 15:19:38 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Evaluate split of a number function
	It moves the number of the block range specified.
	Params:
		A: stack origin.
		B: stack destination.
		pivot_top: threshold number to be moved.
		pivot_bot: threshold number to be moved on the below part.
*/
void	split_num(t_stack *A, t_stack *B, int pivot_top, int pivot_bot)
{
	if (top(A) < pivot_top)
	{
		operate(A, B, "pb");
		if (top(B) < pivot_bot)
		{
			if (pivot_top > B->size && top(A) >= pivot_top)
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

/*
	Splitting stack function
	It splits the stack in the specified number of blocks.
	Params:
		A: stack origin.
		B: stack destination.
		split: number of parts to split x 2.
*/
void	split_stack(t_stack *A, t_stack *B, int split)
{
	int	pivot_top;
	int	pivot_bot;

	while (split > 0)
	{
		pivot_top = size(A) / split + size(B);
		pivot_bot = size(A) / (split * 2) + size(B);
		while (size(A) != 0 && pivot_top > size(B))
			split_num(A, B, pivot_top, pivot_bot);
		--split;
	}
}
