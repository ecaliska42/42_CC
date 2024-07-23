/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:36:51 by ecaliska          #+#    #+#             */
/*   Updated: 2023/11/28 21:06:34 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fd_printf.h"

int	fd_hexadecimal(unsigned int nb, int x, int fd)
{
	char	*s;
	int		length;
	char	*str;

	s = "0123456789ABCDEF";
	if (x == 'x')
		s = "0123456789abcdef";
	if (nb == 0)
		return (write (fd, "0", 1));
	length = fd_len(nb);
	str = (char *)malloc(sizeof(char) * length + 1);
	if (!str)
		return (0);
	str[length] = '\0';
	while (nb != 0)
	{
		str[--length] = s[nb % 16];
		nb /= 16;
	}
	while (str[length])
		fd_print(str[length++], fd);
	free (str);
	return (length);
}
