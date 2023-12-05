/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:25:53 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/05 20:21:46 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	operate(t_stack *A, t_stack *B, char *op)
{
	if (op[0] == 's')
		swap(A, B, op[1]);
	else if (op[0] == 'p')
		push(A, B, op[1]);
	else if (op[0] == 'r')
	{
		if (op[2] == '\0')
			rotate(A, B, op[1]);
		else
			reverse_rotate(A, B, op[2]);
	}
	ft_printf("%s\n", op);
}

void	swap(t_stack *A, t_stack *B, char stack)
{
	t_stack	*s;

	if (stack == 'a')
		s = A;
	else if (stack == 'b')
		s = B;
	else if (stack == 's')
	{
		swap(A, B, 'a');
		swap(A, B, 'b');
		return ;
	}
	swap_stack(s);
}

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
	else if (stack == 'b')
	{
		stack_origin = A;
		stack_destination = B;
	}
	node = stack_origin->top;
	remove_stack_top(stack_origin);
	set_stack_top(stack_destination, node);
}

void	rotate(t_stack *A, t_stack *B, char stack_selected)
{
	t_stack	*stack;
	t_node	*node;

	if (stack_selected == 'a')
		stack = A;
	else if (stack_selected == 'b')
		stack = B;
	else if (stack_selected == 'r')
	{
		rotate(A, B, 'a');
		rotate(A, B, 'b');
		return ;
	}
	node = stack->top;
	remove_stack_top(stack);
	set_stack_bot(stack, node);
}

void	reverse_rotate(t_stack *A, t_stack *B, char stack_selected)
{
	t_stack	*stack;
	t_node	*node;

	if (stack_selected == 'a')
		stack = A;
	else if (stack_selected == 'b')
		stack = B;
	else if (stack_selected == 'r')
	{
		reverse_rotate(A, B, 'a');
		reverse_rotate(A, B, 'b');
		return ;
	}
	node = stack->bot;
	remove_stack_bot(stack);
	set_stack_top(stack, node);
}
