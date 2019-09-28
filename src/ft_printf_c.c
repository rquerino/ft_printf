/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 13:25:56 by rquerino          #+#    #+#             */
/*   Updated: 2019/09/28 11:38:16 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** c: Print character.
** Probably the simplest to handle.
** %c ignores all flags.
*/

int	ft_printf_c(va_list args, t_flags flags)
{
	int	var;
	int	i;

	i = 0;
	var = va_arg(args, int);
	if (flags.justify && flags.width > 1)
	{
		ft_putchar(var);
		while (i < flags.width - 1)
		{
			ft_putchar(' ');
			i++;
		}
	}
	else
	{
		if (flags.width > 1)
			while (i < flags.width - 1)
			{
				ft_putchar(' ');
				i++;
			}
		ft_putchar(var);
	}
	return (flags.width > 1 ? flags.width : 1);
}
