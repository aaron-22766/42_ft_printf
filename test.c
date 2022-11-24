/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:38:41 by arabenst          #+#    #+#             */
/*   Updated: 2022/11/23 13:29:53 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char			*str;
	unsigned int	u;

	str = "nice";
	u = 2147483648;
	printf("\n   FT_PRINTF TEST\n\n");
	printf("[%i]\n", printf("%--72c", 118));
	printf("[%i]\n\n", ft_printf("%--72c", 118));
	printf("[%i]\n", printf("%1s", NULL));
	printf("[%i]\n\n", ft_printf("%1s", NULL));
	printf("[%i]\n", printf("%p", NULL));
	printf("[%i]\n\n", ft_printf("%p", NULL));
	printf("[%i]\n", printf("%.d", 0));
	printf("[%i]\n\n", ft_printf("%.d", 0));
	printf("[%i]\n", printf("%020.4u", 1234567));
	printf("[%i]\n\n", ft_printf("%020.4u", 1234567));
	printf("[%i]\n", printf("%#16x", -230210160));
	printf("[%i]\n\n", ft_printf("%#16x", -230210160));
	printf("[%i]\n", printf("%020.19X", -1234));
	printf("[%i]\n\n", ft_printf("%020.19X", -1234));
	printf("[%i]\n", printf("%5%"));
	printf("[%i]\n\n", ft_printf("%5%"));
	return (0);
}
