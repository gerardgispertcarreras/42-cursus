/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:21:56 by gerard            #+#    #+#             */
/*   Updated: 2023/12/05 11:38:55 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Stack top value getter function
	It returns the top value of the stack.
	Params:
		S: stack.
*/
int	top(t_stack *S)
{
	return (S->values[0]);
}

/*
	Stack size getter function
	It returns the size of a stack.
	Params:
		S: stack.
*/
int	size(t_stack *S)
{
	return (S->size);
}

/*
	Is it sorted function
	It returns 1 if the stack is sorted. 0 if not.
	Params:
		S: stack to check.
*/
char	is_sorted(t_stack *S)
{
	char	sorted;
	int		i;
	int		j;
	int		prev;

	sorted = 1;
	i = -1;
	while (S->values[++i] != 0)
		;
	prev = 0;
	j = i + 1;
	if (j >= size(S))
		j = 0;
	while (sorted && j != i)
	{
		if (prev > S->values[j])
			sorted = 0;
		prev = S->values[j++];
		if (j >= size(S))
			j = 0;
	}
	return (sorted);
}
