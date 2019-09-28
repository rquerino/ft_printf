/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:29:38 by rquerino          #+#    #+#             */
/*   Updated: 2019/09/28 15:19:43 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*g_chars = "0123456789ABCDEF";

char		*ft_ulltoa_base(unsigned long long n, int base)
{
	char	*res;
	int		len;
	int		i;

	len = ft_ull_len_base(n, base);
	if ((res = ft_strnew(len)) == NULL)
		return (NULL);
	i = len;
	while (--i >= 0)
	{
		res[i] = g_chars[n % base];
		n /= base;
	}
	return (res);
}

inline char	*ft_ulltoa(unsigned long long n)
{
	return (ft_ulltoa_base(n, 10));
}

inline char	*ft_ultoa_base(unsigned long n, int base)
{
	return (ft_ulltoa_base(n, base));
}

inline char	*ft_ultoa(unsigned long n)
{
	return (ft_ulltoa_base(n, 10));
}
