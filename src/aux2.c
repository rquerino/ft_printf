/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:13:17 by rquerino          #+#    #+#             */
/*   Updated: 2019/09/28 15:09:34 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Auxiliary functions for flags 'd', 'i', and 'x'/'X'
*/

char	*ft_getvar_di(va_list args, t_flags flags)
{
	if (flags.h == 1)
		return (ft_itoa((short)va_arg(args, int)));
	else if (flags.hh == 1)
		return (ft_itoa((char)va_arg(args, int)));
	else if (flags.l == 1)
		return (ft_ltoa(va_arg(args, long)));
	else if (flags.ll == 1)
		return (ft_lltoa(va_arg(args, long long)));
	else
		return (ft_itoa(va_arg(args, int)));
}

char	*ft_getvar_x(va_list args, t_flags flags)
{
	if (flags.h == 1)
		return (ft_utoa_base((unsigned short)va_arg(args, unsigned), 16));
	else if (flags.hh == 1)
		return (ft_utoa_base((unsigned char)va_arg(args, unsigned), 16));
	else if (flags.l == 1)
		return (ft_ulltoa_base(va_arg(args, unsigned long), 16));
	else if (flags.ll == 1)
		return (ft_ulltoa_base(va_arg(args, unsigned long long), 16));
	else
		return (ft_utoa_base(va_arg(args, unsigned), 16));
}

void	ft_printjustify_x(t_flags flags, char *res, int len, char *var)
{
	if (flags.hashtag && ft_strcmp(var, "0") != 0)
		ft_print0x(flags.type);
	if (flags.type == 'x')
		ft_makehexlower(res);
	else
		ft_putstr(res);
	ft_fillwidth(flags, flags.width - len);
}
