/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_finish.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:31:36 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/10 13:47:30 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	This function sets the t_stack props to default.
	Params:
		S: stack.
*/
void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->bot = NULL;
	stack->size = 0;
}

/*
	This function frees the memory of a node and all the next ones. (recursive)
	Params:
		n: node.
*/
void	free_nodes(t_node *node)
{
	if (node == NULL)
		return ;
	if (node->next != NULL)
		free_nodes(node->next);
	node->value = 0;
	node->next = NULL;
	node->prev = NULL;
	free(node);
}

/*
	This function frees the memory of a stack.
	Params:
		S: stack.
*/
void	free_stack(t_stack *stack)
{
	free_nodes(stack->top);
	stack->top = NULL;
	stack->bot = NULL;
	stack->size = 0;
}

/*
	This function handles the errors in the arguments.
	No params.
*/
void	error_handler(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}
