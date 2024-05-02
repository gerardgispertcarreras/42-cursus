/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:18:10 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/10 13:30:48 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	This function sorts stacks from size 2 to 8.
	Params:
		a: stack with the numbers list.
		b: empty stack.
*/
void	algorithm_simple(t_stack *a, t_stack *b)
{
	int	pivot;
	int	counter;

	if (a->size <= 4)
		pivot = 0;
	else if (a->size <= 6)
		pivot = a->size - 3;
	else
		pivot = a->size - 4;
	counter = 0;
	while (counter < pivot)
	{
		if (a->top->value < pivot)
		{
			operate(a, b, "pb");
			++counter;
		}
		else
			operate(a, b, "ra");
	}
	select_sorting(a, b, 'a', 1);
	select_sorting(a, b, 'b', 0);
	while (counter-- > 0)
		operate(a, b, "pa");
}

/*
	This function selects the sorting algorithm based on its size.
	The size has to be 2, 3 or 4.
	Params:
		a: stack a.
		b: stack b.
		selected: selected stack. 'a' or 'b'.
		ascending: if the sorting has to be ascending, 1. 0 otherwise.
*/
void	select_sorting(t_stack *a, t_stack *b, char selected, char ascending)
{
	t_stack	*stack;

	stack = stack_selector(a, b, selected);
	if (stack->size == 2)
		sort2(a, b, selected, ascending);
	else if (stack->size == 3)
		sort3(a, b, selected, ascending);
	else if (stack->size == 4)
		sort4(a, b, selected, ascending);
}

/*
	This function sorts stacks of size 2.
	Params:
		a: stack a.
		b: stack b.
		selected: selected stack. 'a' or 'b'.
		ascending: if the sorting has to be ascending, 1. 0 otherwise.
*/
void	sort2(t_stack *a, t_stack *b, char selected, char ascending)
{
	t_stack	*stack;
	t_node	*node;
	char	*operation;

	stack = stack_selector(a, b, selected);
	operation = operation_conversor("s", selected);
	node = stack->top;
	if (!eval_sort(node->value, node->next->value, ascending))
		operate(a, b, operation);
	free(operation);
}

/*
	This function sorts stacks of size 3.
	Params:
		a: stack a.
		b: stack b.
		selected: selected stack. 'a' or 'b'.
		ascending: if the sorting has to be ascending, 1. 0 otherwise.
*/
void	sort3(t_stack *a, t_stack *b, char selected, char ascending)
{
	t_stack	*stack;
	char	*operation;

	stack = stack_selector(a, b, selected);
	operation = operation_conversor("s", selected);
	if (!is_sorted(stack, ascending))
		operate(a, b, operation);
	reset_stack(a, b, selected, ascending);
	free(operation);
}

/*
	This function sorts stacks of size 4.
	Params:
		a: stack a.
		b: stack b.
		selected: selected stack. 'a' or 'b'.
		ascending: if the sorting has to be ascending, 1. 0 otherwise.
*/
void	sort4(t_stack *a, t_stack *b, char selected, char ascending)
{
	t_stack	*stack;
	char	*operation;
	int		moves;

	stack = stack_selector(a, b, selected);
	operation = operation_conversor("s", selected);
	while (!is_sorted(stack, ascending))
	{
		moves = calc_moves_by_index(stack, search_swap(stack, ascending));
		execute_moves_simple(a, b, moves, selected);
		operate(a, b, operation);
	}
	reset_stack(a, b, selected, ascending);
	free(operation);
}
