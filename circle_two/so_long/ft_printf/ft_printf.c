/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:10:44 by ecaliska          #+#    #+#             */
/*   Updated: 2023/09/28 19:47:48 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	arguments(va_list my_list, const char s)
{
	if (s == 'c')
		return (print(va_arg(my_list, int)));
	else if (s == 's')
		return (str(va_arg(my_list, const char *)));
	else if (s == 'p')
		return (adress(va_arg(my_list, void *)));
	else if (s == 'd' || s == 'i')
		return (ft_putnbr(va_arg(my_list, int)));
	else if (s == 'u')
		return (ft_unsigned_putnbr(va_arg(my_list, unsigned int)));
	else if (s == 'x' || s == 'X')
		return (hexadecimal(va_arg(my_list, int), s));
	else if (s == '%')
		return (print('%'));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		length;
	va_list	my_list;

	i = 0;
	length = 0;
	va_start (my_list, s);
	if (!s)
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			length += arguments(my_list, s[i + 1]);
			i++;
		}
		else
			length += print(s[i]);
		i++;
	}
	va_end (my_list);
	return (length);
}
/*
#include <limits.h>

int	main(void)
{
	void	*p = NULL;
	//unsigned int	i;
	//void *nb = LONG_MAX;
	//i = UINT_MAX;
	//ft_printf("printf\t\t\t%p\n", i);
	printf("num:%d\n", ft_printf("%%%\n"));
	//printf("this is the printf\t%p\n", i);
	printf("orignum:%d\n", printf("%%%\n"));
	return (0);
}
*/
/*
•FIN	 %c Prints a single character.
•FIN	 %s Prints a string (as defined by the common C convention).
•FIN	 %p The void * pointer argument has to be printed in hexadecimal format.
•FIN	 %d Prints a decimal (base 10) number.
•FIN	 %i Prints an integer in base 10.
•FIN	 %u Prints an unsigned decimal (base 10) number.
•OKOK	 %x Prints a number in hexadecimal (base 16) lowercase format.
•OKOK	 %X Prints a number in hexadecimal (base 16) uppercase format.
•FIN	 %% Prints a percent sign.
*/
