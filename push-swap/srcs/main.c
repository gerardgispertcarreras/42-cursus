/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:16:54 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/05 11:37:50 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Init stack function
	It saves memory for the maximum numbers it will handle but it remains empty.
	Params:
		S: the stack wanted to be initialized
		max_size: the maximum size that the stack might handle
*/
void	init_stack(t_stack *S, int max_size)
{
	S->values = malloc(max_size * sizeof(int));
	S->size = 0;
	if (S->values == NULL)
		exit (0);
}

/*
	Free stack function
	It frees the memory of a stack.
	Params:
		S: the stack wanted to be freed
*/
void	free_stack(t_stack *S)
{
	free(S->values);
}

/*
	Main function
	Params:
		A list of ints is expected.
		Ex: ./push_swap 3 42 5 -3 412
*/
int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		max_size;

	if (argc > 1)
	{
		max_size = argc - 1;
		init_stack(&a, max_size);
		convert_arg_to_stack(argc, argv, &a);
		init_stack(&b, max_size);
		push_swap(&a, &b);
		free_stack(&a);
		free_stack(&b);
	}
	return (0);
}
