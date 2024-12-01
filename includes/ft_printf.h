/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:44:18 by loicpapon         #+#    #+#             */
/*   Updated: 2024/12/01 17:09:53 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

// Fonction principale de printf
int		ft_printf(const char *str, ...);

// Fonctions pour chaque conversion
void	ft_print_char(char c, int *len);
void	ft_print_hexa(unsigned int hexa, int *len, char format);
void	ft_print_int(int n, int *len);
void	ft_print_ptr(size_t p, int *len);
void	ft_print_unsigned(unsigned int nb, int *len);
void	ft_print_str(char *str, int *len);
void	ft_print_percent(void);

int		ft_putstr(char *str);
#endif