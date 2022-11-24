/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specs2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:55:28 by arabenst          #+#    #+#             */
/*   Updated: 2022/11/23 13:59:19 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putc(va_list *args, char *tag, int *prtd)
{
	unsigned char	c;
	size_t			i;
	int				wlen;

	c = (unsigned char)va_arg(*args, int);
	i = 1;
	while (ft_strchr("-", tag[i]))
		i++;
	wlen = ft_atoi(&tag[i]) - 1;
	if (wlen < 0 && ft_strchr("123456789", tag[i]))
		return (-1);
	if (ft_strchr(tag, '-'))
		if (ft_putchar_fd(c, 1) == -1)
			return (-1);
	if (ft_strchr("123456789", tag[i]))
		while (wlen--)
			if (ft_putchar_fd(' ', 1) == -1)
				return (-1);
	if (!ft_strchr(tag, '-'))
		if (ft_putchar_fd(c, 1) == -1)
			return (-1);
	*prtd += !(!ft_strchr("123456789", tag[i])) * (ft_atoi(&tag[i]) - 1) + 1;
	return (ft_strlen(tag));
}

void	ft_get_percent(char *tag, char **cache)
{
	*cache = ft_calloc(2, sizeof(char));
	if (!(*cache))
		return ;
	(*cache)[0] = '%';
	ft_apply_width(tag, cache);
	ft_apply_precision(tag, cache, 0);
}
