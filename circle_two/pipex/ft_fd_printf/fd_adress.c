/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_adress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:35:15 by ecaliska          #+#    #+#             */
/*   Updated: 2023/11/28 21:06:48 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fd_printf.h"

int	fd_adress(void *point, int fd)
{
	char				*s;
	int					length;
	char				*str;
	unsigned long long	p;

	p = (unsigned long long) point;
	if (p == 0)
		return (write(fd, "(nil)", 5));
	write (fd, "0x", 2);
	s = "0123456789abcdef";
	length = fd_len(p) + 1;
	str = (char *)malloc(sizeof(char) * length + 1);
	if (!str)
		return (0);
	str[length] = '\0';
	while (p != 0)
	{
		str[--length] = s[p % 16];
		p /= 16;
	}
	while (str[length])
		fd_print(str[length++], fd);
	free (str);
	return (length + 1);
}
