/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_arg_to_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:34:58 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/03 16:06:30 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Error resolver function
	Handles errors.
	No params.
*/
void	ft_error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(0);
}

/*
	Int checker function
	Checks if a string is an int.
	Params:
		s: string.
*/
void	check_is_int(char *s)
{
	int		i;
	int		sig;
	long	num;

	if (s[0] == '\0')
		ft_error();
	i = 0;
	sig = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sig = -1;
		++i;
	}
	num = 0;
	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9' || i > 11)
			ft_error();
		num *= 10;
		num += sig * (s[i] - '0');
		++i;
	}
	if ((sig == 1 && num > 2147483647) || (sig == -1 && num < -2147483648))
		ft_error();
}

/*
	Duplication checker function
	Checks if the number is duplicated.
	Params:
		nums: numbers already placed.
		index: position of the last number placed which is the number to check.
*/
void	check_not_dup(int *nums, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (nums[i] == nums[index])
			ft_error();
		++i;
	}
}

/*
	Stack simplification function
	It simplifies the number list into the stack as 0..n.
	Params:
		A: stack.
		nums: numbers not simplified.
		size: size of the number list.
*/
void	simplify_stack(t_stack *A, int *nums, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		A->values[i] = i;
		++A->size;
		while (j < i)
		{
			if (nums[i] < nums[j])
			{
				--A->values[i];
				++A->values[j];
			}
			++j;
		}
		++i;
	}
}

/*
	Arg to stack converter function
	It converts the arguments to the stack. It handles the possible errors.
	Params:
		argc: number size.
		argv: number list.
		A: stack.
*/
void	convert_arg_to_stack(int argc, char **argv, t_stack *A)
{
	int	*nums;
	int	i;

	i = 1;
	nums = malloc((argc - 1) * sizeof(int));
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
