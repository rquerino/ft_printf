/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 22:50:11 by rquerino          #+#    #+#             */
/*   Updated: 2019/08/16 00:01:02 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// store 16-bit address, and then pretend that memory is a character array

int	ft_printf_p(va_list args)
{
	void			*var;
	int				ptr;
	unsigned char	tmp;
	char			string[] = "0123456789ABCDEF";

	var = va_arg(args, void *);
	ptr = (int) &var;
	tmp = *(1 + (unsigned char*) &ptr); // MSB
	ft_putchar( string[tmp >> 4] );
	ft_putchar( string[tmp & 0xF] );
	tmp = *(0 + (unsigned char*) &ptr); // LSB
	ft_putchar( string[tmp >> 4] );
	ft_putchar( string[tmp & 0xF] );
	return (0);
}