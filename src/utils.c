/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:15:53 by loicpapon         #+#    #+#             */
/*   Updated: 2024/11/23 14:20:37 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_hexlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_hexlen_ptr(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	int		base_len;
	int		count;

	base_len = 0;
	count = 0;
	while (base[base_len])
		base_len++;
	if (nbr >= (unsigned int)base_len)
		count += ft_putnbr_base(nbr / base_len, base);
	count += write(1, &base[nbr % base_len], 1);

	return (count);
}

int	ft_putnbr_base_signed(int nbr, char *base)
{
	int	count;

	count = 0;
	if (nbr < 0)
		count += write(1, "-", 1);
	count += ft_putnbr_base((unsigned int)(nbr < 0 ? -nbr : nbr), base);
	return (count);
}
