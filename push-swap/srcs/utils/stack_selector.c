/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_selector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:41:05 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/09 13:41:17 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack *stack_selector(t_stack *a, t_stack *b, char stack_selected)
{
	if (stack_selected == 'a')
		return a;
	return b;
}
