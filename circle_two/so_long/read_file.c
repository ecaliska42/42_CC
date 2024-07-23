/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:24:37 by ecaliska          #+#    #+#             */
/*   Updated: 2023/12/18 19:14:51 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	no_file_descriptor(t_sllist *game)
{
	perror("");
	free(game->temp);
	exit(EXIT_FAILURE);
}

static void	malloc_fail(int fd, t_sllist *game)
{
	free(game->temp);
	close(fd);
	free_stack(game);
}

static void	*error_handling(int fd, t_sllist *game, char *line, int flag)
{
	if (flag == 1)
	{
		close(fd);
		free(game->temp);
		free(line);
		return (NULL);
	}
	if (flag == 2)
	{
		close(fd);
		free(line);
		return (NULL);
	}
	return (NULL);
}

char	*fill_the_map(t_sllist *game, char *av)
{
	char	*line;
	int		fd;
	int		count;

	game->temp = ft_strdup("");
	if (!game->temp)
		return (NULL);
	fd = open(av, O_RDONLY);
	if (fd < 0)
		no_file_descriptor(game);
	line = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!line)
		malloc_fail(fd, game);
	count = read(fd, line, BUFFER_SIZE);
	if (count <= 0)
		return (error_handling(fd, game, line, 1));
	game->temp = ft_strjoin(game->temp, line);
	if (!game->temp)
		return (error_handling(fd, game, line, 2));
	close(fd);
	free(line);
	return (game->temp);
}
