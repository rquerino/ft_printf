/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 11:33:02 by rquerino          #+#    #+#             */
/*   Updated: 2019/09/28 13:59:37 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_ilen(int n)
{
	size_t	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

size_t	ft_lllen_base(long long n, int base)
{
	size_t	i;

	i = 1;
	if (n < 0)
		i++;
	while ((n /= base))
		i++;
	return (i);
}

char	*ft_lltoa(long long n)
{
	char				*res;
	int					len;
	unsigned long long	nbr;
	const char			*b10 = "0123456789";

	len = ft_lllen_base(n, 10);
	nbr = n < 0 ? -n : n;
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	while (--len >= 0 + (n < 0))
	{
		res[len] = b10[nbr % 10];
		nbr /= 10;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}

char	*ft_ltoa(long n)
{
	return (ft_lltoa(n));
}

int		ft_putchar_ptf(char c)
{
	write(1, &c, 1);
	return (1);
}
