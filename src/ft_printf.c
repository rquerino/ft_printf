/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:31:28 by rquerino          #+#    #+#             */
/*   Updated: 2019/09/28 18:39:12 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

/*
** Start the structure to argument n.
*/

void	ft_startstruct(t_flags *flags, int n)
{
	flags[n].type = 'a';
	flags[n].justdot = 0;
	flags[n].afterdot = 0;
	flags[n].hashtag = 0;
	flags[n].hiddenplus = 0;
	flags[n].justify = 0;
	flags[n].plus = 0;
	flags[n].type = 0;
	flags[n].width = 0;
	flags[n].zero = 0;
	flags[n].h = 0;
	flags[n].hh = 0;
	flags[n].l = 0;
	flags[n].ll = 0;
	flags[n].up_l = 0;
}

/*
** Counts how many arguments were passed after the string.
*/

int		ft_countargs(const char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '%')
			i++;
		if (str[i] == '%' && str[i + 1] != '%')
		{
			while (str[i] && (str[i] != 'c' && str[i] != 'd' && str[i] != 'e' &&
				str[i] != 'f' && str[i] != 'g' && str[i] != 'i' &&
				str[i] != 'o' && str[i] != 's' && str[i] != 'u' &&
				str[i] != 'x' && str[i] != 'p' && str[i] == '%'))
				i++;
			if (str[i])
				n += 1;
		}
		i++;
	}
	return (n);
}

/*
** Variadic Function: a function that accepts a variable number of arguments.
** printf exists 0 on success, and >0 if an error occurs.
*/

int		ft_printf(const char *str, ...)
{
	va_list args;
	t_flags *flags;
	int		n_args;
	int		ret;

	ret = 0;
	n_args = ft_countargs(str) + 1;
	flags = malloc(sizeof(t_flags) * n_args);
	va_start(args, str);
	ret = ft_reader(str, args, flags, ret);
	va_end(args);
	free(flags);
	return (ret);
}
