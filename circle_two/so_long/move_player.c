/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:17:27 by ecaliska          #+#    #+#             */
/*   Updated: 2023/12/18 19:43:43 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "so_long.h"

void	move_player_down(t_sllist *game)
{
	if (game->new_map[game->y_player_pos + 1][game->x_player_pos] == '0')
	{
		game->new_map[game->y_player_pos][game->x_player_pos] = '0';
		game->y_player_pos += 1;
		game->new_map[game->y_player_pos][game->x_player_pos] = 'P';
		ft_printf("MOVES: %d\n", ++game->moves);
	}
	else if (game->new_map[game->y_player_pos + 1][game->x_player_pos] == 'C')
	{
		game->new_map[game->y_player_pos][game->x_player_pos] = '0';
		game->y_player_pos += 1;
		game->new_map[game->y_player_pos][game->x_player_pos] = 'P';
		game->coins--;
		ft_printf("MOVES: %d\n", ++game->moves);
	}
	else if (game->new_map[game->y_player_pos + 1][game->x_player_pos] == 'E')
	{
		if (game->coins != 0)
			return ((void)ft_printf("%sTHERE ARE STILL RUBIES LEFT\n", GREEN));
		ft_printf("MOVES: %d\n", ++game->moves);
		close_frame(game, 1);
	}
	return ;
}

void	move_player_right(t_sllist *game)
{
	if (game->new_map[game->y_player_pos][game->x_player_pos + 1] == '0')
	{
		game->new_map[game->y_player_pos][game->x_player_pos] = '0';
		game->x_player_pos += 1;
		game->new_map[game->y_player_pos][game->x_player_pos] = 'P';
		ft_printf("MOVES: %d\n", ++game->moves);
	}
	else if (game->new_map[game->y_player_pos][game->x_player_pos + 1] == 'C')
	{
		game->new_map[game->y_player_pos][game->x_player_pos] = '0';
		game->x_player_pos += 1;
		game->new_map[game->y_player_pos][game->x_player_pos] = 'P';
		game->coins--;
		ft_printf("MOVES: %d\n", ++game->moves);
	}
	else if (game->new_map[game->y_player_pos][game->x_player_pos + 1] == 'E')
	{
		if (game->coins != 0)
			return ((void)ft_printf("%sTHERE ARE STILL RUBIES LEFT\n", GREEN));
		ft_printf("MOVES: %d\n", ++game->moves);
		close_frame(game, 1);
	}
	return ;
}

void	move_player_up(t_sllist *game)
{
	if (game->new_map[game->y_player_pos - 1][game->x_player_pos] == '0')
	{
		game->new_map[game->y_player_pos][game->x_player_pos] = '0';
		game->y_player_pos -= 1;
		game->new_map[game->y_player_pos][game->x_player_pos] = 'P';
		ft_printf("MOVES: %d\n", ++game->moves);
	}
	else if (game->new_map[game->y_player_pos - 1][game->x_player_pos] == 'C')
	{
		game->new_map[game->y_player_pos][game->x_player_pos] = '0';
		game->y_player_pos -= 1;
		game->new_map[game->y_player_pos][game->x_player_pos] = 'P';
		game->coins--;
		ft_printf("MOVES: %d\n", ++game->moves);
	}
	else if (game->new_map[game->y_player_pos - 1][game->x_player_pos] == 'E')
	{
		if (game->coins != 0)
			return ((void)ft_printf("%sTHERE ARE STILL RUBIES LEFT\n", GREEN));
		ft_printf("MOVES: %d\n", ++game->moves);
		close_frame(game, 1);
	}
	return ;
}

void	move_player_left(t_sllist *game)
{
	if (game->new_map[game->y_player_pos][game->x_player_pos - 1] == '0')
	{
		game->new_map[game->y_player_pos][game->x_player_pos] = '0';
		game->x_player_pos -= 1;
		game->new_map[game->y_player_pos][game->x_player_pos] = 'P';
		ft_printf("MOVES: %d\n", ++game->moves);
	}
	else if (game->new_map[game->y_player_pos][game->x_player_pos - 1] == 'C')
	{
		game->new_map[game->y_player_pos][game->x_player_pos] = '0';
		game->x_player_pos -= 1;
		game->new_map[game->y_player_pos][game->x_player_pos] = 'P';
		game->coins--;
		ft_printf("MOVES: %d\n", ++game->moves);
	}
	else if (game->new_map[game->y_player_pos][game->x_player_pos - 1] == 'E')
	{
		if (game->coins != 0)
			return ((void)ft_printf("%sTHERE ARE STILL RUBIES LEFT\n", GREEN));
		ft_printf("MOVES: %d\n", ++game->moves);
		close_frame(game, 1);
	}
	return ;
}

/*
	ESCAPE IS 65307
		W IS 119
		A IS 97
		S IS 115
		D IS 100
	ARROWKEYS ARE:
		UP IS 653629
		RIGHT IS 65361
		DOWN IS 65364
		LEFT IS 65363 
*/
int	key_press(int key, t_sllist *game)
{
	if (key == 65307)
		close_frame(game, 0);
	if (key == 119 || key == 65362)
		move_player_up(game);
	else if (key == 97 || key == 65361)
		move_player_left(game);
	else if (key == 115 || key == 65364)
		move_player_down(game);
	else if (key == 100 || key == 65363)
		move_player_right(game);
	return (0);
}
