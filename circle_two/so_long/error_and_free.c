/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:59:40 by ecaliska          #+#    #+#             */
/*   Updated: 2023/12/18 23:05:16 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>
#include <stdlib.h>

void	freedouble(char **head)
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

void	free_stack(t_sllist *game)
{
	if (game->map)
	{
		free(game->map);
		game->map = NULL;
	}
	if (game->new_map)
	{
		freedouble(game->new_map);
		game->new_map = NULL;
	}
	if (game->clone)
	{
		freedouble(game->clone);
		game->clone = NULL;
	}
	exit(EXIT_SUCCESS);
}

void	free_mlx(t_sllist *game)
{
	if (game->mlx)
	{
		free(game->mlx);
		game->mlx = NULL;
	}
	free_stack(game);
}

/**
 * This function, `close_frame`, is used to clean up and close the game window.
 *
 * The function then ends the game loop by calling `mlx_loop_end`.
 */
int	close_frame(t_sllist *game, int message)
{
	if (message == 1)
		ft_printf("%sCONGRATULATIONS YOU FOUND ALL RUBIES AND WON\n", GREEN);
	mlx_loop_end(game->mlx);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->coin)
		mlx_destroy_image(game->mlx, game->coin);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->karakter)
		mlx_destroy_image(game->mlx, game->karakter);
	if (game->image)
		mlx_destroy_window(game->mlx, game->image);
	mlx_destroy_display(game->mlx);
	free_mlx(game);
	return (0);
}
