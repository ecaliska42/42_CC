/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:40:49 by ecaliska          #+#    #+#             */
/*   Updated: 2023/11/28 21:11:56 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FD_PRINTF_H
# define FT_FD_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>

int	fd_print(unsigned char c, int fd);
int	fd_str(const char *s, int fd);
int	fd_len(unsigned long long nb);
int	fd_adress(void *point, int fd);
int	fd_hexadecimal(unsigned int nb, int x, int fd);
int	ft_fd_printf(int fd, const char *s, ...);
int	ft_fd_putnbr(int nb, int fd);
int	ft_fd_unsigned_putnbr(unsigned int nb, int fd);

#endif
