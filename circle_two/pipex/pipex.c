/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:27:19 by ecaliska          #+#    #+#             */
/*   Updated: 2023/12/09 18:20:49 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "ft_fd_printf/ft_fd_printf.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void	free_until(char **head, int x)
{
	int	i;

	i = 0;
	if (head)
	{
		while (i < x)
		{
			free(head[i]);
			i++;
		}
		free(head);
	}
}

void	initialize_struct(t_pipe_list *pix)
{
	pix->command = NULL;
	pix->command2 = NULL;
	pix->path = NULL;
	pix->path2 = NULL;
	pix->id = 0;
	pix->id2 = 0;
}

void	parent(t_pipe_list *pix, char **av, char **envp)
{
	pix->id2 = fork();
	if (pix->id2 < 0)
		error(2, pix, NULL);
	else if (pix->id2 == 0)
		child_main_two(av, envp, pix);
	else
		freepipe(pix);
	waitpid(pix->id, NULL, 0);
	waitpid(pix->id2, NULL, 0);
	freepipe(pix);
}

int	main(int ac, char **av, char **envp)
{
	t_pipe_list	pix;

	if (envp[0] == NULL || !envp)
		return (EXIT_FAILURE);
	if (ac != 5)
		return (write(2, "./pipex file1 cmd1 cmd2 file2\n", 30));
	if (pipe(pix.fd) == -1)
	{
		write(2, "./pipex: pipe error: ", 21);
		perror("");
		return (EXIT_FAILURE);
	}
	fill_struct(&pix, av, envp);
	pix.id = fork();
	if (pix.id < 0)
		error(2, &pix, NULL);
	if (pix.id == 0)
		child_main(av, envp, &pix);
	else
		parent(&pix, av, envp);
	return (0);
}

/*
valgrind --show-leak-kinds=all --trace-children=yes 
./pipex input "grep Now" "/usr/bin/cat" outputs
./pipex input "cat" "cat" outputs
./pipex no_file "no function" "wc" outputs
*/
/*
valgrind --track-fds=yes --trace-children=yes --show-leak-kinds=all
 --leak-check=full 
./pipex infile cat ls outfile
*/