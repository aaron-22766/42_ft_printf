/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:50:26 by arabenst          #+#    #+#             */
/*   Updated: 2022/11/23 14:03:27 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strmerge(char **dst, char *src, int dstleft)
{
	char	*joined;
	size_t	i;
	size_t	size;

	if (!src)
		return (NULL);
	size = ft_strlen(*dst) + ft_strlen(src) + 1;
	joined = ft_calloc(size, sizeof(char));
	if (!joined)
		return (NULL);
	i = 0;
	if (!dstleft)
		i = ft_strlcpy(joined, src, size);
	if (*dst)
	{
		i = ft_strlcpy(joined + i, *dst, size);
		free(*dst);
	}
	if (dstleft)
		i = ft_strlcpy(joined + i, src, size);
	*dst = joined;
	return (dst);
}
