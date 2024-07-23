/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adress.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:35:15 by ecaliska          #+#    #+#             */
/*   Updated: 2023/09/28 18:36:21 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	adress(void *point)
{
	char				*s;
	int					length;
	char				*str;
	unsigned long long	p;

	p = (unsigned long long) point;
	if (p == 0)
		return (write(1, "(nil)", 5));
	write (1, "0x", 2);
	s = "0123456789abcdef";
	length = len(p) + 1;
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
		print(str[length++]);
	free (str);
	return (length + 1);
}
