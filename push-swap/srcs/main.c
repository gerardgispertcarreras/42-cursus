/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:16:54 by ggispert          #+#    #+#             */
/*   Updated: 2023/09/07 11:30:39 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_stack *A, int size)
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
	S->values = malloc(max_size);
	S->size = 0;
}

int	main(int argc, char **argv)
{
	t_stack A;
	t_stack B;
	int max_size;

	if (argc > 1)
	{
		max_size = argc - 1;
		init_stack(&A, max_size);
		init_stack(&B, max_size);
		convert_arg_to_stack(argc, argv, &A);
		push_swap(&A, &B, max_size);
		print_stack(&A, max_size);
	}
	return (0);
}
