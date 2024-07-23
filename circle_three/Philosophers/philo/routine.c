/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:48:35 by ecaliska          #+#    #+#             */
/*   Updated: 2024/01/30 21:03:17 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *list)
{
	t_philolist	*philo;
	int			j;
	size_t		start;
	size_t		eaten;

	philo = (t_philolist *)list;
	pthread_mutex_lock(&philo->mutexes.iterate_p);
	j = philo->id;
	philo->id++;
	pthread_mutex_unlock(&philo->mutexes.iterate_p);
	if (j % 2 == 1)
		usleep(300);
	start = get_time();
	eaten = start;
	while (is_dead(philo) == false)
	{
		eat(philo, &eaten, j, start);
		if (philo->max_eat[j] == 0 || is_dead(philo) == true)
			break ;
		ft_sleep(philo, j, eaten, start);
		thinking(philo, j, start);
	}
	print_death(philo, j, start);
	return (NULL);
}
