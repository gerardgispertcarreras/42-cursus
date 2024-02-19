/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:34:09 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/19 11:55:56 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_setup(t_setup *setup)
{
	printf("n_philo = %d\n", setup->n_philo);
	printf("t_die = %d\n", setup->t_die);
	printf("t_eat = %d\n", setup->t_eat);
	printf("t_sleep = %d\n", setup->t_sleep);
	printf("n_times_eat = %d\n", setup->n_times_eat);
}

int	main(int argc, char **argv)
{
	t_setup	setup;
	if (parser(argc, argv, &setup))
		return (EXIT_SUCCESS);
	print_setup(&setup);
	return (0);
}
