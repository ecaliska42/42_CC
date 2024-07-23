/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:34:15 by ecaliska          #+#    #+#             */
/*   Updated: 2024/01/30 18:55:44 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_philolist	philo;

	if (input_check(ac) == false)
	{
		ft_putstr_fd("./philo <philosopher count> <time to eat>", 2);
		return (ft_putstr_fd(" <time to sleep> <max eat>\n", 2));
	}
	if (initialize_struct(&philo, av, ac) != SUCCESS)
		return (ERROR);
	if (philo.p_count == 1)
		return (single_philo(&philo));
	if (create_mutexes(&philo) != SUCCESS)
		return (ERROR);
	create_threads(&philo);
	return (exit_philosophers(&philo, SUCCESS));
}
