/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_unsigned_putnbr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:24:18 by ecaliska          #+#    #+#             */
/*   Updated: 2023/11/28 21:05:51 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fd_printf.h"

int	ft_fd_unsigned_putnbr(unsigned int nb, int fd)
{
	int	i;

	i = 0;
	if (nb > 9)
	{
		i += ft_fd_unsigned_putnbr(nb / 10, fd);
		i += ft_fd_unsigned_putnbr(nb % 10, fd);
	}
	else if (nb < 10)
		i += fd_print(nb + '0', fd);
	return (i);
}
