/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:14:53 by rquerino          #+#    #+#             */
/*   Updated: 2019/08/12 17:53:21 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** These functions will read the string and and store information
** about the flags of each variable.
*/

int	ft_getwidth(const char *str, t_flags *flags, int i, int variables)
{
	int	width;

	width = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		width = width * 10 + str[i] + '0';
		i++;
	}
	flags[variables].width = width;
	return (i);
}

int	ft_getafterdot(const char *str, t_flags *flags, int i, int variables)
{
	int afterdot;

	i++;
	afterdot = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		afterdot = afterdot * 10 + str[i] + '0';
		i++;
	}
	flags[variables].afterdot = afterdot;
	return (i);
}

int	ft_checkflags(const char *str, t_flags *flags, int i, int variables)
{
	int	founddot;

	founddot = 0;
	while (str[i] != 'd' && str[i] != 's' && str[i] != 'i')
	{
		if (str[i] == '-')
			flags[variables].justify = 1;
		else if (str[i] == '+')
			flags[variables].plus = 1;
		else if (str[i] == ' ')
			flags[variables].hiddenplus = 1;
		else if (str[i] == '0' && str[i - 1] <= '0' && str[i - 1] >= '9')
			flags[variables].zero = 1;
		else if (str[i] == '*')
			flags[variables].star = 1;
		else if (str[i] == '$')
			flags[variables].dollar = 1;
		else if (str[i] == '#')
			flags[variables].hashtag = 1;
		else if (str[i] > '0' && str[i] <= '9' && founddot == 0)
			i = ft_getwidth(str, flags, i, variables);
		else if (str[i] == '.')
		{
			i = ft_getafterdot(str, flags, i, variables);
			founddot = 1;
		}
		i++;
	}
	flags[variables].type = str[i];
	return (i);
}

void    ft_reader(const char *str, t_flags *flags)
{
	int variables;
	int i;

	i = 0;
	variables = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '%')
		{
			ft_putchar(str[i]);
			i++;
		}
		else if (str[i] == '%' && str[i + 1] != '%')
		{
			i = ft_checkflags(str, flags, i, variables); // Store every flag on that variable
			//ft_printvariable(flags, variables); // Print that variable according to the flags
			variables += 1;
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
