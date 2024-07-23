/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorhandling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:48:30 by ecaliska          #+#    #+#             */
/*   Updated: 2023/12/09 17:41:31 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fd_printf/ft_fd_printf.h"
#include "pipex.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	freedouble(char **head1, char **head2)
{
	int	i;

	i = 0;
	if (head1)
	{
		while (head1[i])
		{
			free(head1[i]);
			head1[i++] = NULL;
		}
		free(head1);
		head1 = NULL;
	}
	i = 0;
	if (head2)
	{
		while (head2[i])
		{
			free(head2[i]);
			head2[i++] = NULL;
		}
		free(head2);
		head2 = NULL;
	}
}

void	free_two(char **head)
{
	int	i;

	i = 0;
	while (head[i])
	{
		free(head[i]);
		i++;
	}
	free(head);
}

void	freepipe(t_pipe_list *pix)
{
	if (pix->command != NULL)
	{
		free_two(pix->command);
		pix->command = NULL;
	}
	if (pix->command2 != NULL)
	{
		free_two(pix->command2);
		pix->command2 = NULL;
	}
	if (pix->path != NULL)
	{
		free_two(pix->path);
		pix->path = NULL;
	}
	if (pix->path2 != NULL)
	{
		free_two(pix->path2);
		pix->path2 = NULL;
	}
	if (pix->fd[0] > 0)
		close(pix->fd[0]);
	if (pix->fd[1] > 0)
		close(pix->fd[1]);
}

void	error(int error_number, t_pipe_list *pix, char **av)
{
	if (error_number == 1)
	{
		write(2, "pipex: ", 7);
		write(2, av[4], ft_strlen(av[4]));
		write(2, ": ", 2);
		perror("");
		freepipe(pix);
		exit (EXIT_FAILURE);
	}
	if (error_number == 2)
	{
		perror("Error");
		freepipe(pix);
		exit (EXIT_FAILURE);
	}
	if (error_number == 3)
	{
		write(2, "pipex: ", 7);
		write(2, av[1], ft_strlen(av[1]));
		write(2, ": ", 2);
		perror("");
	}
}

void	malloc_fail(t_pipe_list *pix)
{
	perror("one malloc of fillstruct failed\n");
	freepipe(pix);
	exit(EXIT_FAILURE);
}
