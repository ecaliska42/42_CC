/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:02:38 by ecaliska          #+#    #+#             */
/*   Updated: 2024/02/02 15:00:13 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*single(void *list)
{
	t_philolist	*philo;
	size_t		start;
	int			flag;

	philo = (t_philolist *)list;
	flag = 0;
	start = get_time();
	if (pthread_mutex_init(&philo->mutexes.flag, NULL))
	{
		ft_putstr_fd("Error on creatine mutex\n", 2);
		flag = 1;
	}
	pthread_mutex_lock(&philo->mutexes.flag);
	if (flag == 0)
		printf("%ld %d has taken a fork\n", get_time() - start, 1);
	pthread_mutex_unlock(&philo->mutexes.flag);
	while (flag == 0 && philo->dead == ALIVE)
	{
		if ((get_time() - start) >= (unsigned long) philo->time_to_die)
			philo->dead = 1;
	}
	if (pthread_mutex_destroy(&philo->mutexes.flag))
		ft_putstr_fd("Error on destroying mutex\n", 2);
	return (NULL);
}

int	single_philo(t_philolist *philo)
{
	pthread_t	t;

	philo->start = get_time();
	if (pthread_create(&t, NULL, &single, philo))
	{
		free(philo->max_eat);
		free(philo->status);
		return (ft_putstr_fd("ERROR CREATING THREAD\n", 2));
	}
	if (pthread_join(t, NULL))
	{
		free(philo->max_eat);
		free(philo->status);
		return (ft_putstr_fd("ERROR JOINING THREAD\n", 2));
	}
	printf("%ld %d died\n", (get_time() - philo->start), philo->dead);
	free(philo->max_eat);
	free(philo->status);
	return (SUCCESS);
}
