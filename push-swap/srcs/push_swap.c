/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:59:46 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/05 11:39:14 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Algorithm for 3 numbers function
	It makes a swap if it is not sorted and rotates to the sorted solution.
	Params:
		A: stack with the numbers list
		B: empty stack
*/
void	algorithm_size3(t_stack *A, t_stack *B)
{
	if (!is_sorted(A))
		operate(A, B, "sa");
	if (top(A) > A->values[size(A) - 1])
		operate(A, B, "rra");
	else if (A->size > 1 && top(A) > A->values[1])
		operate(A, B, "ra");
}

/*
	Algorithm for 5 numbers function
	Params:
		A: stack with the numbers list
		B: empty stack
*/
void	algorithm_size5(t_stack *A, t_stack *B)
{
	int	pivot;

	pivot = size(A) / 2;
	while (size(A) != 0 && pivot > size(B))
	{
		if (top(A) > pivot)
			operate(A, B, "pb");
		else
			operate(A, B, "ra");
	}
	algorithm_size3(A, B);
	if (B->values[0] < B->values[1])
		operate(A, B, "sb");
	operate(A, B, "pa");
	operate(A, B, "pa");
	operate(A, B, "ra");
	operate(A, B, "ra");
}

/*
	Algorithm for 100 numbers function
	It makes a pseudo sorting splitting the numbers in 4 blocks
	and reordering them back afterwards.
	Params:
		A: stack with the numbers list
		B: empty stack
*/
void	algorithm_size100(t_stack *A, t_stack *B)
{
	split_stack(A, B, 4);
	reorder(A, B);
}

/*
	Algorithm for 500 numbers function
	It makes a pseudo sorting splitting the numbers in 8 blocks
	and reordering them back.
	Params:
		A: stack with the numbers list
		B: empty stack
*/
void	algorithm_size500(t_stack *A, t_stack *B)
{
	split_stack(A, B, 8);
	reorder(A, B);
}

/*
	Push swap algorithm function
	It calls the correct sorting algorithm depending on the list size
	Params:
		A: stack with the numbers list
		B: empty stack
*/
void	push_swap(t_stack *A, t_stack *B)
{
	if (A->size <= 3)
		algorithm_size3(A, B);
	else if (A->size <= 5)
		algorithm_size5(A, B);
	else if (A->size <= 100)
		algorithm_size100(A, B);
	else
		algorithm_size500(A, B);
}
