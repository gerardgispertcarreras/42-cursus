/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decide_move_flow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:24:37 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/09 13:40:16 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
	Move flow decider function
	It saves the variables of direction and operation depending on the moves.
	Params:
		moves: number of moves to the desired number.
		direction: pointer to the direction. It will be 1 or -1.
		operation: pointer to the operation string. It will be "rb" or "rrb".
*/
void decide_move_flow(const int moves, int *direction, char **operation, char stack_selected)
{
	if (moves < 0)
	{
		*direction = 1;
		*operation = operation_conversor("rr", stack_selected);
	}
	else
	{
		*direction = -1;
		*operation = operation_conversor("r", stack_selected);
	}
}
