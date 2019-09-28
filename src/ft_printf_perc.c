/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_perc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 10:31:17 by rquerino          #+#    #+#             */
/*   Updated: 2019/09/28 11:55:34 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_perc(t_flags flags)
{
	int	i;

	i = 1;
	if (flags.width > 1)
	{
		if (flags.justify)
		{
			ft_putchar('%');
			while (i++ < flags.width)
				ft_putchar(' ');
		}
		else
		{
			if (flags.zero)
				while (i++ < flags.width)
					ft_putchar('0');
			else
				while (i++ < flags.width)
					ft_putchar(' ');
			ft_putchar('%');
		}
	}
	else
		ft_putchar('%');
	return (flags.width ? flags.width : 1);
}
