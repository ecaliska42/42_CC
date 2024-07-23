/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:47:11 by ecaliska          #+#    #+#             */
/*   Updated: 2023/12/09 17:38:25 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fd_printf/ft_fd_printf.h"
#include "libft/libft.h"
#include "pipex.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	fill_struct(t_pipe_list *pix, char **av, char **envp)
{
	initialize_struct(pix);
	pix->command = get_command_sndtry(av[2], envp);
	if (pix->command == NULL)
		malloc_fail(pix);
	pix->path = ft_split(av[2], ' ');
	if (pix->path == NULL)
		malloc_fail(pix);
	pix->command2 = get_command_sndtry(av[3], envp);
	if (pix->command2 == NULL)
		malloc_fail(pix);
	pix->path2 = ft_split(av[3], ' ');
	if (pix->path2 == NULL)
		malloc_fail(pix);
}

char	**get_paths(char **envp, char *first)
{
	int		i;
	int		j;
	char	**paths;

	i = 0;
	j = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0 && envp[i])
		i++;
	if (!envp[i])
		exit(-1);
	paths = ft_split(envp[i], ':');
	if (!paths)
		return (NULL);
	while (paths[j])
	{
		paths[j] = trim_paths(paths[j], first);
		if (paths[j] == NULL)
		{
			free_until(paths, j);
			return (NULL);
		}
		j++;
	}
	return (paths);
}

char	**full_path(char *av)
{
	char	**ret;

	ret = ft_calloc(sizeof(char *), 2);
	if (!ret)
		return (NULL);
	ret[0] = ft_strdup(av);
	if (!ret[0])
		return (NULL);
	ret[1] = NULL;
	return (ret);
}

char	**get_command_sndtry(char *av, char **envp)
{
	char	**ret;
	char	**splitting;

	if (access(av, X_OK | F_OK) == 0 || ft_strlen(av) == 0)
		return (full_path(av));
	splitting = ft_split(av, ' ');
	if (!splitting)
		return (NULL);
	ret = get_paths(envp, splitting[0]);
	if (!ret)
	{
		freedouble(splitting, NULL);
		return (NULL);
	}
	freedouble(splitting, NULL);
	return (ret);
}

char	*trim_paths(char *paths, char *first)
{
	paths = ft_strtrim(paths, "PATH=");
	if (!paths)
		return (NULL);
	paths = ft_strjoin(paths, "/");
	if (!paths)
	{
		free(paths);
		return (NULL);
	}
	paths = ft_strjoin(paths, first);
	if (!paths)
	{
		free(paths);
		return (NULL);
	}
	return (paths);
}
