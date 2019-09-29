/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:14:53 by rquerino          #+#    #+#             */
/*   Updated: 2019/09/28 18:56:34 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_getlength(const char *str, t_flags *flags, int i)
{
	if (str[i] == 'l')
	{
		if (str[i + 1] == 'l')
		{
			flags->ll = 1;
			return (i + 1);
		}
		else
			flags->l = 1;
	}
	else if (str[i] == 'h')
	{
		if (str[i + 1] == 'h')
		{
			flags->hh = 1;
			return (i + 1);
		}
		else
			flags->h = 1;
	}
	else if (str[i] == 'L')
		flags->up_l = 1;
	return (i);
}

int		ft_getwidth(const char *str, t_flags *flags, int i)
{
	int	width;

	width = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		width = width * 10 + (str[i] - '0');
		i++;
	}
	flags->width = width;
	return (i - 1);
}

int		ft_getafterdot(const char *str, t_flags *flags, int i)
{
	int afterdot;
	int	justdot;

	justdot = i;
	i++;
	afterdot = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		afterdot = afterdot * 10 + (str[i] - '0');
		i++;
	}
	if (justdot == i - 1 || afterdot == 0)
		flags->justdot = 1;
	flags->afterdot = afterdot;
	return (i - 1);
}

int		ft_checkflags(const char *str, t_flags *flags, int i)
{
	while (str[i] && (str[i] != 'c' && str[i] != 'd' && str[i] != 'f'
		&& str[i] != 'p' && str[i] != 'i' && str[i] != 'o' && str[i] != 's'
		&& str[i] != 'u' && str[i] != 'x' && str[i] != 'X' && str[i] != '%'))
	{
		if (str[i] == '-')
			flags->justify = 1;
		else if (str[i] == '+')
			flags->plus = 1;
		else if (str[i] == ' ')
			flags->hiddenplus = 1;
		else if (str[i] == '0' && str[i - 1] != '.')
			flags->zero = 1;
		else if (str[i] == 'h' || str[i] == 'l' || str[i] == 'L')
			i = ft_getlength(str, flags, i);
		else if (str[i] == '#')
			flags->hashtag = 1;
		else if (str[i] > '0' && str[i] <= '9' && flags->afterdot == 0)
			i = ft_getwidth(str, flags, i);
		else if (str[i] == '.')
			i = ft_getafterdot(str, flags, i);
		i++;
	}
	flags->type = str[i];
	return (i);
}

int		ft_reader(const char *str, va_list args, t_flags *flags, int ret)
{
	int n;
	int i;

	i = 0;
	n = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '%')
			ret += ft_putchar_ptf(str[i++]);
		else if (str[i] == '%' && str[i + 1])
		{
			ft_startstruct(flags, n);
			i = ft_checkflags(str, &flags[n], i + 1);
			if (flags[n].type != 'a' && flags[n].type != 0)
			{
				ret += ft_printer(args, flags, n);
				n += 1;
			}
		}
		else if (str[i] && str[i] != '%')
			ret += ft_putchar_ptf(str[i]);
		i += str[i] ? 1 : 0;
	}
	return (ret);
}
