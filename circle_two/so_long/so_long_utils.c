/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:52:51 by ecaliska          #+#    #+#             */
/*   Updated: 2023/12/18 19:16:33 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_position(t_sllist *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->new_map[j])
	{
		i = 0;
		while (game->new_map[j][i])
		{
			if (game->new_map[j][i] == 'P')
			{
				game->x_player_pos = i;
				game->y_player_pos = j;
			}
			else if (game->new_map[j][i] == 'E')
			{
				game->x_exit_pos = i;
				game->y_exit_pos = j;
			}
			i++;
		}
		j++;
	}
}

/*
	I count all the symbols in my string and return the amount at the end
	like new lines or coins etc.
*/
int	count_in_lines(t_sllist *game, char symbol)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (game->map[i])
	{
		if (game->map[i] == symbol)
			counter++;
		i++;
	}
	return (counter);
}
