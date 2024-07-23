/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:51:14 by ecaliska          #+#    #+#             */
/*   Updated: 2023/12/09 17:35:48 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fd_printf/ft_fd_printf.h"
#include "libft/libft.h"
#include "pipex.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	child_main(char **av, char **envp, t_pipe_list *pix)
{
	int		infile;
	int		flag;

	flag = 0;
	close(pix->fd[0]);
	infile = open(av[1], O_RDONLY);
	if (infile < 0)
	{
		error(3, NULL, av);
		flag = 1;
	}
	if (flag == 0 && ft_strlen(av[2]) != 0)
	{
		execute_child_one(infile, pix, envp);
		write(2, av[2], ft_strlen(av[2]));
		write(2, ": command not found\n", 20);
		freepipe(pix);
	}
	else
	{
		close(pix->fd[1]);
		if (infile > 0)
			close(infile);
		freepipe(pix);
	}
}

static void	dup_error(t_pipe_list *pix)
{
	freedouble(pix->command, pix->path);
	perror("");
	exit(EXIT_FAILURE);
}

void	execute_child_one(int infile, t_pipe_list *pix, char **envp)
{
	int	j;

	j = 0;
	while (pix->command[j])
	{
		if (access(pix->command[j], 0) == 0)
		{
			if (dup2(infile, STDIN_FILENO) == -1)
				dup_error(pix);
			close(infile);
			if (dup2(pix->fd[1], STDOUT_FILENO) == -1)
				dup_error(pix);
			close(pix->fd[1]);
			execve(pix->command[j], pix->path, envp);
			perror("");
			freepipe(pix);
		}
		j++;
	}
}
