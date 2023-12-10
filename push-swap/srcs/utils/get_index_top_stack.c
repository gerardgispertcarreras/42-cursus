/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index_top_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:38:14 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/10 16:53:18 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
	This function searches for the index of the number that should
	be on top of the stack if it was sorted.
	Params:
		stack: stack.
		ascending: if the sorting has to be ascending, 1. 0 otherwise.
*/
int	get_index_top_stack(t_stack *stack, char ascending)
{
	t_node	*node;
	int		i;
	int		top_index;
	int		top_value;

	node = stack->top;
	top_index = 0;
	i = 0;
	top_value = node->value;
	while (node != NULL)
	{
		if (eval_sort(node->value, top_value, ascending))
		{
			top_index = i;
			top_value = node->value;
		}
		node = node->next;
		++i;
	}
	return (top_index);
}
