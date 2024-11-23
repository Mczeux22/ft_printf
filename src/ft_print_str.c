/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:45:59 by loicpapon         #+#    #+#             */
/*   Updated: 2024/11/23 14:09:48 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_width(int width, int len, char fill)
{
	int	count;

	count = 0;
	while (width > len)
	{
		count += write(1, &fill, 1);
		width--;
	}
	return (count);
}

int	ft_print_str_with_flags(const char *str, t_flags *flags)
{
	int	count;
	int	len;

	count = 0;
	if (!str)
		len = 6;
	else
		len = ft_strlen(str);
	if (flags->dot && flags->precision < len)
		len = flags->precision;
	if (!flags->minus)
		count += print_width(flags->width, len, ' ');
	if (!str)
		count += write(1, "(null)", len);
	else
		count += write(1, str, len);
	if (flags->minus)
		count += print_width(flags->width, len, ' ');

	return (count);
}
