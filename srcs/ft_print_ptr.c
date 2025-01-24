/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:38:19 by loicpapon         #+#    #+#             */
/*   Updated: 2025/01/04 21:40:24 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ptr(size_t p, int *len)
{
	char	str[25];
	char	*base;
	int		i;

	i = 0;
	base = "0123456789abcdef";
	write(1, "0x", 2);
	(*len) += 2;
	if (p == 0)
	{
		ft_print_char('0', len);
		return ;
	}
	while (p != 0)
	{
		str[i] = base[p % 16];
		p /= 16;
		i++;
	}
	while (i--)
		ft_print_char(str[i], len);
}
