/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 20:41:36 by ecaliska          #+#    #+#             */
/*   Updated: 2024/01/30 20:52:58 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <stdbool.h>
# include <limits.h>

# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define ALIVE -1
# define NOT_WRITTEN 4
# define WRITTEN 5
# define SINGLE 6
# define SUCCESS 0
# define ERROR 1

typedef struct mutexes_list
{
	pthread_mutex_t	*m_forks;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	iterate_p;
	pthread_mutex_t	check_pulse;
	pthread_mutex_t	flag;
}	t_mlist;

typedef struct t_list
{
	size_t	start;
	int		p_count;
	int		time_to_eat;
	int		time_to_sleep;
	int		time_to_die;
	int		fork_count;
	int		eat;
	int		*max_eat;
	int		*status;
	int		dead;
	int		id;
	int		write_flag;
	int		routine_loop;
	t_mlist	mutexes;
}	t_philolist;

/*
	*UTILTIY.C
*/
long	ft_atoi(char *str);
size_t	get_time(void);
void	ft_usleep(size_t ms, t_philolist *philo, int j, size_t eaten);

/*
	*UTILITY2.C
*/
int		exit_philosophers(t_philolist *philo, int status);
bool	is_dead(t_philolist *philo);
void	please_wait(t_philolist *philo);
void	lock_print(t_philolist *philo, int error);
bool	input_check(int ac);
/*
	*SINGLE.C
*/
void	*single(void *list);
int		single_philo(t_philolist *philo);

/*
	*INIT.C
*/
int		initilize_mallocs(t_philolist *philo);
int		initialize_struct(t_philolist *philo, char **av, int ac);
int		create_mutexes(t_philolist *philo);
int		wrong_input(t_philolist *philo);

/*
	*ACTIONS.C
*/
void	eat(t_philolist *philo, size_t *start, int j, size_t start2);
void	ft_sleep(t_philolist *philo, int j, size_t eaten, size_t start);
void	thinking(t_philolist *philo, int j, size_t start);

/*
	*ROUTINE.C
*/
void	*routine(void *list);

/*
	*PRINTING.C
*/
void	print_death(t_philolist *philo, int philosopher, size_t time);
void	print_message(size_t time, int phil, int status, t_philolist *philo);
int		ft_putstr_fd(char *str, int fd);

/*
	*THREAD.C
*/
int		create_threads(t_philolist *philo);

#endif
