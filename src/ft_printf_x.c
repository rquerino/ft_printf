/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 21:22:26 by rquerino          #+#    #+#             */
/*   Updated: 2019/09/05 11:40:50 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** hashtag = 1 and number != 0, start with 0x ONLY!!!!!!!!
** 
*/

void	ft_makehexlower(char *var)
{
	int	i;

	i = 0;
	while (var[i])
	{
		ft_putchar(ft_tolower(var[i]));
		i++;
	}
}

int		ft_printf_x(va_list args, t_flags flags)
{
	int		len;
    char    *var;

    if (flags.h == 1)
        var = ft_utoa_base((unsigned short)va_arg(args, unsigned), 16);
    else if (flags.hh == 1)
        var = ft_utoa_base((unsigned char)va_arg(args, unsigned), 16);
    else if (flags.l == 1)
        var = ft_ulltoa_base(va_arg(args, unsigned long), 16);
    else if (flags.ll == 1)
        var = ft_ulltoa_base(va_arg(args, unsigned long long), 16);
	else
		var = ft_utoa_base(va_arg(args, unsigned), 16);
	len = ft_strlen(var);
	len += len >= 0 && (flags.plus == 1 || flags.hiddenplus == 1) ? 1 : 0;
	if (flags.type == 'x')
		ft_makehexlower(var);
	if (flags.width <= len)
		ft_nowidth_di(flags, var);
	else
		ft_width_di(flags, var, len);
	ft_strdel(&var);
	return (0);
}