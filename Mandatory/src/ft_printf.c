/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:31:00 by arabenst          #+#    #+#             */
/*   Updated: 2022/11/20 10:49:30 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_iteri(const char *str, va_list *args);
int	ft_putarg(char flag, va_list *args);
int	ft_putarg2(char flag, va_list *args);

int	ft_printf(const char *format, ...)
{
	int		prtd;
	va_list	args;

	prtd = 0;
	va_start(args, format);
	prtd = ft_format_iteri(format, &args);
	va_end(args);
	return (prtd);
}

int	ft_format_iteri(const char *str, va_list *args)
{
	int	i;
	int	res;
	int	prtd;

	i = 0;
	prtd = 0;
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			res = ft_putarg(str[i + 1], args);
			if (res == -1)
				return (-1);
			prtd += res;
			i++;
		}
		else
		{
			if (ft_putchar(str[i]) == -1)
				return (-1);
			prtd++;
		}
		i++;
	}
	return (prtd);
}

int	ft_putarg(char flag, va_list *args)
{
	char	*str;

	if (flag == 'c')
	{
		if (ft_putchar(va_arg(*args, int)) != -1)
			return (1);
	}
	if (flag == 's')
	{
		str = va_arg(*args, char *);
		if (!str)
			str = "(null)";
		if (ft_putstr(str) != -1)
			return (ft_strlen(str));
	}
	if (flag == 'p')
	{
		if (ft_putstr("0x") == -1)
			return (-1);
		return (ft_print_hex((unsigned long)va_arg(*args, void *), 1, 0) + 2);
	}
	return (ft_putarg2(flag, args));
}

int	ft_putarg2(char flag, va_list *args)
{
	int	nbr;

	if (flag == 'd')
	{
		nbr = va_arg(*args, int);
		if (ft_putnbr(nbr) != -1)
			return (ft_count_digits(nbr));
	}
	if (flag == 'i')
	{
		nbr = va_arg(*args, int);
		if (ft_putnbr(nbr) != -1)
			return (ft_count_digits(nbr));
	}
	if (flag == 'u')
		return (ft_put_usnbr(va_arg(*args, unsigned int), 0));
	if (flag == 'x')
		return (ft_print_hex(va_arg(*args, unsigned int), 1, 0));
	if (flag == 'X')
		return (ft_print_hex(va_arg(*args, unsigned int), 0, 0));
	if (flag == '%')
		if (ft_putchar('%') != -1)
			return (1);
	return (-1);
}
