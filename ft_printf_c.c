/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 13:25:56 by rquerino          #+#    #+#             */
/*   Updated: 2019/08/15 14:11:45 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** c: Print character.
** Probably the simplest to handle.
** %c ignores all flags.
*/

int ft_printf_c(va_list args)
{
	int     var;

	var = va_arg(args, int);
	ft_putchar(var);
	return (0);
}