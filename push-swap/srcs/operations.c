/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:25:53 by ggispert          #+#    #+#             */
/*   Updated: 2023/10/22 13:31:40 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
void	swap(t_stack *A, t_stack *B, char stack);
void	push(t_stack *A, t_stack *B, char stack);
void	rotate(t_stack *A, t_stack *B, char stack);
void	reverse_rotate(t_stack *A, t_stack *B, char stack);

void	operate(t_stack *A, t_stack *B, char *op)
{
	if (op[0] == 's') //swap
		swap(A, B, op[1]);
	else if (op[0] == 'p') //push
		push(A, B, op[1]);
	else if (op[0] == 'r') 
	{
		if (op[2] == '\0') //rotate
			rotate(A, B, op[1]);
		else //reverse_rotate
			reverse_rotate(A, B, op[2]);
	}
}

void	swap(t_stack *A, t_stack *B, char stack)
{
	(void) A;
	(void) B;
	(void) stack;
	if (stack == 'a')
	{
		
	}
	else if (stack == 'b')
	{
		
	}
	else if (stack == 's')
	{
		
	}
}

void	push(t_stack *A, t_stack *B, char stack)
{
	int	temp;
	int i = 1;
	
	if (stack == 'a')
	{
		
	}
	else if (stack == 'b')
	{
		temp = A->values[0]; //store the number we want to push
		while (i < A->size) //reallocate the stack A pushing every number one position above
		{
			A->values[i - 1] = A->values[i];
			++i;
		}
		i = B->size;
		while (i > 0) //reallocate the stack B pushing every number one position below
		{
			B->values[i] = B->values[i - 1];
			--i;
		}
		B->values[0] = temp; //number we want to push on top of B stack
		--(A->size);
		++(B->size);
	}	
}

void	rotate(t_stack *A, t_stack *B, char stack)
{
	(void) B;
	int	temp;
	int i = 1;
	
	if (stack == 'a')
	{
		temp = A->values[0]; //store the last number
		while (i < A->size) //reallocate the stack A pushing every number one position above
		{
			A->values[i - 1] = A->values[i];
			++i;
		}
		A->values[i - 1] = temp; //the first number goes to the last
	}
	else if (stack == 'b')
	{
		temp = B->values[0]; //store the last number
		while (i < B->size) //reallocate the stack A pushing every number one position above
		{
			B->values[i - 1] = B->values[i];
			++i;
		}
		B->values[i - 1] = temp; //the first number goes to the last	
	}
	else if (stack == 'r')
	{
		
	}
}

void	reverse_rotate(t_stack *A, t_stack *B, char stack)
{
	(void) A;
	int	temp;
	int i = B->size - 1;
	
	if (stack == 'a')
	{
		
	}
	else if (stack == 'b')
	{
		temp = B->values[B->size - 1]; //store the last number
		while (i > 0) //reallocate the stack B pushing every number one position below
		{
			B->values[i] = B->values[i - 1];
			--i;
		}
		B->values[0] = temp; //the last number goes to the first
	}
	else if (stack == 'r')
	{
		
	}
}
