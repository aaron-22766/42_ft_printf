/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:48:02 by arabenst          #+#    #+#             */
/*   Updated: 2022/11/16 20:13:03 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long n, int lowercase, int count)
{
	const char	*base;

	if (count == -1)
		return (-1);
	if (lowercase == 1)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n < 16)
	{
		if (ft_putchar(base[n]) == -1)
			return (-1);
		return (count + 1);
	}
	count = ft_print_hex(n / 16, lowercase, count);
	count = ft_print_hex(n % 16, lowercase, count);
	return (count);
}

int	ft_count_digits(int a)
{
	int	i;

	if (a == 0)
		return (1);
	i = (a < 0);
	while (a != 0)
	{
		a /= 10;
		i++;
	}
	return (i);
}

int	ft_put_usnbr(unsigned int n, int count)
{
	if (count == -1)
		return (-1);
	if (n < 10)
	{
		if (ft_putchar('0' + n) == -1)
			return (-1);
		return (count + 1);
	}
	else
	{
		count = ft_put_usnbr(n / 10, count);
		count = ft_put_usnbr(n % 10, count);
	}
	return (count);
}
