/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_complex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:14:37 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/09 13:25:38 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Algorithm for more than 8 numbers
	It makes a pseudo sorting splitting the numbers in split_parts
	blocks and reordering them back afterwards.
	Params:
		A: stack with the numbers list.
		B: empty stack.
		split_parts: number of parts for the first sort.
*/
void algorithm_complex(t_stack *A, t_stack *B, int split_parts)
{
	split_stack(A, B, split_parts);
	reorder(A, B);
}

/*
	Splitting stack function
	It splits the stack in the specified number of blocks.
	Params:
		A: stack origin.
		B: stack destination.
		split: number of parts to split x 2.
*/
void split_stack(t_stack *A, t_stack *B, int split)
{
	int pivot_top;
	int pivot_bot;

	while (split > 0)
	{
		pivot_top = A->size / split + B->size;
		pivot_bot = A->size / (split * 2) + B->size;
		while (A->size > 0 && pivot_top > B->size)
			split_num(A, B, pivot_top, pivot_bot);
		--split;
	}
}

/*
	Reorder function
	It reorders the stack B into A. At the end stack A is sorted.
	Params:
		A: stack destination.
		B: stack origin.
*/
void reorder(t_stack *A, t_stack *B)
{
	int i;
	int moves;
	char swap_needed;

	i = B->size;
	while (--i >= 0)
	{
		moves = calc_moves_by_num(B, i);
		swap_needed = execute_moves_complex(A, B, moves, i);
		operate(A, B, "pa");
		if (swap_needed)
		{
			operate(A, B, "sa");
			--i;
		}
	}
}
