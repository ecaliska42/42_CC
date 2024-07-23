/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:43:53 by ecaliska          #+#    #+#             */
/*   Updated: 2024/01/29 18:20:24 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	pick_fork(t_philolist *p, int j)
{
	if (j % 2 == 0)
	{
		pthread_mutex_lock(&p->mutexes.m_forks[j % p->p_count]);
		pthread_mutex_lock(&p->mutexes.m_forks[(j + 1) % p->p_count]);
	}
	else
	{
		pthread_mutex_lock(&p->mutexes.m_forks[(j + 1) % p->p_count]);
		pthread_mutex_lock(&p->mutexes.m_forks[j % p->p_count]);
	}
}

static void	put_fork(t_philolist *p, int j)
{
	if (j % 2 == 0)
	{
		pthread_mutex_unlock(&p->mutexes.m_forks[j % p->p_count]);
		pthread_mutex_unlock(&p->mutexes.m_forks[(j + 1) % p->p_count]);
	}
	else
	{
		pthread_mutex_unlock(&p->mutexes.m_forks[(j + 1) % p->p_count]);
		pthread_mutex_unlock(&p->mutexes.m_forks[j % p->p_count]);
	}
}

void	eat(t_philolist *philo, size_t *eaten, int j, size_t start2)
{
	pick_fork(philo, j);
	print_message((get_time() - start2), j + 1, EATING, philo);
	philo->status[j] = EATING;
	ft_usleep(philo->time_to_eat, philo, j, *eaten);
	put_fork(philo, j);
	*eaten = get_time();
	philo->max_eat[j]--;
}

void	ft_sleep(t_philolist *philo, int j, size_t eaten, size_t start)
{
	if (philo->status[j] == EATING)
	{
		philo->status[j] = SLEEPING;
		print_message((get_time() - start), j + 1, SLEEPING, philo);
		ft_usleep(philo->time_to_sleep, philo, j, eaten);
	}
}

void	thinking(t_philolist *philo, int j, size_t start)
{
	if (philo->status[j] == SLEEPING)
	{
		print_message(get_time() - start, j + 1, THINKING, philo);
		philo->status[j] = THINKING;
		please_wait(philo);
	}
}
