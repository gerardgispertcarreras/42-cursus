/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:25:53 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/03 17:10:02 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack *A, t_stack *B, char stack);
void	push(t_stack *A, t_stack *B, char stack);
void	rotate(t_stack *A, t_stack *B, char stack);
void	reverse_rotate(t_stack *A, t_stack *B, char stack);

void	operate(t_stack *A, t_stack *B, char *op)
{
	if (op[0] == 's')
		swap(A, B, op[1]);
	else if (op[0] == 'p')
		push(A, B, op[1]);
	else if (op[0] == 'r')
	{
		if (op[2] == '\0')
			rotate(A, B, op[1]);
		else
			reverse_rotate(A, B, op[2]);
	}
	ft_printf("%s\n", op);
}

void	swap(t_stack *A, t_stack *B, char stack)
{
	int		temp;
	t_stack	*s;

	if (stack == 'a')
		s = A;
	else if (stack == 'b')
		s = B;
	else if (stack == 's')
	{
		swap(A, B, 'a');
		swap(A, B, 'b');
		return ;
	}
	temp = top(s);
	s->values[0] = A->values[1];
	s->values[1] = temp;
}

void	push(t_stack *A, t_stack *B, char stack)
{
	int		temp;
	int		i;
	t_stack	*s1;
	t_stack	*s2;

	if (stack == 'a')
	{
		s1 = B;
		s2 = A;
	}
	else if (stack == 'b')
	{
		s1 = A;
		s2 = B;
	}
	temp = s1->values[0];
	i = 0;
	while (++i < s1->size)
		s1->values[i - 1] = s1->values[i];
	i = s2->size + 1;
	while (--i > 0)
		s2->values[i] = s2->values[i - 1];
	s2->values[0] = temp;
	--(s1->size);
	++(s2->size);
}

void	rotate(t_stack *A, t_stack *B, char stack)
{
	int		temp;
	int		i;
	t_stack	*s;

	if (stack == 'a')
		s = A;
	else if (stack == 'b')
		s = B;
	else if (stack == 'r')
	{
		rotate(A, B, 'a');
		rotate(A, B, 'b');
		return ;
	}
	temp = s->values[0];
	i = 0;
	while (++i < s->size)
		s->values[i - 1] = s->values[i];
	s->values[i - 1] = temp;
}

void	reverse_rotate(t_stack *A, t_stack *B, char stack)
{
	int		temp;
	int		i;
	t_stack	*s;

	if (stack == 'a')
		s = A;
	else if (stack == 'b')
		s = B;
	else if (stack == 'r')
	{
		reverse_rotate(A, B, 'a');
		reverse_rotate(A, B, 'b');
		return ;
	}
	temp = s->values[s->size - 1];
	i = s->size;
	while (--i > 0)
		s->values[i] = s->values[i - 1];
	s->values[0] = temp;
}
