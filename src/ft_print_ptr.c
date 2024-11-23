/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:38:19 by loicpapon         #+#    #+#             */
/*   Updated: 2024/11/23 14:34:58 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_ptr(void *ptr, t_flags *flags)
{
	int	count;
	int	num_len;
	int	padding;

	count = 0;
	if (!ptr && flags->precision == 0)
		num_len = 2;
	else
		num_len = ft_hexlen_ptr((unsigned long)ptr) + 2;
	padding = 0;
	if (flags->precision > (num_len - 2))
		padding = flags->precision - (num_len - 2);
	num_len += padding;
	if (!flags->minus && flags->width > num_len)
	{
		if (flags->zero)
			count += print_width(flags->width, num_len, '0');
		else
			count += print_width(flags->width, num_len, ' ');
	}
	count += write(1, "0x", 2);
	if (padding > 0)
		count += print_width(padding, 0, '0');
	if (ptr || flags->precision != 0)
		count += ft_putnbr_base((unsigned long)ptr, "0123456789abcdef");
	if (flags->minus && flags->width > num_len)
		count += print_width(flags->width, num_len, ' ');
	return (count);
}


