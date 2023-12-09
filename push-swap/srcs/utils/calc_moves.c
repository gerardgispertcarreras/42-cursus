/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:27:36 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/09 13:40:12 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int calc_moves_by_index(t_stack *stack, int index)
{
	if (index > stack->size / 2)
		return (index - stack->size);
	return index;
}

/*
	Move calculator function
	It calculates the moves to reach a number in the stack.
	Negative moves are reversed.
	Params:
		B: stack which must have the number.
		n: number to search.
*/
int calc_moves_by_num(t_stack *stack, int num)
{
	t_node *node;
	int i;

	node = stack->top;
	i = 0;
	while (node->value != num)
	{
		++i;
		node = node->next;
	}
	if (i > (stack->size / 2))
		i -= stack->size;
	return (i);
}
