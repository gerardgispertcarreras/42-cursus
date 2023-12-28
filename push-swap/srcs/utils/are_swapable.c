/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_swapable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:42:34 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/14 09:18:50 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
	This function returns the index of a swapable number.
	Params:
		stack: stack.
		ascending: if the sorting has to be ascending, 1. 0 otherwise.
*/
int	search_swap(t_stack *stack, char ascending)
{
	t_node	*node;
	int		index;

	node = stack->top;
	index = 0;
	while (node->next != NULL)
	{
		if (are_swapable(node->value, node->next->value, stack, ascending))
			return (index);
		++index;
		node = node->next;
	}
	if (are_swapable(node->value, stack->top->value, stack, ascending))
		return (stack->size - 1);
	return (-1);
}

/*
	This function checks if 2 numbers are swapable. They are swapable
	if they aren't sorted and they are immediate numbers.
	Params:
		a: first number.
		b: second number.
		stack: stack.
		ascending: if the sorting has to be ascending, 1. 0 otherwise.
*/
char	are_swapable(int a, int b, t_stack *stack, char ascending)
{
	if (eval_sort(a, b, ascending))
		return (are_edges(a, b, stack, ascending));
	return (are_immediate(a, b, stack, ascending));
}

/*
	This function checks if 2 numbers are the edges of a stack.
	Params:
		a: first number.
		b: second number.
		stack: stack.
		ascending: if the sorting has to be ascending, 1. 0 otherwise.
*/
char	are_edges(int a, int b, t_stack *stack, char ascending)
{
	t_node	*node;
	int		maximum;
	int		minimum;

	node = stack->top;
	if (ascending)
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

/*
	This function checks if 2 numbers are immediate in a stack. They
	are immediate if they should be together in the sorted stack.
	Params:
		a: first number.
		b: second number.
		stack: stack.
		ascending: if the sorting has to be ascending, 1. 0 otherwise.
*/
char	are_immediate(int a, int b, t_stack *stack, char ascending)
{
	t_node	*node;
	int		n;

	node = stack->top;
	while (node != NULL)
	{
		n = node->value;
		if (eval_sort(n, a, ascending) && eval_sort(b, n, ascending))
			return (0);
		node = node->next;
	}
	return (1);
}
