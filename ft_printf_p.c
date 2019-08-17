/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 22:50:11 by rquerino          #+#    #+#             */
/*   Updated: 2019/08/16 15:37:14 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char			*g_chars = "0123456789ABCDEF";


int		ft_len_base(unsigned long long n, int base)
{
	int	i;

	i = 1;
	while ((n /= base))
		i++;
	return (i);
}

char				*ft_ulltoa_base(unsigned long long n, int base)
{
	char	*res;
	int		len;
	int		i;

	len = ft_len_base(n, base);
	RETURN_VAL_IF_FAIL(NULL, (res = ft_strnew(len)));
	i = len;
	while (--i >= 0)
	{
		res[i] = g_chars[n % base];
		n /= base;
	}
	return (res);
}


// store 16-bit address, and then pretend that memory is a character array

int	ft_printf_p(va_list args)
{
	unsigned long int	var;
	unsigned char	tmp;
	char			string[] = "0123456789ABCDEF";
	
	var = (unsigned long int)va_arg(args, void *);
	tmp = *(1 + (unsigned char*) &var);
	ft_putstr("0x");
	ft_putchar( string[tmp >> 4] );
	ft_putchar( string[tmp & 0xF] );
	tmp = *(0 + (unsigned char*) &var);
	ft_putchar( string[tmp >> 4] );
	ft_putchar( string[tmp & 0xF] );
	return (0);
}
