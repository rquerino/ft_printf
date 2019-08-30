/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 10:10:01 by rquerino          #+#    #+#             */
/*   Updated: 2019/08/29 14:07:07 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Functions that read the flags and call the functions to print
** the variables.
*/

/*
** This functions will read the flags and output the string based on
** the type of the argument and its length.
** It's called by each printf function.
*/
/*
char    *ft_readflags(t_flags flags, int arg_len, va_list args, int n)
{
	char	*res;
	
	


	return (res);
}
*/
/*
** This is the caller of all the functions needed to print
** the argument n.
*/

void    ft_printer(va_list args, t_flags *flags, int n)
{	
	if (flags[n].type == 's')
		ft_printf_s(args, flags[n]);
	else if (flags[n].type == 'c')
		ft_printf_c(args);
	else if	(flags[n].type == 'p')
		ft_printf_p(args);
	else if	(flags[n].type == 'd' || flags[n].type == 'i')
		ft_printf_di(args, flags[n]);
	else if (flags[n].type == 'o')
		ft_printf_o(args, flags[n]);
	else if (flags[n].type == 'u')
		ft_printf_u(args, flags[n]);
	else if (flags[n].type == 'x' || flags[n].type == 'X')
		ft_printf_x(args, flags[n]);
	else if (flags[n].type == 'f')
		ft_printf_f(args, flags[n]);
	//c,d,e,f,g,i,o,s,u,x
	/*
	if (flags[n].printas == 'c')
		res = ft_printf_c(args, flags, n);
	else if (flags[n].printas == 'd')
		res = ft_printf_d(args, flags, n);
	else if (flags[n].printas == 'e')
		res = ft_printf_e(args, flags, n);
	else if (flags[n].printas == 'f')
		res = ft_printf_f(args, flags, n);
	else if (flags[n].printas == 'g')
		res = ft_printf_g(args, flags, n);
	else if (flags[n].printas == 'i')
		res = ft_printf_i(args, flags, n);
	else if (flags[n].printas == 'o')
		res = ft_printf_o(args, flags, n);
	else if (flags[n].printas == 's')
		res = ft_printf_s(args, flags, n);
	else if (flags[n].printas == 'u')
		res = ft_printf_u(args, flags, n);
	else if (flags[n].printas == 'x')
		res = ft_printf_x(args, flags, n);
	*/
	//free(res);
}
