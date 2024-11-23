/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:44:15 by loicpapon         #+#    #+#             */
/*   Updated: 2024/11/23 14:41:14 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_format(va_list args, const char format)
{
	int	i;

	i = 0;
	if (format == 'c')
		i += ft_print_char(va_args(args, int));
	else if (format == 's')
		i += ft_print_str_with_flags(va_arg(args, char *));
	else if (format == 'p')
		i += ;
	else if (format == 'd')
		i += ;
	else if (format == 'i')
		i += ft_print_int_with_flags(va_args(args, int));
	else if (format == 'u')
		i += ;
	else if (format == 'x')
		i += ;
	else if (format == 'X')
		i += ;
	else if (format == '%')
		i += ft_print_percent();
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_lenght;

	i = 0;
	print_lenght = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_lenght += ft_format(args, str[i + 1]);
			i++;
		}
		else
			print_lenght += ft_print_char(str[i]);
		i++;
	}
	va_end (args);
	return (print_lenght);

}
