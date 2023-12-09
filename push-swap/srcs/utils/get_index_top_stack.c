/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index_top_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:38:14 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/09 13:40:27 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int get_index_top_stack(t_stack *stack, char sort_ascending)
{
	t_node *node;
	int i;
	int top_index;
	int top_value;

	node = stack->top;
	top_index = 0;
	i = 0;
	top_value = node->value;
	while (node != NULL)
	{
		if (evaluate_sorting(node->value, top_value, sort_ascending))
		{
			top_index = i;
			top_value = node->value;
		}
		node = node->next;
		++i;
	}
	return (top_index);
}
