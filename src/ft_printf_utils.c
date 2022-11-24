/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 09:45:50 by arabenst          #+#    #+#             */
/*   Updated: 2022/11/23 14:04:32 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_apply_width(char *tag, char **cache)
{
	size_t	i;
	int		wlen;
	char	*width;

	i = 1;
	while (ft_strchr("#0- +", tag[i]))
		i++;
	if (i == ft_strlen(tag) - 1 || tag[i] == '.')
		return ;
	wlen = ft_atoi(&tag[i]) - ft_strlen(*cache);
	if (wlen <= 0)
		return ;
	width = ft_calloc(wlen + 1, sizeof(char));
	if (!width)
		return ;
	ft_memset(width, ' ', wlen);
	cache = ft_strmerge(cache, width, !(!ft_strchr(tag, '-')));
	free(width);
}

void	ft_apply_precision(char *tag, char **cache, int nu)
{
	int		i;
	size_t	plen;
	char	*new;

	i = 1;
	while (ft_strchr("#0- +", tag[i]))
		i++;
	while (ft_isdigit(tag[i]))
		i++;
	if (tag[i] != '.')
		return ;
	plen = ft_atoi(&tag[i + 1]);
	if ((!nu && plen >= ft_strlen(*cache))
		|| ((*cache)[0] != '0' && nu && plen < ft_strlen(*cache)))
		return ;
	new = ft_calloc(plen + 1 + !(!ft_strchr(*cache, '-')), sizeof(char));
	if (!new)
		return ;
	ft_memset(new, '0', nu * plen);
	if (nu && ft_strchr(*cache, '-'))
		new[0] = '-';
	ft_strlcpy(new + !(!plen) * (nu * (plen - ft_strlen(*cache) + 2
				* (new[0] == '-'))), *cache + (new[0] == '-'), plen + 1);
	free(*cache);
	*cache = new;
}

void	ft_apply_zero_padding(char *tag, char **cache)
{
	size_t	i;
	int		wlen;
	char	*width;

	i = 1;
	while (ft_strchr("#- +", tag[i]))
		i++;
	if (tag[i] != '0')
		return ;
	while (ft_strchr("#0- +", tag[i]))
		i++;
	if (i == ft_strlen(tag) - 1 || ft_strchr(tag, '.'))
		return ;
	wlen = ft_atoi(&tag[i]) - ft_strlen(*cache)
		- (ft_strchr(tag, ' ') && !ft_strchr(*cache, '-'))
		- (ft_strchr(tag, '+') && !ft_strchr(*cache, '-'));
	if (wlen <= 0)
		return ;
	width = ft_calloc(wlen + 1, sizeof(char));
	if (!width)
		return ;
	ft_memset(width, '0', wlen);
	cache = ft_strmerge(cache, width, !(!ft_strchr(tag, '-')));
	free(width);
}

void	ft_apply_alternate(char *tag, char **cache, unsigned int u)
{
	int		z;
	char	*prefix;

	if (!(ft_strchr(tag, '#') && u))
		return ;
	prefix = ft_calloc(3, sizeof(char));
	if (!prefix)
		return ;
	prefix[0] = '0';
	prefix[1] = tag[ft_strlen(tag) - 1];
	z = ((*cache)[0] == '0') + ((*cache)[0] == '0') * ((*cache)[1] == '0');
	if (z == 2 && !ft_strchr(tag, '.'))
		ft_memcpy(*cache, prefix, 2);
	else if (z == 1 && !ft_strchr(tag, '.'))
	{
		cache = ft_strmerge(cache, "0", 0);
		ft_memcpy(*cache + 1, &prefix[1], 1);
	}
	else
		cache = ft_strmerge(cache, prefix, 0);
	free(prefix);
}

//returns index of specifier in tag | 0 if invalid
int	ft_valid_tag(const char *tag)
{
	int	i;

	if (tag[0] != '%')
		return (0);
	i = 1;
	while (ft_strchr("#0- +", tag[i]))
		i++;
	while (ft_isdigit(tag[i]))
		i++;
	if (tag[i] == '.')
	{
		i++;
		while (ft_isdigit(tag[i]))
			i++;
	}
	if (ft_strchr("cspdiuxX%", tag[i]))
		return (i);
	return (0);
}
