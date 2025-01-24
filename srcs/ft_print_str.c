/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:45:59 by loicpapon         #+#    #+#             */
/*   Updated: 2025/01/24 11:31:24 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(char *str, int *len)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(nil)");
		(*len) += 6;
		return ;
	}
	while (str[i])
	{
		ft_print_char(str[i], len);
		i++;
	}
}
