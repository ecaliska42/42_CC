/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:47:52 by ecaliska          #+#    #+#             */
/*   Updated: 2024/01/30 20:52:51 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	create_loop(t_philolist *philo, pthread_t *t)
{
	int	i;

	i = 0;
	while (i < philo->p_count)
	{
		if (pthread_create(&t[i], NULL, &routine, philo))
		{
			pthread_mutex_lock(&philo->mutexes.flag);
			ft_putstr_fd("Error on creating threads\n", 2);
			philo->write_flag = WRITTEN;
			philo->dead = 6;
			pthread_mutex_unlock(&philo->mutexes.flag);
			break ;
		}
		i++;
	}
	return (i);
}

static int	join_loop(t_philolist *philo, pthread_t *t, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (pthread_join(t[j], NULL))
		{
			free(t);
			exit_philosophers(philo, ERROR);
			return (ft_putstr_fd("Error on joining threads\n", 2));
		}
		j++;
	}
	free(t);
	return (SUCCESS);
}

int	create_threads(t_philolist *philo)
{
	pthread_t	*t;
	int			i;

	t = malloc(sizeof(pthread_t) * philo->p_count);
	if (!t)
		return (ft_putstr_fd("MALLOC FAILED\n", 2));
	i = create_loop(philo, t);
	return (join_loop(philo, t, i));
}
