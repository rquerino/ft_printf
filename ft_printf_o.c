/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 14:59:57 by rquerino          #+#    #+#             */
/*   Updated: 2019/08/25 15:32:54 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Function to deal with 'o'.
** Uses all the auxiliary functions of 'd'/'i' to handle the flags.
*/

int		ft_printf_o(va_list args, t_flags flags)
{
	char	*var;
	int		len;

	if (flags.h == 1)
		var = ft_ulltoa8((unsigned short)va_arg(args, unsigned));
	else if (flags.hh == 1)
		var = ft_ulltoa8((unsigned char)va_arg(args, unsigned));
	else if (flags.l == 1) 
		var = ft_utoa8(va_arg(args, unsigned long));
	else if (flags.ll == 1)
		var = ft_utoa8(va_arg(args, unsigned long long));
	else
		var = ft_utoa8(va_arg(args, unsigned));
	len = ft_strlen(var);
	len += len >= 0 && (flags.plus == 1 || flags.hiddenplus == 1) ? 1 : 0;
	if (flags.width <= len)
		ft_nowidth_di(flags, var);
	else
		ft_width_di(flags, var, len);
	ft_strdel(&var);
	return (0);
}