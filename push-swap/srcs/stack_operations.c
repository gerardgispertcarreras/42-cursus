/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:20:11 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/10 14:04:11 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	This function swaps the two first elements of the stack.
	Params:
		stack: stack.
*/
void	swap_stack(t_stack *stack)
{
	t_node	*node_first;
	t_node	*node_second;
	t_node	*node_third;

	node_first = stack->top;
	node_second = node_first->next;
	node_third = node_second->next;
	if (node_third)
		node_third->prev = node_first;
	node_first->prev = node_second;
	node_second->next = node_first;
	node_first->next = node_third;
	node_second->prev = NULL;
	stack->top = node_second;
}

/*
	This function sets node as the top of the stack.
	Params:
		stack: stack.
		node: node.
*/
void	set_stack_top(t_stack *stack, t_node *node)
{
	node->prev = NULL;
	node->next = stack->top;
	if (stack->size > 0)
		stack->top->prev = node;
	else
		stack->bot = node;
	stack->top = node;
	++(stack->size);
}

/*
	This function removes the top of the stack and sets the next.
	Params:
		stack: stack.
*/
void	remove_stack_top(t_stack *stack)
{
	stack->top = stack->top->next;
	if (stack->size > 1)
		stack->top->prev = NULL;
	else
		stack->bot = NULL;
	--(stack->size);
}

/*
	This function sets node as the bot of the stack.
	Params:
		stack: stack.
		node: node.
*/
void	set_stack_bot(t_stack *stack, t_node *node)
{
	node->next = NULL;
	node->prev = stack->bot;
	if (stack->size > 0)
		stack->bot->next = node;
	else
		stack->top = node;
	stack->bot = node;
	++(stack->size);
}

/*
	This function removes the bot of the stack and sets the previous.
	Params:
		stack: stack.
*/
void	remove_stack_bot(t_stack *stack)
{
	stack->bot = stack->bot->prev;
	if (stack->size > 1)
		stack->bot->next = NULL;
	else
		stack->top = NULL;
	--(stack->size);
}
