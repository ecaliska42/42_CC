/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:02:56 by ecaliska          #+#    #+#             */
/*   Updated: 2024/02/02 15:00:42 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	is_dead(t_philolist *philo)
{
	pthread_mutex_lock(&philo->mutexes.check_pulse);
	if (philo->dead != ALIVE)
	{
		pthread_mutex_unlock(&philo->mutexes.check_pulse);
		return (true);
	}
	pthread_mutex_unlock(&philo->mutexes.check_pulse);
	return (false);
}

int	exit_philosophers(t_philolist *philo, int status)
{
	int	i;

	i = 0;
	while (i < philo->p_count)
	{
		if (pthread_mutex_destroy(&philo->mutexes.m_forks[i]))
			ft_putstr_fd("Error on destoying a mutex\n", 2);
		i++;
	}
	if (pthread_mutex_destroy(&philo->mutexes.write_mutex))
		ft_putstr_fd("Error on destoying a mutex\n", 2);
	if (philo->mutexes.m_forks)
		free(philo->mutexes.m_forks);
	if (philo->max_eat)
		free(philo->max_eat);
	if (philo->status)
		free(philo->status);
	if (pthread_mutex_destroy(&philo->mutexes.iterate_p))
		ft_putstr_fd("Error on destoying a mutex\n", 2);
	if (pthread_mutex_destroy(&philo->mutexes.flag))
		ft_putstr_fd("Error on destoying a mutex\n", 2);
	if (pthread_mutex_destroy(&philo->mutexes.check_pulse))
		ft_putstr_fd("Error on destoying a mutex\n", 2);
	return (status);
}

void	please_wait(t_philolist *philo)
{
	int	number;

	if (philo->time_to_eat - philo->time_to_sleep < 0)
		number = philo->time_to_sleep - philo->time_to_eat;
	else
		number = philo->time_to_eat - philo->time_to_sleep;
	if (philo->p_count % 2 == 1 && is_dead(philo) == false)
		usleep(1000 * (number) + 500);
}

bool	input_check(int ac)
{
	if (ac < 5)
	{
		write(2, "NOT ENOUGH ARGUMETS\n", 21);
		return (false);
	}
	if (ac > 6)
	{
		write(2, "TOO MANY ARGUMENTS\n", 20);
		return (false);
	}
	return (true);
}
