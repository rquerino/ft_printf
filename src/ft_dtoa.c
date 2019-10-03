/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 14:49:58 by rquerino          #+#    #+#             */
/*   Updated: 2019/10/03 10:36:25 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

/*
** Elevates any number n to the power of pow. In this case, we're using to
** round the numbers based on the precision passed. 10 ^ something.
*/

double	ft_pow(double n, int pow)
{
	return (pow ? n * ft_pow(n, pow - 1) : 1);
}

/*
** Function to round the number based on the precision. If the precision is 0,
** checks if the first decimal is >= 5 and then rounds up. Returns the Aux nbr.
*/

long	ft_round(long double n, int precision)
{
	long long	aux;

	aux = n * ft_pow(10, precision + 1);
	if (aux % 10 >= 5)
		aux = aux / 10 + 1;
	else if (aux % 10 <= -5)
		aux = aux / 10 - 1;
	else
		aux /= 10;
	return (aux);
}

/*
** Deals with cases where precision is 0.
*/

char	*ft_auxldtoa(long double n)
{
	if ((int)n == 0 && n < 0 && ((n - (int)n) * 10 < 5))
		return (ft_strdup("-0"));
	if (n > 0 ? (n - (int)n) * 10 >= 5 : (n - (int)n) * 10 <= -5)
		return (ft_itoa((int)n + (n > 0 ? 1 : -1)));
	return (ft_itoa((int)n));
}

/*
** Function to transform a double to string.
** len: 3(neg) or 2(pos) + aux=/10 len++ or precision (0.something).
** 3('-', at least 1nbr before dot and '.'), 2(without '-').
** Can't handle numbers bigger than a max_int or min_int.
*/

char	*ft_ldtoa(long double n, int precision)
{
	char		*res;
	long long	aux;
	long long	tmp;
	int			len;

	if (precision == 0)
		return (ft_auxldtoa(n));
	aux = ft_round(n, precision);
	tmp = (aux < 0) ? -aux : aux;
	len = (n < 0 ? 3 : 2);
	while (aux /= 10)
		len++;
	(n < 0 && n > -1) ? len = 3 + precision : 0;
	(n >= 0 && n < 1) ? len = 2 + precision : 0;
	if (!(res = ft_strnew(len)))
		return (NULL);
	while (len--)
	{
		res[len] = (!precision--) ? '.' : tmp % 10 + '0';
		tmp /= (precision + 1) ? 10 : 1;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}

char	*ft_dtoa(double n, int precision)
{
	return (ft_ldtoa(n, precision));
}
