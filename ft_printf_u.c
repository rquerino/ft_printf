/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 20:26:37 by rquerino          #+#    #+#             */
/*   Updated: 2019/08/28 20:54:13 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Function to deal with 'u'.
** Uses all the auxiliary functions of 'd'/'i' to handle the flags.
*/

int		ft_printf_u(va_list args, t_flags flags)
{
	int		len;
    char    *var;

    if (flags.h == 1)
        var = ft_utoa_base((unsigned short)va_arg(args, unsigned int), 10);
    else if (flags.hh == 1)
        var = ft_utoa_base((unsigned char)va_arg(args, unsigned int), 10);
    else if (flags.l == 1)
        var = ft_ulltoa_base(va_arg(args, unsigned long), 10);
    else if (flags.ll == 1)
        var = ft_ulltoa_base(va_arg(args, unsigned long long), 10);
	else
		var = ft_utoa_base(va_arg(args, int), 10);
	len = ft_strlen(var);
	len += len >= 0 && (flags.plus == 1 || flags.hiddenplus == 1) ? 1 : 0;
	if (flags.width <= len)
		ft_nowidth_di(flags, var);
	else
		ft_width_di(flags, var, len);
	ft_strdel(&var);
	return (0);
}

