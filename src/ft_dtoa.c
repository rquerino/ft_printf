/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 14:49:58 by rquerino          #+#    #+#             */
/*   Updated: 2019/09/27 13:52:44 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

/*
** Extract the integer part of the number.
*/

// int		ft_checkround(int n, int after)
// {
// 	char	*check;
// 	int		len;

// 	check = ft_itoa(n);
// 	len = ft_strlen(check);
// 	//if (check[len - 1] != '9' && after == 999)
// 	if (after >= 500)
// 	{
// 		ft_strdel(&check);
// 		return (1);
// 	}
// 	ft_strdel(&check);
// 	return (0);
// }

// /*
// ** Returns the length of the number after dot.
// */

// char	*ft_roundbefore(long double n, int precision)
// {
// 	int			aux;
// 	long double	after;
// 	int			neg;

// 	if ((int)n == 0 && n < 0)
// 		return (strdup("-0"));
// 	neg = n > 0 ? 1 : -1;
// 	aux = n > 0 ? (int)n : (int)-n;
// 	after = n - (int)n;
// 	if (precision == 0)
// 	{
// 		after *= after > 0 ? 10 : -10;
// 		if (after >= 5)
// 			aux += 1;
// 	}	
// 	return (ft_itoa(neg * aux));
// }

// /*
// ** Returns ".0000" format.
// */

// void	ft_dotafter(char *res, char *after, int precision, int zerosbefore)
// {
// 	int	i;
// 	int	j;
// 	int	len;

// 	i = 1;
// 	j = 0;
// 	len = ft_strlen(after);
// 	res[0] = '.';
// 	zerosbefore -= (zerosbefore + len > precision && ft_strcmp(after, "0")) ? len : 0;
// 	while (i <= zerosbefore)
// 		res[i++] = '0';
// 	while (after[j] && ft_strcmp(after, "0"))
// 	{
// 		res[i] = after[j];
// 		i++;
// 		j++;
// 	}
// 	if (precision - zerosbefore > 0)
// 		while (i < (precision - zerosbefore) + 1)
// 			res[i++] = '0';
// }

// /*
// ** Extract the fraction part.
// */

// char	*ft_afterdot(long double n, int precision)
// {
// 	long double	after;
// 	int			i;
// 	int			aux;
// 	char		*res;
// 	int			zerosbefore;

// 	if (precision == 0)
// 		return (ft_strnew(0));
// 	i = 0;
// 	aux = (int)n;
// 	after = n - aux;
// 	after *= after < 0 ? -1 : 1;
// 	res = ft_strnew(precision + 1);
// 	zerosbefore = 0;
// 	while (i < precision)
// 	{
// 		after *= 10;
// 		if (after < 1)
// 			zerosbefore++;
// 		i++;
// 	}
// 	aux = (int)after;
// 	after = after - (int)after;
// 	//CONFERIR SE PRECISION >6 TRATA OS ARREDONDAMENTOS
// 	if (
// 	else if (ft_checkround(aux, (int)(after * 1000))) 
// 		aux += 1;
// 	ft_dotafter(res, ft_itoa(aux), precision, zerosbefore);
// 	return (res);
// }

// char	*ft_ldtoa(long double n, int precision)
// {
// 	char	*before;
// 	char	*after;
// 	char	*res;
	
// 	before = ft_roundbefore(n, precision);
// 	after = ft_afterdot(n, precision);
// 	res = ft_strcat(before, after);
// 	//printf("\n\nres: %s\n\n", res);
// 	return (res);
// }


/*
** Elevates any number n to the power of pow. In this case, we're using to round the numbers
** based on the precision passed.
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


char	*ft_ldtoa(long double n, int precision)
{
	char		*s;
	long long	aux;
	long long	t;
	int			length;

	if (precision == 0)
	{
		if ((int)n == 0 && n < 0 && ((n - (int)n) * 10 < 5))
			return (ft_strdup("-0"));
		if (n > 0 ? (n - (int)n) * 10 >= 5 : (n - (int)n) * 10 <= -5)
			return (ft_itoa((int)n + (n > 0 ? 1 : -1)));
		return (ft_itoa((int)n));
	}
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