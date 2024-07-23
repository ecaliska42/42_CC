/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:27:02 by ecaliska          #+#    #+#             */
/*   Updated: 2023/12/18 21:15:25 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "so_long.h"
#include <stdlib.h>

void	count_in_struct(t_sllist *game)
{
	game->coins = count_in_lines(game, 'C');
	game->coins_for_flood_fill = game->coins;
	game->line_count = count_in_lines(game, '\n');
	game->player_count = count_in_lines(game, 'P');
	game->exit_count = count_in_lines(game, 'E');
	game->exit2 = game->exit_count;
	game->width = 64;
	game->height = 64;
	game->moves = 0;
}

void	initialize_struct(t_sllist *game, char **av)
{
	ft_bzero(game, sizeof (*game));
	game->map = fill_the_map(game, av[1]);
	if (!game->map)
		free_stack(game);
	game->len_of_map = ft_strlen(game->map) - 1;
	if (game->map[game->len_of_map] == '\n')
	{
		ft_putstr_fd("\033[0;31mERROR\nINVALID MAP\n", 2);
		free_stack(game);
	}
	if (multiple_new_lines(game) == -1)
	{
		ft_putstr_fd("\033[0;31mERROR\nINVALID MAP\n", 2);
		free_stack(game);
	}
	game->new_map = ft_split(game->map, '\n');
	if (!game->new_map)
		free_stack(game);
	game->clone = ft_split(game->map, '\n');
	if (!game->clone)
		free_stack(game);
	count_in_struct(game);
}

void	intitialize_mlx(t_sllist *game)
{
	game->floor = mlx_xpm_file_to_image(game->mlx, "img/bg.xpm",
			&game->width, &game->height);
	if (!game->floor)
		close_frame(game, 0);
	game->karakter = mlx_xpm_file_to_image(game->mlx, "img/front_char.xpm",
			&game->width, &game->height);
	if (!game->karakter)
		close_frame(game, 0);
	game->wall = mlx_xpm_file_to_image(game->mlx, "img/block.xpm",
			&game->width, &game->height);
	if (!game->wall)
		close_frame(game, 0);
	game->exit = mlx_xpm_file_to_image(game->mlx, "img/endgate.xpm",
			&game->width, &game->height);
	if (!game->exit)
		close_frame(game, 0);
	game->coin = mlx_xpm_file_to_image(game->mlx, "img/coin.xpm",
			&game->width, &game->height);
	if (!game->coin)
		close_frame(game, 0);
}
