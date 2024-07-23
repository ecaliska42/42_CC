/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_putnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:23:41 by ecaliska          #+#    #+#             */
/*   Updated: 2023/11/28 21:06:04 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fd_printf.h"

int	ft_fd_putnbr(int nb, int fd)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
		return (write(fd, "-2147483648", 11));
	if (nb < 0 && nb > -2147483648)
	{
		i += fd_print('-', fd);
		nb *= -1;
	}
	if (nb > 9)
	{
		i += ft_fd_putnbr(nb / 10, fd);
		i += ft_fd_putnbr(nb % 10, fd);
	}
	else if (nb < 10 && nb >= 0)
		i += fd_print(nb + '0', fd);
	return (i);
}
