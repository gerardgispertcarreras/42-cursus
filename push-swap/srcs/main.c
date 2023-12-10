/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:16:54 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/10 13:49:10 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Main function
	This program returns the list of instructions in the push_swap
	format to sort a list of numbers.
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
		free_stack(&a);
		free_stack(&b);
	}
	return (0);
}
