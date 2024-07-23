/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:52:23 by ecaliska          #+#    #+#             */
/*   Updated: 2023/12/09 17:40:44 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fd_printf/ft_fd_printf.h"
#include "pipex.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	child_main_two(char **av, char **envp, t_pipe_list *pix)
{
	int		outfile;
	int		flag;

	flag = 0;
	close(pix->fd[1]);
	if (ft_strlen(av[3]) == 0)
		flag = 1;
	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		error(1, pix, av);
	if (flag == 0)
	{
		execute_chile_tw(outfile, pix, envp);
		write(2, av[3], ft_strlen(av[3]));
		write(2, ": command not found\n", 20);
		freepipe(pix);
	}
	else
	{
		perror("");
		close(outfile);
		close(pix->fd[0]);
		freepipe(pix);
	}
}

static void	error_handling(t_pipe_list *pix)
{
	perror("");
	freepipe(pix);
	exit(EXIT_FAILURE);
}

void	execute_chile_tw(int outfile, t_pipe_list *pix, char **envp)
{
	int	x;

	x = 0;
	while (pix->command2[x])
	{
		if (access(pix->command2[x], 0) == 0)
		{
			if (dup2(pix->fd[0], STDIN_FILENO) == -1)
				error_handling(pix);
			close(pix->fd[0]);
			if (dup2(outfile, STDOUT_FILENO) == -1)
				error_handling(pix);
			close(outfile);
			execve(pix->command2[x], pix->path2, envp);
			perror("");
			break ;
		}
		x++;
	}
}
