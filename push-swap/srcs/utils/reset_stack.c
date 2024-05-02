/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:38:54 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/10 17:00:47 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
	This function resets the selected stack. It means that it puts ok the numbers
	of a sorted stack.
	Params:
		a: stack a.
		b: stack b.
		selected: selected stack.
		ascending: if the sorting has to be ascending, 1. 0 otherwise.
*/
void	reset_stack(t_stack *a, t_stack *b, char selected, char ascending)
{
	t_stack	*stack;
	int		moves;

	stack = stack_selector(a, b, selected);
	moves = calc_moves_by_index(stack, get_index_top_stack(stack, ascending));
	execute_moves_simple(a, b, moves, selected);
}
