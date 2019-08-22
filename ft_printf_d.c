/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 14:10:55 by rquerino          #+#    #+#             */
/*   Updated: 2019/08/21 12:52:09 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Functions to deal with types 'd' and 'i'.
** Flags expected: -, +,  , width, h, hh, l, L.
*/

void	ft_fillwidth(t_flags flags, int len)
{
	while (len > 0)
	{
		if (flags.zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		len--;
	}
}

void	ft_nowidth_di(t_flags flags, char *var)
{
	if (flags.plus == 1 && var[0] != '-')
		ft_putchar('+');
	else if (flags.hiddenplus == 1 && var[0] != '-')
		ft_putchar(' ');
	ft_putstr(var);
}

void	ft_width_di(t_flags flags, char *var, int len)
{
	int isneg;

	isneg = 0;
	if (flags.justify == 1)
	{
		ft_nowidth_di(flags, var);
		ft_fillwidth(flags, flags.width - len);
	}
	else if (flags.zero == 1)
	{
		if (var[0] != '-' && flags.plus == 1)
			ft_putchar('+');
		else if (var >= 0 && flags.hiddenplus == 1)
			ft_putchar(' ');
		else if (var[0] == '-')
		{
			ft_putchar('-');
			isneg = 1;
		}
		ft_fillwidth(flags, flags.width - len);
		ft_putstr(var + 1);
	}
	else
	{
		ft_fillwidth(flags, flags.width - len);
		if (var[0] != '-' && flags.plus == 1)
			ft_putchar('+');
		else if (var >= 0 && flags.hiddenplus == 1)
			ft_putchar(' ');
		else
			ft_putstr(var);
	}
	
}

/*
** Mother function to deal with 'd' and 'i'
** First, we see if there's a required width and compare to the number length
*/

int		ft_printf_di(va_list args, t_flags flags)
{
	int		len;
    char    *var;

    if (flags.h == 1)
        var = ft_itoa((short)va_arg(args, int));
    else if (flags.hh == 1)
        var = ft_itoa((char)va_arg(args, int));
    else if (flags.l == 1) 
        var = ft_ltoa(va_arg(args, long));
    else if (flags.ll == 1)
        var = ft_ltoa(va_arg(args, long long));
	else
		var = ft_itoa(va_arg(args, int));
	len = ft_strlen(var);
	len += len >= 0 && (flags.plus == 1 || flags.hiddenplus == 1) ? 1 : 0;
	if (flags.width <= len)
		ft_nowidth_di(flags, var);
	else
		ft_width_di(flags, var, len);
	ft_strdel(var);
	return (0);
}
