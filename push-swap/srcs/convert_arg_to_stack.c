/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_arg_to_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:34:58 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/09 14:26:35 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Int checker function
	Checks if a string is an int.
	Params:
		s: string.
*/
void check_is_int(char *s)
{
	int i;
	int sig;
	long num;

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
	Duplication checker function
	Checks if the number is duplicated.
	Params:
		nums: numbers already placed.
		index: position of the last number placed which is the number to check.
*/
void check_not_dup(int *nums, int index)
{
	int i;

	i = 0;
	while (i < index)
	{
		if (nums[i] == nums[index])
			error_handler();
		++i;
	}
}

/*
	Number simplification function
	It simplifies the number checking the whole list of numbers.
	Params:
		nums: numbers not simplified.
		n: number to simplify.
		size: size of the number list.
	Returns:
		The number simplified. It starts on 0 and adds 1 for every
		number smaller than it in the list.
*/
int calc_simplified_num(int *nums, int n, int size)
{
	int i;
	int simplified_n;

	i = -1;
	simplified_n = 0;
	while (++i < size)
	{
		if (nums[i] < n)
			++simplified_n;
	}
	return (simplified_n);
}

/*
	Stack simplification function
	It simplifies the number list into the stack as 0..n.
	Params:
		A: stack.
		nums: numbers not simplified.
		size: size of the number list.
*/
void simplify_stack(t_stack *S, int *nums, int size)
{
	int i;
	t_node *node_current;
	t_node *node_prev;

	node_current = malloc(sizeof(t_node));
	if (node_current == NULL)
		exit(0);
	S->top = node_current;
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
	S->bot = node_current;
	S->size = size;
}

/*
	Arg to stack converter function
	It converts the arguments to the stack. It handles the possible errors.
	Params:
		argc: number size.
		argv: number list.
		A: stack.
*/
void convert_arg_to_stack(int argc, char **argv, t_stack *A)
{
	int *nums;
	int i;

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
	simplify_stack(A, nums, argc - 1);
	free(nums);
}
