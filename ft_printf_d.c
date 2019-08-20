/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 14:10:55 by rquerino          #+#    #+#             */
/*   Updated: 2019/08/19 12:49:21 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Functions to deal with types 'd' and 'i'.
** Flags expected: -, +,  , width, h, hh, l, L.
*/

int		ft_intlen(int num)
{
	int	i;

	i = 0;
	while (num /= 10)
		i++;
	return (i);
}

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

void	ft_nowidth_di(t_flags flags, int var)
{
	if (flags.plus == 1 && var >= 0)
		ft_putchar('+');
	else if (flags.hiddenplus == 1 && var >= 0)
		ft_putchar(' ');
	ft_putnbr(var);
}

void	ft_width_di(t_flags flags, int var, int len)
{
	if (flags.justify == 1)
	{
		ft_nowidth_di(flags, var);
		ft_fillwidth(flags, flags.width - len);
	}
	else
	{
		if (var >= 0 && flags.plus == 1)
			ft_putchar('+');
		else if (var >= 0 && flags.hiddenplus == 1)
			ft_putchar(' ');
		else if (var < 0)
		{
			ft_putchar('-');
			var *= -1;
		}
		ft_fillwidth(flags, flags.width - len);
		ft_putnbr(var);
	}
}

/*
** Mother function to deal with 'd' and 'i'
** First, we see if there's a required width and compare to the number length
*/

int		ft_printf_di(va_list args, t_flags flags)
{
	int		var;
	int		len;

	var = va_arg(args, int);
	len = ft_intlen(var);
	len += len < 0 || (len >= 0 && (flags.plus == 1 || flags.hiddenplus == 1)) ? 1 : 0;
	if (flags.width <= len)
		ft_nowidth_di(flags, var);
	else
		ft_width_di(flags, var, len);
	return (0);
}
