/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decide_move_flow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:24:37 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/10 16:56:46 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
	This function initializes the direction and sets the operation depending
	on the moves.
	Params:
		moves: number of moves to execute.
		dir: pointer to the direction. It will be set to 1 or -1.
		op: pointer to the operation. It will be set to "r" or "rr".
		selected: stack selected.
*/
void	decide_move_flow(const int moves, int *dir, char **op, char selected)
{
	if (moves < 0)
	{
		*dir = 1;
		*op = operation_conversor("rr", selected);
	}
	else
	{
		*dir = -1;
		*op = operation_conversor("r", selected);
	}
}
