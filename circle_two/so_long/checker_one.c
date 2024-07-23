/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:48:43 by ecaliska          #+#    #+#             */
/*   Updated: 2023/12/18 23:05:07 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"
#include <unistd.h>

/*
	I check if the mapname is valid
*/
int	valid_name(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (len > 4)
	{
		if (map_name[len - 1] != 'r')
			return (-1);
		if (map_name[len - 2] != 'e')
			return (-1);
		if (map_name[len - 3] != 'b')
			return (-1);
		if (map_name[len - 4] != '.')
			return (-1);
		return (1);
	}
	return (-1);
}

/*
	This function, `valid_map`, is used to validate the game map.
*/
void	valid_map(t_sllist *game)
{
	count_test(game);
	square_test(game);
	check_for_forbidden_character(game);
	if (check_map_validity(game) == -2)
	{
		ft_printf("%s", RED);
		ft_putstr_fd("ERROR\nYOUR MAP IS NOT BORDERED WITH 1's\n", 2);
		free_stack(game);
	}
}

void	count_test(t_sllist *game)
{
	int	flag;

	flag = 0;
	if (game->coins == 0)
	{
		ft_printf("%s", RED);
		ft_putstr_fd("ERROR\nYOUR MAP HAS NO COINS\n", 2);
		flag = -1;
	}
	if (game->player_count != 1)
	{
		ft_printf("%s", RED);
		ft_putstr_fd("ERROR\nTHERE IS NO OR MORE THEN 1 PLAYER\n", 2);
		flag = -1;
	}
	if (game->exit_count != 1)
	{
		ft_printf("%s", RED);
		ft_putstr_fd("ERROR\nTHERE IS NO OR MORE THEN 1 EXIT\n", 2);
		flag = -1;
	}
	if (flag == -1)
		free_stack(game);
}

void	square_test(t_sllist *game)
{
	int	i;

	i = 0;
	if (!game->new_map || multiple_new_lines(game) == -1)
	{
		ft_printf("%s", RED);
		ft_putstr_fd("ERROR\nINVALID MAP\n", 2);
		free_stack(game);
	}
	if (ft_strlen(game->new_map[0]) - 1 == (size_t)game->line_count)
	{
		ft_printf("%s", RED);
		ft_putstr_fd("ERROR\nTHE MAP HAS TO BE A RECTANGLE\n", 2);
		free_stack(game);
	}
	while (game->new_map[i])
	{
		if (ft_strlen(game->new_map[i]) != ft_strlen(game->new_map[0]))
		{
			ft_printf("%s", RED);
			ft_putstr_fd("ERROR\nTHE MAP IS NOT A RECTANGLE\n", 2);
			free_stack(game);
		}
		i++;
	}
}

/**
 * This function, `check_map_validity`, is used to validate the game map by
 * checking if it is bordered with '1's.
 */
int	check_map_validity(t_sllist *game)
{
	int	i;
	int	end;

	i = 0;
	end = ft_strlen(game->new_map[0]) - 1;
	while (game->new_map[0][i])
	{
		if (game->new_map[0][i] != '1')
			return (-2);
		if (game->new_map[game->line_count][i] != '1')
			return (-2);
		i++;
	}
	i = 0;
	while (game->new_map[i])
	{
		if (game->new_map[i][0] != '1' || game->new_map[i][end] != '1')
			return (-2);
		i++;
	}
	return (0);
}
