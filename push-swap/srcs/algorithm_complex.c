/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_complex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:14:37 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/10 13:29:55 by ggispert         ###   ########.fr       */
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
	char	swap_needed;

	i = b->size;
	while (--i >= 0)
	{
		moves = calc_moves_by_num(b, i);
		swap_needed = execute_moves_complex(a, b, moves, i);
		operate(a, b, "pa");
		if (swap_needed)
		{
			operate(a, b, "sa");
			--i;
		}
	}
}
