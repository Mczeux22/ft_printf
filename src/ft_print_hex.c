/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:37:16 by loicpapon         #+#    #+#             */
/*   Updated: 2024/11/23 14:14:53 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_hex_with_flags(unsigned int n, char format, t_flags *flags)
{
	int		count;
	int		num_len;
	char	*base;

	count = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else if (format == 'X')
		base = "0123456789ABCDEF";
	else
		return (0);
	num_len = ft_hexlen(n);
	if (flags->hash && n != 0)
		num_len += 2;
	if (!flags->minus && !flags->zero)
		count += print_width(flags->width, num_len, ' ');
	if (flags->hash && n != 0)
	{
		if (format == 'x')
			count += write(1, "0x", 2);
		else if (format == 'X')
			count += write(1, "0X", 2);
	}
	if (flags->zero && !flags->minus)
		count += print_width(flags->width, num_len, '0');
	count += ft_putnbr_base(n, base);
	if (flags->minus)
		count += print_width(flags->width, num_len, ' ');
	return (count);
}

