/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:31:00 by arabenst          #+#    #+#             */
/*   Updated: 2022/11/23 13:58:50 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_arg_to_cache(va_list *args, char *tag, char **cache)
{
	int	spec;

	spec = ft_strlen(tag) - 1;
	if (tag[spec] == 's')
		ft_get_string(args, tag, cache);
	else if (tag[spec] == 'p')
		ft_get_pointer(args, tag, cache);
	else if (tag[spec] == 'd' || tag[spec] == 'i')
		ft_get_int(args, tag, cache);
	else if (tag[spec] == 'u')
		ft_get_uint(args, tag, cache);
	else if (tag[spec] == 'x')
		ft_get_hex(args, tag, cache, 1);
	else if (tag[spec] == 'X')
		ft_get_hex(args, tag, cache, 0);
	else if (tag[spec] == '%')
		ft_get_percent(tag, cache);
}

//returns length of tag for skip | 0 if invaid tag | -1 if error
static int	ft_putarg(va_list *args, const char *pos, int *prtd)
{
	int		spec;
	char	*cache;
	char	*tag;

	spec = ft_valid_tag(pos);
	if (!spec)
		return (0);
	tag = ft_calloc(spec + 2, sizeof(char));
	if (!tag)
		return (-1);
	ft_strlcpy(tag, pos, spec + 2);
	cache = NULL;
	if (tag[spec] == 'c')
	{
		spec = ft_putc(args, tag, prtd);
		return (free(tag), spec);
	}
	ft_arg_to_cache(args, tag, &cache);
	free(tag);
	if (!cache)
		return (-1);
	if (ft_putstr_fd(cache, 1) == -1)
		return (free(cache), -1);
	(*prtd) += ft_strlen(cache);
	return (free(cache), spec + 1);
}

//returns number of printed characters | -1 if error
static int	ft_format_iteri(const char *format, va_list *args)
{
	int	i;
	int	prtd;
	int	skip;

	i = 0;
	prtd = 0;
	while (format[i])
	{
		skip = ft_putarg(args, &format[i], &prtd);
		if (skip == -1)
			return (-1);
		if (!skip)
		{
			if (ft_putchar_fd(format[i], 1) == -1)
				return (-1);
			prtd++;
			skip = 1;
		}
		i += skip;
	}
	return (prtd);
}

//returns number of printed characters | -1 if error
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
