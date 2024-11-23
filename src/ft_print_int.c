/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:46:14 by loicpapon         #+#    #+#             */
/*   Updated: 2024/11/23 12:27:37 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	print_width(int width, int len, char fill)
{
	int	count;

	count = 0;
	while (width-- > len)
		count += write(1, &fill, 1);
	return (count);
}

int	ft_print_int_with_flags(int n, t_flags *flags)
{
	int	count;
	int	num_len;

	num_len = ft_numlen(n);
	count = 0;
	if (flags->precision > num_len)
		num_len = flags->precision;
	if (flags->plus || flags->space || n < 0)
		num_len++;
	if (!flags->minus && !flags->zero)
		count += print_width(flags->width, num_len, ' ');
	if (n < 0)
		count += write(1, "-", 1);
	else if (flags->plus)
		count += write(1, "+", 1);
	else if (flags->space)
		count += write(1, " ", 1);
	if (flags->zero && !flags->minus)
		count += print_width(flags->width, num_len, '0');
	count += ft_putnbr(n);
	if (flags->minus)
		count += print_width(flags->width, num_len, ' ');
	return (count);
}
