/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:44:04 by ecaliska          #+#    #+#             */
/*   Updated: 2023/12/18 23:09:38 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "so_long.h"
/**
 *	This function, `put_image`, is used to render different types of game tiles 
 *	on the screen.
 *
 * The `mlx_put_image_to_window` function from the MiniLibX library is used to
 * render the image on the screen.
 */
void	put_image(t_sllist *game, char tile, int *x, int *y)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->image,
			game->wall, *x * 64, *y * 64);
	else if (tile == '0')
		mlx_put_image_to_window(game->mlx, game->image,
			game->floor, *x * 64, *y * 64);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->image,
			game->coin, *x * 64, *y * 64);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->image,
			game->exit, *x * 64, *y * 64);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx, game->image,
			game->karakter, *x * 64, *y * 64);
}

/*
 * This function, `displayimage`, is used to render the game map on the screen.
*/
int	displayimage(t_sllist *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (game->new_map[y])
	{
		x = 0;
		while (game->new_map[y][x])
		{
			put_image(game, game->new_map[y][x], &x, &y);
			x++;
		}
		y++;
	}
	return (0);
}

/**
 * This function, `mlx_functions`, is used to initialize the MiniLibX library.
 *
 * The function first initializes the MiniLibX library by calling `mlx_init`
 *
 * the function creates a new window for the game by calling mlx_new_window.
 *
 * The function sets up the game loop by calling `mlx_loop_hook` and mlx_hook.
 * The `mlx_loop_hook` function sets the `displayimage` function as the hook 
 * function for the game loop, which means that `displayimage` will be called
 * every time the game loop iterates.
 *
 * The `mlx_hook` function sets the `key_press` function as the hook function
 * for key press events, which means that `key_press` will be called every time
 * a key is pressed.
 * The `mlx_hook` function also sets the `close_frame` function as the hook
 * function for the close event, which means that `close_frame` will be called
 * when the game window is closed.
 *
 * Finally, the function starts the game loop by calling `mlx_loop`.
 */
void	mlx_functions(t_sllist *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		free_stack(game);
	game->image = mlx_new_window(game->mlx, ft_strlen(game->new_map[0]) * 64,
			(game->line_count + 1) * 64, "TINY_RENDERED_PRINCESS");
	if (!game->image)
		close_frame(game, 0);
	intitialize_mlx(game);
	ft_printf("%sOH DEAR KNIGHT I'VE LOST ALL MY RUBIES ON MY HIKE", GREEN);
	ft_printf(" PLEASE FIND THEM ALL AND RETURN THEM TO ME\n");
	mlx_loop_hook(game->mlx, displayimage, game);
	mlx_hook(game->image, 2, 1, key_press, game);
	mlx_hook(game->image, 17, 0, close_frame, game);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	t_sllist	game;

	if (ac != 2 || valid_name(av[1]) == -1)
	{
		ft_printf("%s", RED);
		ft_putstr_fd("ERROR\nWRONG INPUT\n", 2);
		return (1);
	}
	check_mlx_files();
	initialize_struct(&game, av);
	valid_map(&game);
	find_position(&game);
	flood_fill(&game, game.x_player_pos, game.y_player_pos);
	check_after_flood_fill(&game);
	mlx_functions(&game);
	close_frame(&game, 0);
}
