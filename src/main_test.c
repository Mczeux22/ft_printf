/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:56:36 by loicpapon         #+#    #+#             */
/*   Updated: 2024/11/22 21:06:28 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main(void)
{
	printf("%s\n", "Batterie de test");

	printf("%s\n", "Test de printf %c pour un seul character");
	ft_printf("%c\n", "A");
	printf("%c\n", "A");
	printf("%s\n", "Test de printf %s pour une chaîne characters");
	ft_printf("%s\n", "Hello World");
	printf("%s\n", "Hello world");
}
