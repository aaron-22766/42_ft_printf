/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:38:41 by arabenst          #+#    #+#             */
/*   Updated: 2022/11/22 09:24:38 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char			*str;
	unsigned int	u;

	str = "nice";
	u = 2147483648;
	printf("\n   FT_PRINTF TEST\n\n");
	printf("[%i]\n", printf(" %c %c %c ", '0', 0, '1'));
	printf("[%i]\n\n", ft_printf(" %c %c %c ", '0', 0, '1'));
	printf("[%i]\n", printf("%s", "This_is_a_test"));
	printf("[%i]\n\n", ft_printf("%s", "This_is_a_test"));
	printf("[%i]\n", printf("%p", str));
	printf("[%i]\n\n", ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX));
	printf("[%i]\n", printf("%i", 1234));
	printf("[%i]\n\n", ft_printf("%i", 1234));
	printf("[%i]\n", printf("%u", u));
	printf("[%i]\n\n", ft_printf("%u", u));
	printf("[%i]\n", printf("%x", -1234));
	printf("[%i]\n\n", ft_printf("%x", -1234));
	printf("[%i]\n", printf("%X", -1234));
	printf("[%i]\n\n", ft_printf("%X", -1234));
	printf("[%i]\n", printf("%%"));
	printf("[%i]\n\n", ft_printf("%%"));
	return (0);
}
