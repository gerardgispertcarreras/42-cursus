/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:34:09 by ggispert          #+#    #+#             */
/*   Updated: 2024/03/05 11:51:54 by ggispert         ###   ########.fr       */
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

void	*philo_start(void *philo_arg)
{
	t_philo *philo = (t_philo *)philo_arg;

	while (1)
	{
		_think(philo);
		_eat(philo);
		_sleep(philo);
	}
	return NULL;
}

void	print_message(int msg_type, int id)
{
	if (msg_type == TAKE_FORK)
		printf("%ld %d has taken a fork\n", get_time(), id);
	else if (msg_type == LEAVE_FORK)
		printf("%ld %d has left a fork\n", get_time(), id);
	else if (msg_type == EAT)
		printf("%ld %d is eating\n", get_time(), id);
	else if (msg_type == THINK)
		printf("%ld %d is thinking\n", get_time(), id);
	else if (msg_type == SLEEP)
		printf("%ld %d is sleeping\n", get_time(), id);
	else if (msg_type == DIE)
		printf("%ld %d died\n", get_time(), id);
}

long	get_time()
{
	struct timeval tv;
	long	milliseconds;
	
	gettimeofday(&tv, NULL);
	milliseconds = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (milliseconds);
}

int	main(int argc, char **argv)
{
	t_setup	setup;
	pthread_t *thread_ids;
	pthread_mutex_t *forks;
	t_philo	*philos;
	int i;

	if (parser(argc, argv, &setup))
		return (EXIT_SUCCESS);
	print_setup(&setup);
	thread_ids = malloc(setup.n_philo * sizeof(pthread_t));
	forks = malloc(setup.n_philo * sizeof(pthread_mutex_t));
	philos = malloc(setup.n_philo * sizeof(t_philo));
	init(&setup, thread_ids, forks, philos);
	i = -1;
	while (++i < setup.n_philo)
	{
		pthread_join(thread_ids[i], NULL);
		pthread_mutex_destroy(&forks[i]);
	}
	return (EXIT_SUCCESS);
}

void	init(t_setup *setup, pthread_t *thread_ids, pthread_mutex_t *forks, t_philo	*philos)
{
	int		i;

	i = -1;
	pthread_mutex_init(&forks[0], NULL);
	while (++i < setup->n_philo)
	{
		philos[i].id = i;
		philos[i].left_fork = &forks[i];
		if (i == setup->n_philo - 1)
			philos[i].right_fork = &forks[0];
		else
		{
			pthread_mutex_init(&forks[i + 1], NULL);
			philos[i].right_fork = &forks[i + 1];
		}
		pthread_create(&thread_ids[i], NULL, philo_start, &philos[i]);
	}
}
