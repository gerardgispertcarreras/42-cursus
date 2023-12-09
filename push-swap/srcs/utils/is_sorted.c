/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:29:04 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/09 13:40:33 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
	Is it sorted function
	It returns True if the stack is sorted. False if not.
	Params:
		stack: stack to check.
*/
char is_sorted(t_stack *stack, char sort_ascending)
{
	t_node *node_current;
	t_node *node_previous;
	char edge_found;

	node_previous = stack->top;
	node_current = node_previous->next;
	edge_found = 0;
	if (evaluate_sorting(stack->bot->value, node_previous->value, sort_ascending))
		edge_found = 0;
	else
		edge_found = 1;
	while (node_current != NULL)
	{
		if (!evaluate_sorting(node_previous->value, node_current->value, sort_ascending))
		{
			if (edge_found)
				return 0;
			else
				edge_found = 1;
		}
		node_previous = node_current;
		node_current = node_previous->next;
	}
	return (1);
}
