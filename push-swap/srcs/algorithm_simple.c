/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:18:10 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/09 13:54:03 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


/*
	Algorithm for 3 numbers function
	It makes a swap if it is not sorted and rotates to the sorted solution.
	Params:
		A: stack with the numbers list
		B: empty stack
*/
void algorithm_simple(t_stack *a, t_stack *b)
{
	int pivot;
	int counter;

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

void	select_sorting(t_stack *a, t_stack *b, char stack_selected, char sort_ascending)
{
	t_stack	*stack;

	stack = stack_selector(a, b, stack_selected);
	if (stack->size == 2)
		sort2(a, b, stack_selected, sort_ascending);
	else if (stack->size == 3)
		sort3(a, b, stack_selected, sort_ascending);
	else if (stack->size == 4)
		sort4(a, b, stack_selected, sort_ascending);
}

void sort2(t_stack *a, t_stack *b, char stack_selected, char sort_ascending)
{
	t_stack *stack;
	t_node *node;
	char *operation;

	stack = stack_selector(a, b, stack_selected);
	operation = operation_conversor("s", stack_selected);
	node = stack->top;
	if (!evaluate_sorting(node->value, node->next->value, sort_ascending))
		operate(a, b, operation);
	free(operation);
}

void sort3(t_stack *a, t_stack *b, char stack_selected, char sort_ascending)
{
	t_stack *stack;
	char *operation;

	stack = stack_selector(a, b, stack_selected);
	operation = operation_conversor("s", stack_selected);
	if (!is_sorted(stack, sort_ascending))
		operate(a, b, operation);
	reset_stack(a, b, stack_selected, sort_ascending);
	free(operation);
}

void sort4(t_stack *a, t_stack *b, char stack_selected, char sort_ascending)
{
	t_stack *stack;
	char *operation;
	int moves;

	stack = stack_selector(a, b, stack_selected);
	operation = operation_conversor("s", stack_selected);
	while (!is_sorted(stack, sort_ascending))
	{
		moves = calc_moves_by_index(stack, search_swap(stack, sort_ascending));
		execute_moves_simple(a, b, moves, stack_selected);
		operate(a, b, operation);
	}
	reset_stack(a, b, stack_selected, sort_ascending);
	free(operation);
}
