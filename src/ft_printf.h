/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:24:36 by arabenst          #+#    #+#             */
/*   Updated: 2022/11/23 17:02:15 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

//ft_printf.c
int		ft_printf(const char *format, ...);

//ft_printf_specs.c
void	ft_get_string(va_list *args, char *tag, char **cache);
void	ft_get_pointer(va_list *args, char *tag, char **cache);
void	ft_get_int(va_list *args, char *tag, char **cache);
void	ft_get_uint(va_list *args, char *tag, char **cache);
void	ft_get_hex(va_list *args, char *tag, char **cache, int lowercase);

//ft_printf_specs2.c
int		ft_putc(va_list *args, char *tag, int *prtd);
void	ft_get_percent(char *tag, char **cache);

//ft_printf_utils.c
void	ft_apply_width(char *tag, char **cache);
void	ft_apply_precision(char *tag, char **cache, int nu);
void	ft_apply_zero_padding(char *tag, char **cache);
void	ft_apply_alternate(char *tag, char **cache, unsigned int u);
int		ft_valid_tag(const char *tag);

#endif