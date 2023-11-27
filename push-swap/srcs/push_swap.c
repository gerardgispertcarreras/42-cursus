/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:59:46 by ggispert          #+#    #+#             */
/*   Updated: 2023/10/22 13:32:08 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_swap(t_stack *A, t_stack *B)
{
	int	i;
	int	sentinel;
	int	pivot;
	int pivot2;

	i = 4;
	while (i > 0)
	{
		sentinel = -1;
		pivot = A->size / i + B->size;
		pivot2 = A->size / (i * 2) + B->size;
		while (A->size != 0 && A->values[0] != sentinel)
		{
			if (A->values[0] < pivot)
			{
				operate(A, B, "pb");
				if (B->values[0] < pivot2)
					operate(A, B, "rb");
			}
			else
			{
				if (sentinel == -1)
					sentinel = A->values[0];
				operate(A, B, "ra");
			}
		}
		--i;	
	}
}
