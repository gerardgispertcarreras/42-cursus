/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:27:36 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/10 16:43:32 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
	This function returns the number of rotating moves to bring the num in index
	to the top of the stack. Negative moves are reverse rotating moves.
	Params:
		stack: stack. It must contain the number always.
		index: index of the stack to move.
*/
int	calc_moves_by_index(t_stack *stack, int index)
{
	if (index > stack->size / 2)
		return (index - stack->size);
	return (index);
}

/*
	This function returns the number of rotating moves to bring num to the
	top of the stack. Negative moves are reverse rotating moves.
	Params:
		stack: stack. It must contain the number always.
		num: number to search.
*/
int	calc_moves_by_num(t_stack *stack, int num)
{
	t_node	*node;
	int		i;

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
