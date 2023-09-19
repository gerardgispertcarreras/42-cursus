/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_arg_to_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:34:58 by ggispert          #+#    #+#             */
/*   Updated: 2023/09/07 11:22:44 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error()
{
	ft_putstr_fd("Error\n", 1);
	exit(0);
}

void check_is_int(char *argv)
{
	int	i;
	int signum;
	long num;

	if (argv[0] == '\0')
		ft_error();
	i = 0;
	signum = 1;
	if (argv[i] == '-' || argv[i] == '+')
	{
		if (argv[i] == '-')
			signum = -1;
		++i;
	}
	num = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] < '0' || argv[i] > '9' || i > 11)
			ft_error();
		num *= 10;
		num += signum * (argv[i] - '0');
		++i;
	}
	if ((signum == 1 && num > 2147483647) || (signum == -1 && num < -2147483648))
		ft_error();
}

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
	int	nums[argc - 1];
	int	i;

	i = 1;
	while (i < argc)
	{
		check_is_int(argv[i]);
		nums[i - 1] = ft_atoi(argv[i]);
		check_not_dup(nums,  i - 1);
		++i;
	}
	simplify_stack(A, nums, argc - 1);
}
