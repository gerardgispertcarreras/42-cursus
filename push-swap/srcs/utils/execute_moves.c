/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:23:55 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/09 13:42:07 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	execute_moves_simple(t_stack *a, t_stack *b, int moves, char stack_selected)
{
	int	direction;
	char *operation;

	decide_move_flow(moves, &direction, &operation, stack_selected);
	while (moves != 0)
	{
		operate(a, b, operation);
		moves += direction;
	}
	free(operation);
}

/*
	Push preparator function
	It prepares the stack B to do the push of the number n to stack A. It may
	return a swap if it found the next number on the process.
	Params:
		A: stack destination.
		B: stack origin.
		moves: number of moves it needs to do.
		n: number it is searching.
*/
char execute_moves_complex(t_stack *A, t_stack *B, int moves, int n)
{
	char swap_needed;
	char *operation;
	int direction;

	swap_needed = 0;
	decide_move_flow(moves, &direction, &operation, 'b');
	while (moves != 0)
	{
		if (B->top->value == (n - 1))
		{
			operate(A, B, "pa");
			swap_needed = 1;
			if (direction == -1)
				moves += direction;
		}
		else
		{
			operate(A, B, operation);
			moves += direction;
		}
	}
	free(operation);
	return (swap_needed);
}
