/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_arg_to_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:34:58 by ggispert          #+#    #+#             */
/*   Updated: 2023/10/21 19:28:37 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error()
{
	ft_putstr_fd("Error\n", 1);
	exit(0);
}

//Check if the string is an int
void check_is_int(char *s)
{
	int	i;
	int signum;
	long num;

	if (s[0] == '\0')
		ft_error();
	i = 0;
	signum = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			signum = -1;
		++i;
	}
	num = 0;
	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9' || i > 11)
			ft_error();
		num *= 10;
		num += signum * (s[i] - '0');
		++i;
	}
	if ((signum == 1 && num > 2147483647) || (signum == -1 && num < -2147483648))
		ft_error();
}

//check the number in the index is not already on another position before
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

//Convert the numbers to a simplification of its relative positions starting by 0 ([123, 4, 80] -> [2, 0, 1])
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

void	convert_arg_to_stack(int argc, char **argv, t_stack *A)
{
	int	nums[argc - 1]; //array of numbers from the stack
	int	i;

	i = 1;
	while (i < argc)
	{
		check_is_int(argv[i]);
		nums[i - 1] = ft_atoi(argv[i]); //add the arg to the array
		check_not_dup(nums,  i - 1); 
		++i;
	}
	simplify_stack(A, nums, argc - 1);
}
