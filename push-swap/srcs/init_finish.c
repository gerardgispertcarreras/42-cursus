/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_finish.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:31:36 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/09 14:23:27 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Init stack function
	It sets the t_stack props to default.
	Params:
		S: stack.
*/
void	init_stack(t_stack *S)
{
	S->top = NULL;
	S->bot = NULL;
	S->size = 0;
}

/*
	Free stack function
	It frees the memory of a node and all the next ones. (recursive)
	Params:
		n: node.
*/
void	free_nodes(t_node *n)
{
	if (n == NULL)
		return ;
	if (n->next != NULL)
		free_nodes(n->next);
	n->value = 0;
	n->next = NULL;
	n->prev = NULL;
	free(n);
}

/*
	Free stack function
	It frees the memory of a stack.
	Params:
		S: stack.
*/
void	free_stack(t_stack *S)
{
	free_nodes(S->top);
	S->top = NULL;
	S->bot = NULL;
	S->size = 0;
}

/*
	Usage error resolver function
	Handles errors.
	No params.
*/
void	error_handler(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}
