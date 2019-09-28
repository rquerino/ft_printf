/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 21:22:26 by rquerino          #+#    #+#             */
/*   Updated: 2019/09/28 15:09:12 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print0x(char type)
{
	if (type == 'x')
		ft_putstr("0x");
	else if (type == 'X')
		ft_putstr("0X");
}

/*
** hashtag = 1 and number != 0, start with 0x/0X!
*/

char	*ft_precision_x(t_flags flags, char *var, int len)
{
	int		i;
	int		j;
	char	*final;

	if (flags.justdot == 1)
		return (ft_strnew(0));
	final = ft_strnew(flags.afterdot);
	i = 0;
	j = 0;
	while (i < (flags.afterdot - len))
	{
		final[i++] = '0';
	}
	while (var[j])
		final[i++] = var[j++];
	return (final);
}

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

void	ft_width_x(t_flags flags, char *res, int len, char *var)
{
	if (flags.justify == 1)
		ft_printjustify_x(flags, res, len, var);
	else
	{
		if (flags.zero == 1 && flags.afterdot == 0 && flags.justdot == 0)
		{
			if (flags.hashtag && ft_strcmp(var, "0") != 0)
				ft_print0x(flags.type);
			ft_fillwidth(flags, flags.width - len);
		}
		else
		{
			ft_fillwidth(flags, flags.width - len);
			if (flags.hashtag && ft_strcmp(var, "0") != 0)
				ft_print0x(flags.type);
		}
		if (flags.type == 'x')
			ft_makehexlower(res);
		else
			ft_putstr(res);
	}
}

int		ft_printf_x(va_list args, t_flags flags)
{
	int		len;
	char	*var;
	char	*res;

	var = ft_getvar_x(args, flags);
	len = ft_strlen(var);
	res = (flags.afterdot > len || flags.justdot == 1) ?
		ft_precision_x(flags, var, len) : ft_strdup(var);
	len = (flags.afterdot > len || flags.justdot == 1) ? flags.afterdot : len;
	if (var && flags.hashtag && ft_strcmp(var, "0") != 0 && flags.justdot == 0)
		len += 2;
	if (flags.width > len)
		ft_width_x(flags, res, len, var);
	else
	{
		if (flags.hashtag && ft_strcmp(var, "0") != 0)
			ft_print0x(flags.type);
		if (flags.type == 'x')
			ft_makehexlower(res);
		else
			ft_putstr(res);
	}
	ft_strdel(&res);
	ft_strdel(&var);
	return (flags.width > len ? flags.width : len);
}
