/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:49:19 by ecaliska          #+#    #+#             */
/*   Updated: 2023/12/18 21:55:42 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

# define BUFFER_SIZE 100000

typedef struct s_character
{
	int		x_pos;
	int		y_pos;
	void	*character;
}	t_character;

typedef struct l_list
{
	char	*map;
	char	*temp;
	char	**new_map;
	char	**clone;
	int		x_player_pos;
	int		y_player_pos;
	int		x_exit_pos;
	int		y_exit_pos;
	int		len_of_map;
	int		coins;
	int		coins_for_flood_fill;
	int		line_count;
	int		player_count;
	int		exit_count;
	int		exit2;
	int		moves;
	/*
		mlx_data
	*/
	int		height;
	int		width;
	void	*mlx;
	void	*image;
	char	*adress;
	int		bits;
	int		line_length;
	int		endian;
	void	*coin;
	void	*karakter;
	void	*wall;
	void	*floor;
	void	*exit;
}	t_sllist;

/*
	CHECKER_ONE.C
*/
int		valid_name(char *map_name);
void	valid_map(t_sllist *game);
void	count_test(t_sllist *game);
void	square_test(t_sllist *game);
int		check_map_validity(t_sllist *game);
/*
	CHECKER_TWO.C
*/
int		correct_letters(char c);
void	check_for_forbidden_character(t_sllist *game);
void	flood_fill(t_sllist *game, int x, int y);
int		multiple_new_lines(t_sllist *game);
void	check_after_flood_fill(t_sllist *game);
/*
	SO_LONG_UTILS.C
*/
void	find_position(t_sllist *game);
int		count_in_lines(t_sllist *game, char symbol);
/*
	ERROR_AND_FREE.C
*/
void	freedouble(char **head);
void	free_stack(t_sllist *game);
void	free_mlx(t_sllist *game);
int		close_frame(t_sllist *game, int message);
/*
	MOVE_PLAYER.C
*/
void	move_player_down(t_sllist *game);
void	move_player_right(t_sllist *game);
void	move_player_up(t_sllist *game);
void	move_player_left(t_sllist *game);
int		key_press(int key, t_sllist *game);
/*
	READ_FILE.C
*/
char	*fill_the_map(t_sllist *game, char *av);
/*
	CHECK_IMG.C
*/
void	missin_file(void);
void	check_mlx_files_two(void);
void	check_mlx_files(void);
/*
	INITIALIZE.C
*/
void	initialize_struct(t_sllist *game, char **av);
void	intitialize_mlx(t_sllist *game);
/*
	so_long functions
*/

#endif