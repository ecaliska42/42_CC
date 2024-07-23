/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:57:24 by ecaliska          #+#    #+#             */
/*   Updated: 2023/12/18 21:17:50 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "so_long.h"
#include <string.h>

int	correct_letters(char c)
{
	if (c == 'C' || c == 'P' || c == '1' || c == '0' || c == 'E' || c == '\n')
		return (1);
	return (-1);
}

void	check_for_forbidden_character(t_sllist *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (correct_letters(game->map[i]) == -1)
		{
			ft_printf("%s", RED);
			ft_putstr_fd("ERROR\n", 2);
			ft_putstr_fd("THERE IS A NON VALID CHARACTER IN YOUR MAP", 2);
			ft_putstr_fd(" VALID CHARACTERS ARE 'C' 'P' '1' '0' AND 'E'\n", 2);
			free_stack(game);
		}
		i++;
	}
}

void	flood_fill(t_sllist *game, int x, int y)
{
	if (game->new_map[y][x] == '1')
		return ;
	if (game->clone[y][x] == 'X')
		return ;
	if (game->new_map[y][x] == '0')
		game->clone[y][x] = 'X';
	if (game->clone[y][x] == 'E')
	{
		game->clone[y][x] = 'X';
		game->exit2--;
		return ;
	}
	if (game->clone[y][x] == 'C')
	{
		game->clone[y][x] = 'X';
		game->coins_for_flood_fill--;
	}
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}

int	multiple_new_lines(t_sllist *game)
{
	int	i;

	i = 0;
	if (game->map[0] == '\n')
	{
		ft_printf("%s", RED);
		ft_putstr_fd("ERROR\nINVALID MAP\n", 2);
		free_stack(game);
	}
	while (game->map[i])
	{
		if (game->map[i] == '\n')
		{
			if (game->map[i + 1] == '\n' && game->map[i + 1])
				return (-1);
		}
		i++;
	}
	return (1);
}

void	check_after_flood_fill(t_sllist *game)
{
	int	len;

	len = ft_strlen(game->new_map[0]) * 64;
	if (game->exit2 != 0 || game->coins_for_flood_fill != 0)
	{
		ft_printf("%s", RED);
		ft_putstr_fd("ERROR:\nYOUR MAP IS NOT PLAYABLE\n", 2);
		free_stack(game);
	}
	if ((game->line_count) * 64 > 896 || len > 1920)
	{
		ft_printf("%s", RED);
		ft_putstr_fd("ERROR:\nYOUR MAP IS TOO BIG\n", 2);
		free_stack(game);
	}
}
