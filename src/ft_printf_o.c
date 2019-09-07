/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 14:59:57 by rquerino          #+#    #+#             */
/*   Updated: 2019/09/07 14:42:31 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

char	*ft_precision_ox(t_flags flags, char *var, int len)
{
	int		i;
	int		j;
	char	*final;

	if (flags.justdot == 1 && flags.hashtag == 0)
		return (ft_strnew(0));
	i = 0;
	j = 0;
	final = flags.afterdot == 0 ? ft_strnew(1) : ft_strnew(flags.afterdot);
	if (flags.hashtag == 1 && ft_strcmp(var, "0") != 0)
	{
		final[0] = '0';
		i = 1;
	}
	while (i < (flags.afterdot - len))
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

void	ft_width_ox(t_flags flags, char *var, int len)
{
	int isneg;

	isneg = 0;
	if (flags.justify == 1)
	{
		ft_putstr(var);
		ft_fillwidth(flags, flags.width - len);
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
** Function to deal with 'o'.
*/

int		ft_printf_o(va_list args, t_flags flags)
{
	char	*var;
	int		len;

	if (flags.h == 1)
		var = ft_utoa_base((unsigned short)va_arg(args, unsigned), 8);
	else if (flags.hh == 1)
		var = ft_utoa_base((unsigned char)va_arg(args, unsigned), 8);
	else if (flags.l == 1) 
		var = ft_ultoa_base(va_arg(args, unsigned long), 8);
	else if (flags.ll == 1)
		var = ft_ulltoa_base(va_arg(args, unsigned long long), 8);
	else
		var = ft_utoa_base(va_arg(args, unsigned), 8);
	len = ft_strlen(var);
	if (flags.afterdot > len || flags.justdot == 1 || flags.hashtag == 1)
		var = ft_precision_ox(flags, var, len);
	len = ft_strlen(var);
	if (flags.width <= len)
		ft_putstr(var);
	else
		ft_width_ox(flags, var, len);
	ft_strdel(&var);
	return (0);
}