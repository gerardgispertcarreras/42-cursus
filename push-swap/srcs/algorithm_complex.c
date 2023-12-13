/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_complex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:14:37 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/13 15:18:22 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	This function sorts stacks. Only used for more than 8 numbers in this case.
	Params:
		a: stack with the numbers list.
		b: empty stack.
*/
void	algorithm_complex(t_stack *a, t_stack *b, int split_parts)
{
	split_stack(a, b, split_parts);
	reorder(a, b);
}

/*
	This function splits the stack a in the specified number of blocks
	into stack b. Every block is also sorted in 2 parts.
	Params:
		a: stack a.
		b: stack b.
		split: number of blocks to split the stack.
*/
void	split_stack(t_stack *a, t_stack *b, int split)
{
	int	pivot_top;
	int	pivot_bot;

	while (split > 0)
	{
		pivot_top = a->size / split + b->size;
		pivot_bot = a->size / (split * 2) + b->size;
		while (a->size > 0 && pivot_top > b->size)
			split_num(a, b, pivot_top, pivot_bot);
		--split;
	}
}

/*
	This function reorders the stack b into a.
	Params:
		a: stack destination.
		b: stack origin.
*/
void	reorder(t_stack *a, t_stack *b)
{
	int		i;
	int		moves;

	i = b->size;
	while (--i >= 0)
	{
		moves = calc_moves_by_num(b, i);
		execute_moves_complex(a, b, moves, i);
		operate(a, b, "pa");
		if (a->size > 2 && a->top->value > a->top->next->value)
		{
			operate(a, b, "sa");
			--i;
		}
		if (a->bot->value < a->top->value)
		{
			operate(a, b, "rra");
			if (a->top->value == a->top->next->value - 1)
				--i;
		}
	}
}
