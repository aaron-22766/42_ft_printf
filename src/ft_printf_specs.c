/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 08:55:24 by arabenst          #+#    #+#             */
/*   Updated: 2022/11/23 14:04:54 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_string(va_list *args, char *tag, char **cache)
{
	char	*str;

	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	*cache = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!(*cache))
		return ;
	ft_strlcpy(*cache, str, ft_strlen(str) + 1);
	ft_apply_precision(tag, cache, 0);
	ft_apply_width(tag, cache);
}

void	ft_get_pointer(va_list *args, char *tag, char **cache)
{
	unsigned long	p;

	p = (unsigned long)va_arg(*args, void *);
	*cache = ft_ultoa_hex(p, 1);
	if (!(*cache))
		return ;
	if (!ft_strmerge(cache, "0x", 0))
	{
		free(*cache);
		*cache = NULL;
		return ;
	}
	ft_apply_width(tag, cache);
}

void	ft_get_int(va_list *args, char *tag, char **cache)
{
	int	n;

	n = va_arg(*args, int);
	*cache = ft_itoa(n);
	if (!(*cache))
		return ;
	ft_apply_zero_padding(tag, cache);
	ft_apply_precision(tag, cache, 1);
	if (n >= 0)
	{
		if (ft_strchr(tag, '+'))
			cache = ft_strmerge(cache, "+", 0);
		else if (ft_strchr(tag, ' '))
			cache = ft_strmerge(cache, " ", 0);
		ft_apply_width(tag, cache);
		return ;
	}
	*ft_strchr(*cache, '-') = (*cache)[0];
	(*cache)[0] = '-';
	ft_apply_width(tag, cache);
}

void	ft_get_uint(va_list *args, char *tag, char **cache)
{
	unsigned int	u;

	u = va_arg(*args, unsigned int);
	*cache = ft_uitoa(u);
	if (!(*cache))
		return ;
	ft_apply_zero_padding(tag, cache);
	ft_apply_precision(tag, cache, 1);
	ft_apply_width(tag, cache);
}

void	ft_get_hex(va_list *args, char *tag, char **cache, int lowercase)
{
	unsigned int	u;

	u = va_arg(*args, unsigned int);
	*cache = ft_ultoa_hex(u, lowercase);
	if (!(*cache))
		return ;
	ft_apply_zero_padding(tag, cache);
	ft_apply_precision(tag, cache, 1);
	ft_apply_alternate(tag, cache, u);
	ft_apply_width(tag, cache);
}
