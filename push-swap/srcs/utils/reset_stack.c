/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:38:54 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/09 13:40:38 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void reset_stack(t_stack *a, t_stack *b, char stack_selected, char sort_ascending)
{
	t_stack *stack;
	int moves;

	stack = stack_selector(a, b, stack_selected);
	moves = calc_moves_by_index(stack, get_index_top_stack(stack, sort_ascending));
	execute_moves_simple(a, b, moves, stack_selected);
}
