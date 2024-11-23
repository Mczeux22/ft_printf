/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:44:18 by loicpapon         #+#    #+#             */
/*   Updated: 2024/11/23 14:28:58 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

typedef struct s_flags
{
	int	minus; //'-'
	int	zero; //'0'
	int	width; //'largeur minimale'
	int	dot; //'.'
	int	precision; //Precision
	int	hash; // '#'
	int	space; //' '
	int	plus; // '+'
}	t_flags;

//Fonction principale de printf

int	ft_print_char(int c);
int	ft_print_str(const char *str);
int	ft_print_hex_with_flags(unsigned int n, char format, t_flags *flags);
int	ft_print_int_with_flags(int n, t_flags *flags);
int	ft_print_percent(void);
int	ft_print_str_with_flags(const char *str, t_flags *flags);
int	ft_printf(const char *str, ...);

//Fonction utilitaire
int	print_width(int width, int len, char fill);
int	ft_format(va_list args, const char format);
int	parse_flags(const char **format, t_flags *flags, va_list args);
int	ft_hexlen(unsigned int n);
int	ft_hexlen_ptr(unsigned long n);
int	ft_putnbr_base(unsigned int nbr, char *base);
int	ft_putnbr_base_signed(int nbr, char *base);


void init_flags(t_flags *flags);


#endif