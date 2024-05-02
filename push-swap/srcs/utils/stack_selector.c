/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_selector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:41:05 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/10 17:06:16 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
	This function selects the stack.
	Params:
		a: stack a.
		b: stack b.
		selected: selected stack.
*/
t_stack	*stack_selector(t_stack *a, t_stack *b, char selected)
{
	if (selected == 'a')
		return (a);
	return (b);
}
