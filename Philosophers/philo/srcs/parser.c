/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:05:57 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/19 11:57:39 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parser(int argc, char **argv, t_setup *setup)
{
	int	i;
	
	(void)argv;
	if (argc < 5 || argc > 6)
		return (usage());
	i = 0;
	while (++i < argc)
	{
		if (get_parameter(i, argv[i], setup))
			return (usage());
	}
	if (argc == 5)
		setup->n_times_eat = -1;
	return (0);
}

int	get_parameter(int param_index, char *arg, t_setup *setup)
{
	int	return_code;

	return_code = EXIT_FAILURE;
	if (param_index == 1)
		return_code = get_int(arg, &(setup->n_philo));
	else if (param_index == 2)
		return_code = get_int(arg, &(setup->t_die));
	else if (param_index == 3)
		return_code = get_int(arg, &(setup->t_eat));
	else if (param_index == 4)
		return_code = get_int(arg, &(setup->t_sleep));
	else if (param_index == 5)
		return_code = get_int(arg, &(setup->n_times_eat));
	return (return_code);
}

int	get_int(char *arg, int *num)
{
	(void)arg;
	*num = 1;
	return (0);
}

int	usage(void)
{
	ft_putendl_fd("Usage: ./philo <number_of_philosophers> <time_to_die> <time_\
to_eat> <time_to_sleep> [<number_of_times_each_philosopher_must_eat>]\n", 2);
	ft_putendl_fd("Examples:", 2);
	ft_putendl_fd("	./philo 4 100 20 20", 2);
	ft_putendl_fd("	./philo 4 100 20 20 10", 2);
	return (EXIT_FAILURE);
}
