/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 14:10:55 by rquerino          #+#    #+#             */
/*   Updated: 2019/09/07 17:32:59 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

/*
** Functions to deal with types 'd' and 'i'.
** Flags expected: -, +,  , precision, width, h, hh, l, L.
*/

char	*ft_precision_di(char *var, int precision, int len)
{
	int		i;
	int		j;
	char	*final;

	if (precision == 0)
		return (ft_strnew(0));
	i = 0;
	j = 0;
	final = (var[0] == '-') ? ft_strnew(precision + 1) : ft_strnew(precision);
	if (var[0] == '-')
	{
		final[0] = '-';
		i = 1;
		j = 1;		
	}
	while (i < (precision - (var[0] == '-' ? len - 2 : len)))
	{
		final[i] = '0';
		i++;
	}
	while (var[j])
	{
		final[i] = var[j];
		i++;
		j++;
	}
	return (final);
}

void	ft_fillwidth(t_flags flags, int len)
{
	while (len-- > 0)
	{
		if (flags.zero == 1 && flags.afterdot == 0 && flags.justdot == 0)
			ft_putchar('0');
		else
			ft_putchar(' ');
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
	else if (flags.zero == 1 && flags.afterdot == 0 && flags.justdot == 0)
	{
		if (var[0] != '-' && flags.plus == 1)
			ft_putchar('+');
		else if (var[0] != '-' && flags.hiddenplus == 1)
			ft_putchar(' ');
		else if (var[0] == '-')
		{
			ft_putchar('-');
			isneg = 1;
		}
		ft_fillwidth(flags, flags.width - len);
		if (var[0] == '-')
			ft_putstr(var + 1);
		else
			ft_putstr(var);
	}
	else
	{
		ft_fillwidth(flags, flags.width - len);
		if (var[0] != '-' && flags.plus == 1)
			ft_putchar('+');
		else if (var[0] != '-' && flags.hiddenplus == 1)
			ft_putchar(' ');
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
        var = ft_lltoa(va_arg(args, long long));
	else
		var = ft_itoa(va_arg(args, int));
	len = ft_strlen(var);
	if (len - (var[0] == '-' ? 1 : 0) < flags.afterdot || flags.justdot == 1)
		var = ft_precision_di(var, flags.afterdot, len);
	len = ft_strlen(var) + ((flags.plus == 1 || flags.hiddenplus == 1) && var[0] != '-' ? 1 : 0);
	if (flags.width <= len)
		ft_nowidth_di(flags, var);
	else
		ft_width_di(flags, var, len);
	ft_strdel(&var);
	return (0);
}
