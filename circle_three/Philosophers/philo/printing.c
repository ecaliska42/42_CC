/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:51:10 by ecaliska          #+#    #+#             */
/*   Updated: 2024/01/29 17:22:15 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_message(size_t time, int phil, int status, t_philolist *philo)
{
	pthread_mutex_lock(&philo->mutexes.flag);
	if (status == EATING && philo->write_flag == NOT_WRITTEN)
	{
		pthread_mutex_lock(&philo->mutexes.write_mutex);
		printf("%ld %d has taken a fork\n", time, phil);
		printf("%ld %d has taken a fork\n", time, phil);
		printf("%ld %d is eating\n", time, phil);
		pthread_mutex_unlock(&philo->mutexes.write_mutex);
	}
	else if (status == THINKING && philo->write_flag == NOT_WRITTEN)
	{
		pthread_mutex_lock(&philo->mutexes.write_mutex);
		printf("%ld %d is thinking\n", time, phil);
		pthread_mutex_unlock(&philo->mutexes.write_mutex);
	}
	else if (status == SLEEPING && philo->write_flag == NOT_WRITTEN)
	{
		pthread_mutex_lock(&philo->mutexes.write_mutex);
		printf("%ld %d is sleeping\n", time, phil);
		pthread_mutex_unlock(&philo->mutexes.write_mutex);
	}
	pthread_mutex_unlock(&philo->mutexes.flag);
}

void	print_death(t_philolist *philo, int philosopher, size_t time)
{
	pthread_mutex_lock(&philo->mutexes.flag);
	if (philo->write_flag == NOT_WRITTEN && philo->max_eat[philosopher] != 0)
	{
		printf("%ld %d died\n", (get_time() - time), philosopher + 1);
		philo->write_flag = WRITTEN;
	}
	pthread_mutex_unlock(&philo->mutexes.flag);
}

int	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	if (!str)
		return (write(fd, "NO STRING FOR FT_PUTSTR_FD\n", 28));
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
	return (ERROR);
}
