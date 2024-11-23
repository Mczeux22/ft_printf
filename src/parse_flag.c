/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 21:48:59 by loicpapon         #+#    #+#             */
/*   Updated: 2024/11/23 13:58:01 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	init_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->dot = 0;
	flags->precision = -1;
	flags->hash = 0;
	flags->space = 0;
	flags->plus = 0;
}

int	parse_flags(const char **format, t_flags *flags, va_list args)
{
	while (**format && (**format == '-' || **format == '0' || **format == '.'
			|| **format == '#' || **format == ' ' || **format == '+'
			|| **format >= '0' && **format <= '9'))
	{
		if (**format == '-')
			flags->minus = 1;
		else if (**format == '0')
			flags->zero = 1;
		else if (**format == '.')
		{
			flags->dot = 1;
			(*format)++;
			if (**format == '*')
				flags->precision = va_arg(args, int);
			else
				flags->precision = atoi(*format);
			while (**format >= '0' && **format <= '9')
				(*format)++;
			continue ;
		}
		else if (**format == '#')
			flags->hash = 1;
		else if (**format == ' ')
			flags->space = 1;
		else if (**format == '+')
			flags->plus = 1;
		else if (**format >= '0' && **format <= '9')
		{
			if (flags->dot)
				flags->precision = atoi(*format);
			else
				flags->width = atoi(*format);
			while (**format >= '0' && **format <= '9')
			{
				(*format)++;
				continue ;
			}
		}
		(*format)++;
	}
	if (flags->minus)
		flags->zero = 0;
	return (1);
}
