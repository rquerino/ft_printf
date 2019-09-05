/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 22:50:11 by rquerino          #+#    #+#             */
/*   Updated: 2019/09/05 11:40:50 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Function that returns the size of a number
** based on its base.
*/

int		ft_blen(unsigned long long n, int base)
{
	int	i;

	i = 1;
	while ((n /= base))
		i++;
	return (i);
}

/*
** Returns the number converted on base (until 16).
** All letters are uppercase.
*/

char	*ft_transform_base(unsigned long long n, int base)
{
	char		*res;
	int			len;
	int			i;
	const char	*b16 = "0123456789ABCDEF";

	len = ft_blen(n, base);
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	i = len;
	while (--i >= 0)
	{
		res[i] = b16[n % base];
		n /= base;
	}
	return (res);
}


// store 16-bit address, and then pretend that memory is a character array

int		ft_printf_p(va_list args)
{
	unsigned long int	var;
	char				*res;
	int					i;

	i = 0;
	var = (unsigned long int)va_arg(args, void *);
	//res = ft_strcat("0x", ft_transform_base(var, 16));
	ft_putstr("0x");
	res = ft_transform_base(var, 16);
	while (res[i])
	{
		ft_putchar(ft_tolower(res[i]));
		i++;
	}
	return (0);
}
