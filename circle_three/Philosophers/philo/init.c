/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:00:04 by ecaliska          #+#    #+#             */
/*   Updated: 2024/02/02 15:01:36 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	initilize_mallocs(t_philolist *philo)
{
	philo->max_eat = malloc(sizeof(int) * philo->p_count);
	if (!philo->max_eat)
		return (ft_putstr_fd("MALLOC FAIL\n", 2));
	philo->status = malloc(sizeof(int) * philo->p_count);
	if (!philo->status)
	{
		free(philo->max_eat);
		return (ft_putstr_fd("MALLOC FAIL\n", 2));
	}
	return (SUCCESS);
}

int	initialize_struct(t_philolist *philo, char **av, int ac)
{
	philo->p_count = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo->eat = ft_atoi(av[5]);
	else
		philo->eat = -2;
	if (wrong_input(philo) != SUCCESS)
		return (ERROR);
	philo->fork_count = philo->p_count;
	philo->id = 0;
	philo->routine_loop = 0;
	philo->dead = ALIVE;
	philo->write_flag = NOT_WRITTEN;
	return (initilize_mallocs(philo));
}

int	initialize_mutexes(t_philolist *p)
{
	if (pthread_mutex_init(&p->mutexes.write_mutex, NULL))
	{
		ft_putstr_fd("Error on initilizing write mutex\n", 2);
		return (exit_philosophers(p, ERROR));
	}
	if (pthread_mutex_init(&p->mutexes.flag, NULL))
	{
		ft_putstr_fd("Error on initilizing flag mutex\n", 2);
		return (exit_philosophers(p, ERROR));
	}
	if (pthread_mutex_init(&p->mutexes.iterate_p, NULL))
	{
		ft_putstr_fd("Error on initilizing iterate_p mutex\n", 2);
		return (exit_philosophers(p, ERROR));
	}
	if (pthread_mutex_init(&p->mutexes.check_pulse, NULL))
	{
		ft_putstr_fd("Error on initilizing check_pulse mutex\n", 2);
		return (exit_philosophers(p, ERROR));
	}
	return (SUCCESS);
}

int	create_mutexes(t_philolist *p)
{
	int	j;

	j = 0;
	p->mutexes.m_forks = malloc(p->fork_count * sizeof(pthread_mutex_t));
	if (!p->mutexes.m_forks)
	{
		free(p->max_eat);
		free(p->status);
		return (ft_putstr_fd("MALLOC FAIL\n", 2));
	}
	while (j < p->p_count)
	{
		p->status[j] = THINKING;
		if (pthread_mutex_init(&p->mutexes.m_forks[j], NULL))
		{
			ft_putstr_fd("Error on initilizing mutex for forks\n", 2);
			return (exit_philosophers(p, ERROR));
		}
		p->max_eat[j] = p->eat;
		j++;
	}
	return (initialize_mutexes(p));
}

int	wrong_input(t_philolist *philo)
{
	if (philo->p_count <= 0)
		return (ft_putstr_fd("WRONG PHILOSOPHER COUNT\n", 2));
	if (philo->time_to_die <= 0)
		return (ft_putstr_fd("INCORRECT TIME TO DIE VALUE\n", 2));
	if (philo->time_to_eat <= 0)
		return (ft_putstr_fd("INCORRECT TIME TO EAT VALUE\n", 2));
	if (philo->time_to_sleep <= 0)
		return (ft_putstr_fd("INCORRECT TIME TO SLEEP VALUE\n", 2));
	if (philo->eat == 0 || philo->eat == -1)
		return (ft_putstr_fd("INCORRECT MAX EAT VALUE\n", 2));
	return (SUCCESS);
}
