/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:16:54 by ggispert          #+#    #+#             */
/*   Updated: 2023/10/22 14:29:15 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_stack *A)
{
	int i = 0;

	while (i < A->size)
	{
		ft_putnbr_fd(A->values[i], 1);
		ft_putchar_fd('\n', 1);
		++i;
	}
}

void	init_stack(t_stack *S, int max_size)
{
	S->values = malloc(max_size * sizeof(int)); //stack numbers (capacity of the max length)
	S->size = 0; //current size
}

int	main(int argc, char **argv)
{
	//init variables
	t_stack A;
	t_stack B;
	int max_size;

	//check for the usage
	if (argc > 1)
	{
		max_size = argc - 1;
		
		//init stacks
		init_stack(&A, max_size);
		init_stack(&B, max_size);

		//fill stack A
		convert_arg_to_stack(argc, argv, &A);

		//sort stack A using stack B as an auxiliary
		push_swap(&A, &B);
		print_stack(&B);
	}
	return (0);
}
