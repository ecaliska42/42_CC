/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:22:32 by ecaliska          #+#    #+#             */
/*   Updated: 2024/04/26 11:09:15 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "so_long.h"
#include <unistd.h>

void	missin_file(void)
{
	ft_printf("%s", RED);
	write(2, "ERROR\n", 7);
	write(2, "AT LEAST ONE .XPM FILE IS MISSING", 34);
	write(2, " PLEASE MAKE SURE YOU HAVE EVERYTHING\n", 39);
	exit(1);
}

void	check_mlx_files_two(void)
{
	int	fd4;
	int	fd5;

	fd4 = open("img/endgate.xpm", O_RDWR);
	if (fd4 < 0)
		missin_file();
	fd5 = open("img/coin.xpm", O_RDWR);
	if (fd5 < 0)
	{
		close(fd4);
		missin_file();
	}
	close(fd4);
	close(fd5);
}

void	check_mlx_files(void)
{
	int	fd1;
	int	fd2;
	int	fd3;

	fd1 = open("img/bg copy.xpm", O_RDWR);
	if (fd1 < 0)
		missin_file();
	fd2 = open("img/front_char.xpm", O_RDWR);
	if (fd2 < 0)
	{
		close(fd1);
		missin_file();
	}
	fd3 = open("img/block.xpm", O_RDWR);
	if (fd3 < 0)
	{
		close(fd1);
		close(fd2);
		missin_file();
	}
	close(fd1);
	close(fd2);
	close(fd3);
	check_mlx_files_two();
}
