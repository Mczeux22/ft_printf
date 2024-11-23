/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:46:46 by loicpapon         #+#    #+#             */
/*   Updated: 2024/11/23 14:44:45 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_unsigned(unsigned int n, t_flags *flags)
{
	int	count;
	int	num_len;
	int	padding;

	count = 0;
	num_len = ft_numlen(n);
	padding = 0;
	if (flags->precision > num_len)
		num_len = flags->precision;
	if (flags->width > num_len)
	{
		if (flags->minus)
			count += print_width(flags->width, num_len, ' ');
		else if (flags->zero)
			count += print_width(flags->width, num_len, '0');
		else
			count += print_width(flags->width, num_len, ' ');
	}
	if (flags->precision > num_len)
		padding = flags->precision - num_len;
	count += print_width(padding, 0, '0');
	count += ft_putnbr(n);
	if (flags->minus && flags->width > num_len)
		count += print_width(flags->width, num_len, ' ');
	return (count);
}

