/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:14:53 by rquerino          #+#    #+#             */
/*   Updated: 2019/08/15 14:38:05 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
** These functions will read the string and and store information
** about the flags of each variable.

char	*ft_gettype(char c)
{
	//c,d,e,f,g,i,o,s,u,x
	if (c == 'c' || c == 'd' || c == 'i' || c == 'o' || c == 'x' ||
		c == 'u')
		return ("int");
	else if (c == 'f' || c == 'e' || c == 'g')
		return ("double");
	else if (c == 's')
		return ("char *");
	else if  (c == 'p')
		return ("void *");
	return ("error");
}
*/
int		ft_getwidth(const char *str, t_flags *flags, int i, int n)
{
	int	width;

	width = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		width = width * 10 + (str[i] - '0');
		i++;
	}
	flags[n].width = width;
	return (i - 1);
}

int		ft_getafterdot(const char *str, t_flags *flags, int i, int n)
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
	if (justdot == i - 1)
		flags[n].justdot = 1;
	flags[n].afterdot = afterdot;
	return (i - 1);
}

// Not needed: e, g
int		ft_checkflags(const char *str, t_flags *flags, int i, int n)
{
	while (str[i] != 'c' && str[i] != 'd' && str[i] != 'f' && str[i] != 'p'
		&& str[i] != 'i' && str[i] != 'o' && str[i] != 's' && str[i] != 'u'
		&& str[i] != 'x' && str[i] != 'X')
	{
		if (str[i] == '-')
			flags[n].justify = 1;
		else if (str[i] == '+')
			flags[n].plus = 1;
		else if (str[i] == ' ')
			flags[n].hiddenplus = 1;
		else if (str[i] == '0' && str[i - 1] <= '0' && str[i - 1] >= '9')
			flags[n].zero = 1;
		else if (str[i] == '*')
			flags[n].star = 1;
		else if (str[i] == '$')
			flags[n].dollar = 1;
		else if (str[i] == '#')
			flags[n].hashtag = 1;
		else if (str[i] > '0' && str[i] <= '9' && flags[n].afterdot == 0)
			i = ft_getwidth(str, flags, i, n);
		else if (str[i] == '.')
			i = ft_getafterdot(str, flags, i, n);
		i++;
	}
	flags[n].type = str[i];
	return (i);
}

void    ft_reader(const char *str, va_list args, t_flags *flags)
{
	int n;
	int i;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '%')
		{
			ft_putchar(str[i]);
			i++;
		}
		else if (str[i] == '%' && str[i + 1] != '%')
		{
			ft_startstruct(flags, n);
			i = ft_checkflags(str, flags, i, n); // Store every flag on that variable
			//ft_printflags(flags[n]);
			ft_printer(args, flags, n); // Print that variable according to the flags
			n += 1;
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
