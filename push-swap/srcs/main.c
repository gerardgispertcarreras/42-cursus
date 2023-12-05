/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:16:54 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/05 18:28:10 by ggispert         ###   ########.fr       */
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
	Main function
	Args:
		A list of ints is expected.
		Ex: ./push_swap 3 42 5 -3 412
*/
int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc > 1)
	{
		init_stack(&a);
		init_stack(&b);
		convert_arg_to_stack(argc, argv, &a);
		push_swap(&a, &b);
		ft_printf("Stack A:\n");
		printStackValues(&a);
		ft_printf("Stack B:\n");
		printStackValues(&b);
		free_stack(&a);
		free_stack(&b);
	}
	return (0);
}
