/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reorder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:06:28 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/03 17:10:24 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Move calculator function
	It calculates the moves to reach a number in the stack.
	Negative moves are reversed.
	Params:
		B: stack which must have the number.
    n: number to search.
*/
int	calc_moves(t_stack *B, int n)
{
	int	i;

	i = -1;
	while (B->values[++i] != n)
		;
	if (i > (size(B) / 2))
		i -= size(B);
	return (i);
}

/*
	Move flow decider function
	It saves the variables of direction and operation depending on the moves.
	Params:
		moves: number of moves to the desired number.
    direction: pointer to the direction. It will be 1 or -1.
    op: pointer to the operation string. It will be "rb" or "rrb".
*/
void	decide_move_flow(const int moves, char *direction, char **op)
{
	if (moves < 0)
	{
		*direction = 1;
		*op = "rrb";
	}
	else
	{
		*direction = -1;
		*op = "rb";
	}
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
char	prepare_push(t_stack *A, t_stack *B, int moves, int n)
{
	char	swap_needed;
	char	*op;
	char	direction;

	swap_needed = 0;
	decide_move_flow(moves, &direction, &op);
	while (moves != 0)
	{
		if (top(B) == (n - 1))
		{
			operate(A, B, "pa");
			swap_needed = 1;
			if (direction == -1)
				moves += direction;
		}
		else
		{
			operate(A, B, op);
			moves += direction;
		}
	}
	return (swap_needed);
}

/*
	Reorder function
	It reorders the stack B into A. At the end stack A is sorted.
	Params:
		A: stack destination.
    B: stack origin.
*/
void	reorder(t_stack *A, t_stack *B)
{
	int		i;
	int		moves;
	char	swap_needed;

	i = size(B);
	while (--i >= 0)
	{
		moves = calc_moves(B, i);
		swap_needed = prepare_push(A, B, moves, i);
		operate(A, B, "pa");
		if (swap_needed)
		{
			operate(A, B, "sa");
			--i;
		}
	}
}
