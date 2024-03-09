/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:34:28 by ggispert          #+#    #+#             */
/*   Updated: 2024/03/05 11:54:05 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_setup
{
	int	n_philo;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	n_times_eat;
}				t_setup;

typedef struct s_philo
{
	int	id;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
} t_philo;

enum {
    TAKE_FORK = 1,
    LEAVE_FORK = 2,
    EAT = 3,
    THINK = 4,
    SLEEP = 5,
    DIE = 6,
};

int		main(int argc, char **argv);

// Parsing and usage
int		parser(int argc, char **argv, t_setup *setup);
int		usage(int error_code);
int		get_parameter(int param_index, char *arg, t_setup *setup);
int		get_int(char *arg, int *num);

// Thread init
void	init(t_setup *setup, pthread_t *thread_ids, pthread_mutex_t *forks, t_philo	*philos);

// Philosophers actions
int	_think(t_philo *philo);
int	_eat(t_philo *philo);
int	_die();
int	_sleep(t_philo *philo);

// Utils
void	print_message(int msg_type, int id);
long	get_time();

// String utils
size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);

#endif