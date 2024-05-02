/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:29:04 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/10 16:55:42 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
	This function checks if the stack is sorted.
	Params:
		stack: stack to check.
		ascending: if the sorting has to be ascending, 1. 0 otherwise.
*/
char	is_sorted(t_stack *stack, char ascending)
{
	t_node	*node_current;
	t_node	*node_previous;
	char	edge_found;

	node_previous = stack->top;
	node_current = node_previous->next;
	edge_found = 0;
	if (eval_sort(stack->bot->value, node_previous->value, ascending))
		edge_found = 0;
	else
		edge_found = 1;
	while (node_current != NULL)
	{
		if (!eval_sort(node_previous->value, node_current->value, ascending))
		{
			if (edge_found)
				return (0);
			else
				edge_found = 1;
		}
		node_previous = node_current;
		node_current = node_previous->next;
	}
	return (1);
}
