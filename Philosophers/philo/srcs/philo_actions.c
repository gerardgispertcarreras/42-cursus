/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:21:13 by ggispert          #+#    #+#             */
/*   Updated: 2024/03/09 13:33:41 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	_sleep(t_philo *philo)
{
	print_message(SLEEP, philo->id);
	usleep(10000*1000);
	return (EXIT_SUCCESS);
}

int	_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_message(TAKE_FORK, philo->id);
	pthread_mutex_lock(philo->right_fork);
	print_message(TAKE_FORK, philo->id);
	print_message(EAT, philo->id);
	usleep(3000*1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (EXIT_SUCCESS);
}

int	_think(t_philo *philo)
{
	print_message(THINK, philo->id);
	return (EXIT_SUCCESS);
}

int	_die()
{
	return (EXIT_SUCCESS);
}
