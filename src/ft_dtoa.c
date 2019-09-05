/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 14:49:58 by rquerino          #+#    #+#             */
/*   Updated: 2019/09/05 11:40:50 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

/*
** Extract the integer part of the number.
*/

int		ft_checkround(int n, int precision)
{
	char *check;

	check = ft_itoa(n);
	if (check[precision - 1] == '9' && check[precision - 2] == '9')
	{
		ft_strdel(&check);
		return (1);
	}
	ft_strdel(&check);
	return (0);
}

/*
** Returns the length of the number after dot.
*/

int		ft_roundafter(long double n, int precision)
{
	int			aux;
	long double	after;
	int			i;

	i = 0;
	aux = (int)n;
	after = n - aux;
	after *= after < 0 ? -1 : 1;
	while (i < precision)
	{
		after *= 10;
		i++;
	}
	//printf("\n\ni: %i\n\n", i);
	aux = (int)after;
	after = after - aux;
	return ((int)after * 10);
}

/*
** Returns ".0000" format.
*/

void	ft_dotafter(char *res, char *after, int precision)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	res[0] = '.';
	while (after[j])
	{
		res[i] = after[j];
		i++;
		j++;
	}
	while (i < precision + 1)
	{
		res[i] = '0';
		i++;
	}
}

/*
** Extract the fraction part.
*/

char	*ft_afterdot(long double n, int precision)
{
	long double	after;
	int			i;
	int			aux;
	char		*res;

	i = 0;
	aux = (int)n;
	after = n - aux;
	after *= after < 0 ? -1 : 1;
	res = ft_strnew(precision + 1);
	while (i < precision)
	{
		after *= 10;
		i++;
	}
	aux = (int)after;
	//CONFERIR SE PRECISION >6 TRATA OS ARREDONDAMENTOS
	if (ft_roundafter(n, precision) >= 5 || ft_checkround(aux, precision)) 
		aux += 1;
	ft_dotafter(res, ft_itoa(aux), precision);
	return (res);
}

char	*ft_ldtoa(long double n, int precision)
{
	char	*before;
	char	*after;
	char	*res;

	before = ft_itoa((int)n);
	after = ft_afterdot(n, precision);
	res = ft_strcat(before, after);
	//printf("\n\nres: %s\n\n", res);
	return (res);
}

char	*ft_dtoa(double n, int precision)
{
	return (ft_ldtoa(n, precision));
}