/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_redo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:33:08 by arabenst          #+#    #+#             */
/*   Updated: 2022/11/16 20:54:59 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return ((int)write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (ft_putchar(s[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		if (ft_putchar('2') == -1)
			return (-1);
		n = 147483648;
	}
	else if (n < 0)
	{
		n = -n;
		if (ft_putchar('-') == -1)
			return (-1);
	}
	if (n >= 10)
	{
		if (ft_putnbr(n / 10) == -1)
			return (-1);
		if (ft_putnbr(n % 10) == -1)
			return (-1);
	}
	else
		if (ft_putchar('0' + n) == -1)
			return (-1);
	return (0);
}
