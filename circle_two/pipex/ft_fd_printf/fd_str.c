/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:35:18 by ecaliska          #+#    #+#             */
/*   Updated: 2023/11/28 21:06:24 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fd_printf.h"

int	fd_str(const char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return (write(fd, "(null)", 6));
	while (s[i])
	{
		fd_print(s[i], fd);
		i++;
	}
	return (i);
}
