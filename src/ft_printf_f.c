/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 13:45:15 by rquerino          #+#    #+#             */
/*   Updated: 2019/09/28 12:11:29 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_nowidth_f(t_flags flags, char *var)
{
	if (flags.plus == 1 && var[0] != '-')
		ft_putchar('+');
	else if (flags.hiddenplus == 1 && var[0] != '-')
		ft_putchar(' ');
	ft_putstr(var);
	if (flags.hashtag == 1 && flags.afterdot == 0)
		ft_putchar('.');
}

void	ft_width_notjustify(t_flags flags, int len, char *var)
{
	int	i;

	if (var[0] == '-')
	{
		ft_putchar(var[0]);
		i = 1;
		while ((flags.width - len) > 0)
		{
			ft_putchar('0');
			len++;
		}
		while (var[i])
			ft_putchar(var[i++]);
		return ;
	}
	i = 0;
	if (flags.plus || flags.hiddenplus)
		i++;
	if (flags.plus)
		ft_putchar('+');
	if (flags.hiddenplus)
		ft_putchar(' ');
	while (i++ < flags.width - len)
		ft_putchar('0');
	ft_putstr(var);
}

void	ft_width_f(t_flags flags, char *var, int len)
{
	int	i;

	i = flags.hashtag == 1 && flags.afterdot == 0 ? 1 : 0;
	if (flags.justify == 1)
	{
		ft_nowidth_f(flags, var);
		if (flags.zero == 1 && flags.afterdot > 1)
			while ((flags.plus == 1 || flags.hiddenplus == 1) && var[0] != '-' ?
				i++ < (flags.width - (len + 1)) : i++ < (flags.width - len))
				ft_putchar('0');
		else
			while ((flags.plus == 1 || flags.hiddenplus == 1) && var[0] != '-' ?
				i++ < (flags.width - (len + 1)) : i++ < (flags.width - len))
				ft_putchar(' ');
	}
	else if (flags.zero == 1 && flags.justify == 0)
		ft_width_notjustify(flags, len, var);
	else
	{
		while ((flags.plus == 1 || flags.hiddenplus == 1) && var[0] != '-' ?
			i++ < (flags.width - (len + 1)) : i++ < (flags.width - len))
			ft_putchar(' ');
		ft_nowidth_f(flags, var);
	}
}

int		ft_printf_f(va_list args, t_flags flags)
{
	int		len;
	char	*var;

	if (flags.up_l == 1)
		var = ft_ldtoa(va_arg(args, long double), flags.afterdot
			|| flags.justdot ? flags.afterdot : 6);
	else
		var = ft_dtoa(va_arg(args, double), flags.afterdot
			|| flags.justdot ? flags.afterdot : 6);
	len = ft_strlen(var);
	if (flags.width <= len)
		ft_nowidth_f(flags, var);
	else
		ft_width_f(flags, var, len);
	ft_strdel(&var);
	return (flags.width > len ? flags.width : len);
}
