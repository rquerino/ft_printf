/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 11:33:02 by rquerino          #+#    #+#             */
/*   Updated: 2019/08/23 10:23:15 by rquerino         ###   ########.fr       */
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

size_t		ft_ulllen(unsigned long long n)
{
	size_t	i;

	i = 1;
	while ((n /= 10))
		i++;
	return (i);
}

char    *ft_ltoa(long long n)
{
	char				*res;
	int					len;
	unsigned long long	nbr;
	const char			*b10 = "0123456789";

	len = ft_ulllen(n);
	len += n < 0 ? 1 : 0;
	nbr = n < 0 ? -n : n;
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	while (--len >= 0 + (n < 0))
	{
		res[len] = b10[n % 10];
		nbr /= 10;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}