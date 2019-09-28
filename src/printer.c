/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 10:10:01 by rquerino          #+#    #+#             */
/*   Updated: 2019/09/28 12:20:28 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** This is the caller of all the functions needed to print
** the argument n.
*/

int	ft_printer(va_list args, t_flags *flags, int n)
{
	if (flags[n].type == 's')
		return (ft_printf_s(args, flags[n]));
	else if (flags[n].type == 'c')
		return (ft_printf_c(args, flags[n]));
	else if (flags[n].type == 'p')
		return (ft_printf_p(args, flags[n]));
	else if (flags[n].type == 'd' || flags[n].type == 'i')
		return (ft_printf_di(args, flags[n]));
	else if (flags[n].type == 'o')
		return (ft_printf_o(args, flags[n]));
	else if (flags[n].type == 'u')
		return (ft_printf_u(args, flags[n]));
	else if (flags[n].type == 'x' || flags[n].type == 'X')
		return (ft_printf_x(args, flags[n]));
	else if (flags[n].type == 'f')
		return (ft_printf_f(args, flags[n]));
	else if (flags[n].type == '%')
		return (ft_printf_perc(flags[n]));
	return (0);
}
