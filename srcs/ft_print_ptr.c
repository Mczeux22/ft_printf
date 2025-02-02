/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:38:19 by loicpapon         #+#    #+#             */
/*   Updated: 2025/02/02 10:14:03 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ptr(size_t p, int *len)
{
	char	str[25];
	char	*base;
	int		i;

	i = 0;
	if (p == 0)
	{
		(*len) += ft_putstr("Nil");
		return ;
	}
	base = "0123456789abcdef";
	write(1, "0x", 2);
	(*len) += 2;
	while (p != 0)
	{
		str[i] = base[p % 16];
		p /= 16;
		i++;
	}
	while (i--)
	{
		write(1, &str[i], 1);
		(*len)++;
	}
}
