/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 14:49:58 by rquerino          #+#    #+#             */
/*   Updated: 2019/09/28 12:35:32 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

/*
** Elevates any number n to the power of pow. In this case, we're using to
** round the numbers based on the precision passed.
*/

double	ft_pow(double n, int pow)
{
	return (pow ? n * ft_pow(n, pow - 1) : 1);
}

/*
** Function to round the number based on the precision. If the precision is 0,
** checks if the first decimal is >= 5 and then rounds up.
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

char	*ft_auxldtoa(long double n)
{
	if ((int)n == 0 && n < 0 && ((n - (int)n) * 10 < 5))
		return (ft_strdup("-0"));
	if (n > 0 ? (n - (int)n) * 10 >= 5 : (n - (int)n) * 10 <= -5)
		return (ft_itoa((int)n + (n > 0 ? 1 : -1)));
	return (ft_itoa((int)n));
}

char	*ft_ldtoa(long double n, int precision)
{
	char		*s;
	long long	aux;
	long long	t;
	int			length;

	if (precision == 0)
		return (ft_auxldtoa(n));
	aux = ft_round(n, precision);
	t = (aux < 0) ? -aux : aux;
	length = (n < 0 ? 3 : 2);
	while (aux /= 10)
		++length;
	(n < 1 && n > -1) ? length = 3 + precision : 0;
	(n >= 0 && n < 1) ? length = 2 + precision : 0;
	if (!(s = (char *)malloc(sizeof(char) * length)))
		return (NULL);
	s[length] = '\0';
	while (length--)
	{
		s[length] = (!precision--) ? '.' : t % 10 + '0';
		t /= (precision + 1) ? 10 : 1;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}

char	*ft_dtoa(double n, int precision)
{
	return (ft_ldtoa(n, precision));
}
