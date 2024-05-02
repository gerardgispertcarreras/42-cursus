/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:25:53 by ggispert          #+#    #+#             */
/*   Updated: 2024/01/29 17:08:41 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	This function handles the operations.
	Params:
		a: stack a.
		b: stack b.
		operation: string of the operation.
*/
void	operate(t_stack *a, t_stack *b, char *operation)
{
	if (operation[0] == 's')
		swap(a, b, operation[1]);
	else if (operation[0] == 'p')
		push(a, b, operation[1]);
	else if (operation[0] == 'r')
	{
		if (operation[2] == '\0')
			rotate(a, b, operation[1]);
		else
			reverse_rotate(a, b, operation[2]);
	}
	ft_printf("%s\n", operation);
}

/*
	This function executes the swap for the stack selected.
	Params:
		a: stack a.
		b: stack b.
		stack: stack selected. 'a' or 'b'.
*/
void	swap(t_stack *A, t_stack *B, char stack)
{
	t_stack	*s;

	if (stack == 'a')
		s = A;
	else if (stack == 'b')
		s = B;
	else
	{
		swap(A, B, 'a');
		swap(A, B, 'b');
		return ;
	}
	swap_stack(s);
}

/*
	This function executes the push for the stack selected.
	Params:
		a: stack a.
		b: stack b.
		stack: stack selected. 'a' or 'b'.
*/
void	push(t_stack *A, t_stack *B, char stack)
{
	t_stack	*stack_origin;
	t_stack	*stack_destination;
	t_node	*node;

	if (stack == 'a')
	{
		stack_origin = B;
		stack_destination = A;
	}
	else
	{
		stack_origin = A;
		stack_destination = B;
	}
	node = stack_origin->top;
	remove_stack_top(stack_origin);
	set_stack_top(stack_destination, node);
}

/*
	This function executes the rotate for the stack selected.
	Params:
		a: stack a.
		b: stack b.
		stack: stack selected. 'a' or 'b'.
*/
void	rotate(t_stack *A, t_stack *B, char selected)
{
	t_stack	*stack;
	t_node	*node;

	if (selected == 'a')
		stack = A;
	else if (selected == 'b')
		stack = B;
	else
	{
		rotate(A, B, 'a');
		rotate(A, B, 'b');
		return ;
	}
	node = stack->top;
	remove_stack_top(stack);
	set_stack_bot(stack, node);
}

/*
	This function executes the reverse rotate for the stack selected.
	Params:
		a: stack a.
		b: stack b.
		stack: stack selected. 'a' or 'b'.
*/
void	reverse_rotate(t_stack *A, t_stack *B, char selected)
{
	t_stack	*stack;
	t_node	*node;

	if (selected == 'a')
		stack = A;
	else if (selected == 'b')
		stack = B;
	else
	{
		reverse_rotate(A, B, 'a');
		reverse_rotate(A, B, 'b');
		return ;
	}
	node = stack->bot;
	remove_stack_bot(stack);
	set_stack_top(stack, node);
}
