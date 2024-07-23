/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:08:22 by enes              #+#    #+#             */
/*   Updated: 2024/01/30 20:59:59 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static bool	not_number(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

long	ft_atoi(char *str)
{
	long	nb;
	int		i;

	if (!str || ft_strlen(str) > 10 || str[0] == '0')
		return (-1);
	i = 0;
	nb = 0;
	while (str[i])
	{
		if (not_number(str[i]) == false)
			return (-1);
		nb = nb * 10 + (str[i] - '0');
		if (nb > INT_MAX || nb < 0)
			return (-1);
		i++;
	}
	if (nb > INT_MAX || nb < 0)
		return (-1);
	if (nb == 0)
		return (-1);
	return (nb);
}

size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		write(2, "gettime error\n", 15);
		return (0);
	}
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(size_t ms, t_philolist *philo, int j, size_t eaten)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < ms)
	{
		usleep(50);
		if (is_dead(philo) == true)
			break ;
		if ((get_time() - eaten) >= (unsigned long) philo->time_to_die)
		{
			pthread_mutex_lock(&philo->mutexes.check_pulse);
			philo->dead = j;
			pthread_mutex_unlock(&philo->mutexes.check_pulse);
			break ;
		}
	}
}
