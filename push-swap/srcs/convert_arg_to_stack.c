/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_arg_to_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:34:58 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/10 13:43:23 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	This function converts the arguments to a stack. It checks all
	the errors and simplifies the numbers.
	Params:
		argc: number size.
		argv: number list.
		a: stack a.
*/
void	convert_arg_to_stack(int argc, char **argv, t_stack *a)
{
	int	*nums;
	int	i;

	i = 1;
	nums = malloc((argc - 1) * sizeof(int));
	if (nums == NULL)
		exit(0);
	while (i < argc)
	{
		check_is_int(argv[i]);
		nums[i - 1] = ft_atoi(argv[i]);
		check_not_dup(nums, i - 1);
		++i;
	}
	simplify_stack(a, nums, argc - 1);
	free(nums);
}

/*
	This function checks if a s is an int.
	Params:
		s: string.
*/
void	check_is_int(char *s)
{
	int		i;
	int		sig;
	long	num;

	i = 0;
	sig = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sig = -1;
		++i;
	}
	if (s[i] == '\0')
		error_handler();
	num = 0;
	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9' || i > 11)
			error_handler();
		num *= 10;
		num += sig * (s[i] - '0');
		++i;
	}
	if ((sig == 1 && num > 2147483647) || (sig == -1 && num < -2147483648))
		error_handler();
}

/*
	This function checks if the number in nums[index] is duplicated before it.
	Params:
		nums: number list.
		index: position of the number to check.
*/
void	check_not_dup(int *nums, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (nums[i] == nums[index])
			error_handler();
		++i;
	}
}

/*
	This function simplifies the number list into the stack as 0..size - 1.
	Params:
		stack: stack.
		nums: number list.
		size: size of the number list.
*/
void	simplify_stack(t_stack *stack, int *nums, int size)
{
	int		i;
	t_node	*node_current;
	t_node	*node_prev;

	node_current = malloc(sizeof(t_node));
	if (node_current == NULL)
		exit(0);
	stack->top = node_current;
	node_current->value = calc_simplified_num(nums, nums[0], size);
	node_current->prev = NULL;
	i = 0;
	while (++i < size)
	{
		node_prev = node_current;
		node_current = malloc(sizeof(t_node));
		if (node_current == NULL)
			exit(0);
		node_prev->next = node_current;
		node_current->value = calc_simplified_num(nums, nums[i], size);
		node_current->prev = node_prev;
	}
	node_current->next = NULL;
	stack->bot = node_current;
	stack->size = size;
}

/*
	This function simiplifies a number based on the number list.
	Params:
		nums: numbers list.
		n: number to simplify.
		size: size of the number list.
*/
int	calc_simplified_num(int *nums, int n, int size)
{
	int	i;
	int	simplified_n;

	i = -1;
	simplified_n = 0;
	while (++i < size)
	{
		if (nums[i] < n)
			++simplified_n;
	}
	return (simplified_n);
}
