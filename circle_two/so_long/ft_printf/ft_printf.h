/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:40:49 by ecaliska          #+#    #+#             */
/*   Updated: 2023/09/30 16:56:36 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>

int	print(unsigned char c);
int	str(const char *s);
int	len(unsigned long long nb);
int	adress(void *point);
int	hexadecimal(unsigned int nb, int x);
int	ft_printf(const char *s, ...);
int	ft_putnbr(int nb);
int	ft_unsigned_putnbr(unsigned int nb);

#endif
