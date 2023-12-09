/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_swapable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:42:34 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/09 13:43:12 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	search_swap(t_stack *stack, char sort_ascending)
{
	t_node	*node;
	int		index;
	
	node = stack->top;
	index = 0;
	while (node->next != NULL)
	{
		if (are_swapable(node->value, node->next->value, stack, sort_ascending))
			return (index);
		++index;
		node = node->next;
	}
	if (are_swapable(node->value, stack->top->value, stack, sort_ascending))
		return (stack->size - 1);
	return (-1);
}

char	are_swapable(int a, int b, t_stack *stack, char sort_ascending)
{
	if (evaluate_sorting(a, b, sort_ascending))
		return (are_edges(a, b, stack, sort_ascending));
	return (are_immediate(a, b, stack, sort_ascending));
}

char	are_edges(int a, int b, t_stack *stack, char sort_ascending)
{
	t_node	*node;
	int		maximum;
	int		minimum;
	
	node = stack->top;
	if (sort_ascending)
	{
		maximum = b;
		minimum = a;
	}
	else
	{
		maximum = a;
		minimum = b;
	}
	while (node != NULL)
	{
		if (node->value > maximum || node->value < minimum)
			return (0);
		node = node->next;
	}
	return (1);
}

char	are_immediate(int a, int b, t_stack *stack, char sort_ascending)
{
	t_node	*node;

	node = stack->top;
	while (node != NULL)
	{
		if (evaluate_sorting(node->value, a, sort_ascending) && evaluate_sorting(b, node->value, sort_ascending))
			return (0);
		node = node->next;
	}
	return (1);
}
