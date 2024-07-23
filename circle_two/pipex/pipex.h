/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:27:45 by ecaliska          #+#    #+#             */
/*   Updated: 2023/12/09 17:38:32 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "ft_fd_printf/ft_fd_printf.h"
# include <ctype.h>
# include <errno.h>

typedef struct t_plist
{
	char	**command;
	char	**path;
	char	**command2;
	char	**path2;
	int		fd[2];
	pid_t	id;
	pid_t	id2;
}	t_pipe_list;

void	free_until(char **head, int x);
void	initialize_struct(t_pipe_list *pix);
void	parent(t_pipe_list *pix, char **av, char **envp);
void	fill_struct(t_pipe_list *pix, char **av, char **envp);
char	**get_paths(char **envp, char *first);
char	**full_path(char *av);
char	**get_command_sndtry(char *av, char **envp);
char	*trim_paths(char *paths, char *first);
void	child_main(char **av, char **envp, t_pipe_list *pix);
void	execute_child_one(int infile, t_pipe_list *pix, char **envp);
void	child_main_two(char **av, char **envp, t_pipe_list *pix);
void	execute_chile_tw(int outfile, t_pipe_list *pix, char **envp);
void	freedouble(char **head1, char **head2);
void	freepipe(t_pipe_list *pix);
void	error(int error_number, t_pipe_list *pix, char **av);
void	malloc_fail(t_pipe_list *pix);

#endif