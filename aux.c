/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 11:33:02 by rquerino          #+#    #+#             */
/*   Updated: 2019/08/29 11:46:04 by rquerino         ###   ########.fr       */
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

size_t		ft_ulllen_base(unsigned long long n, int base)
{
	size_t	i;

	i = 1;
	while ((n /= base))
		i++;
	return (i);
}

char    *ft_ltoa(long long n)
{
	char				*res;
	int					len;
	unsigned long long	nbr;
	const char			*b16 = "0123456789ABCDEF";

	len = ft_ulllen_base(n, 10);
	len += n < 0 ? 1 : 0;
	nbr = n < 0 ? -n : n;
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	while (--len >= 0 + (n < 0))
	{
		res[len] = b16[n % 10];
		nbr /= 10;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}

char	*ft_utoa_base(unsigned n, int base)
{
	char	*res;
	int		len;
	const char	*b16 = "0123456789ABCDEF";

	len = ft_ulllen_base(n, base);
	len += n < 0 ? 1 : 0;
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	while (--len >= 0 + (n < 0))
	{
		res[len] = b16[n % base];
		n /= base;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}

char	*ft_ulltoa_base(unsigned long long n, int base)
{
	char	*res;
	int		len;
	const char	*b16 = "0123456789ABCDEF";

	len = ft_ulllen_base(n, base);
	len += n < 0 ? 1 : 0;
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	while (--len >= 0 + (n < 0))
	{
		res[len] = b16[n % base];
		n /= base;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}