/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 13:45:15 by rquerino          #+#    #+#             */
/*   Updated: 2019/09/05 11:40:50 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
static int	ft_charsafterdot(char *var)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (var[i] != '.')
	{
		i++;
	}
	i++;
	if (var[i - 1] == '.')
		while (var[i] != '\0')
		{
			i++;
			count++;
		}
	return (count);
}*/


void	ft_nowidth_f(t_flags flags, char *var)
{
	if (flags.plus == 1 && var[0] != '-')
		ft_putchar('+');
	else if (flags.hiddenplus == 1 && var[0] != '-')
		ft_putchar(' ');
	ft_putstr(var);
}

void	ft_width_f(t_flags flags, char *var, int len)
{
	int	i;

	i = 0;
	if (flags.justify == 1)
	{
		i = 0;
		ft_nowidth_f(flags, var);
		while ((flags.plus == 1 || flags.hiddenplus == 1) && var[0] != '-' ?
			i++ < (flags.width - (len + 1)) : i++ < (flags.width - len))
			ft_putchar('0');
	}
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
    char    *var;

    if (flags.L == 1)
        var = ft_ldtoa(va_arg(args, long double), flags.afterdot > 0 ? flags.afterdot : 6);
	else
		var = ft_dtoa(va_arg(args, double), flags.afterdot > 0 ? flags.afterdot : 6);
	len = ft_strlen(var);
	if (flags.width <= len)
		ft_nowidth_f(flags, var);
	else
		ft_width_f(flags, var, len);
	ft_strdel(&var);
	return (0);
}