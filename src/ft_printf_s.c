/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 14:10:50 by rquerino          #+#    #+#             */
/*   Updated: 2019/09/28 11:59:09 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** s: print characters from string (char *) until '\0'
** or number of characters given by the precision.
** Order of transformations:
** 1) Transform the argument according to precision (afterdot/justdot).
** 2) Transforms to fit width (justify/width).
*/

/*
** This function will check if there are numbers after dot
** (precision) or just dots and transform *var accordingly.
*/

char	*ft_checkdot_s(t_flags flags, char *var)
{
	int		i;
	char	*result;

	if (flags.justdot == 1)
	{
		result = ft_strnew(0);
		return (result);
	}
	i = 0;
	result = ft_strnew(flags.afterdot);
	while (i < flags.afterdot)
	{
		result[i] = var[i];
		i++;
	}
	return (result);
}

/*
** Function called after ft_s_checkdots if there's a
** justify flag and width is bigger then res length.
** Transforms *res accordingly.
*/

void	ft_checkjwidth_s(t_flags flags, char *res)
{
	char	*final;
	int		i;

	i = 0;
	final = ft_strnew(flags.width);
	while (res[i] != '\0' && flags.justdot == 0)
	{
		final[i] = res[i];
		i++;
	}
	while (i < flags.width)
	{
		final[i] = ' ';
		i++;
	}
	ft_putstr(final);
	ft_strdel(&final);
}

/*
** Function called after ft_s_checkdots if width is bigger then res length.
** Transforms *res accordingly.
*/

void	ft_checkwidth_s(t_flags flags, char *res, int len)
{
	char	*final;
	int		i;
	int		j;

	i = 0;
	j = 0;
	final = ft_strnew(flags.width);
	while (i < (flags.width - len))
	{
		final[i] = ' ';
		i++;
	}
	while (i < flags.width)
	{
		final[i] = res[j];
		i++;
		j++;
	}
	ft_putstr(final);
	ft_strdel(&final);
}

int		ft_printf_s(va_list args, t_flags flags)
{
	char	*res;
	int		len;
	char	*var;

	var = va_arg(args, char*);
	if (var == NULL)
		var = "(null)";
	if (flags.width == 0 && flags.justdot == 1)
		return (0);
	len = ft_strlen(var);
	res = ((flags.afterdot > 0 && flags.afterdot < len) || flags.justdot == 1) ?
		ft_checkdot_s(flags, var) : ft_strdup(var);
	len = ((flags.afterdot > 0 && flags.afterdot < len) || flags.justdot == 1) ?
		flags.afterdot : len;
	if (flags.width > 0 && flags.width > len)
	{
		if (flags.justify == 1)
			ft_checkjwidth_s(flags, res);
		else
			ft_checkwidth_s(flags, res, len);
	}
	else
		ft_putstr(res);
	ft_strdel(&res);
	return (flags.width > len ? flags.width : len);
}
