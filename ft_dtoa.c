/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 14:49:58 by rquerino          #+#    #+#             */
/*   Updated: 2019/09/03 22:49:13 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "math.h"

/*
** Extract the integer part of the number.
*/

char	*ft_beforedot(long double n)
{
	int		nbr;

	nbr = (int)n;
	return (ft_itoa(nbr));
}

/*
** Returns the length of the number after dot.
*/

size_t	ft_afterdotlen(long double n)
{
	int			len;
	int			before;
	long double	after;

	len = 0;
	before = (int)n;
	after = n - before;
	after *= after < 0 ? -1 : 1;
	//ERROR HERE, FLOAT HAS MORE DECIMALS
	while (after > 0.001)
	{
		after *= 10;
		len++;
		before = (int)after;
		after = after - before;
	}
	return (len);
}

/*
** Returns ".0000" format.
*/

void	ft_dotafter(char *res, char *after)
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
}

/*
** Extract the fraction part.
*/

char	*ft_afterdot(long double n)
{
	long double	after;
	int			aux;
	int			aft_len;
	char		*res;

	aux = (int)n;
	aft_len = ft_afterdotlen(n);
	if (aft_len > 0)
	{
		after = n - (long double)aux;
		aux = (int)after;
		res = ft_strnew(aft_len + 1);
		ft_dotafter(res, ft_itoa(aux));
		return (res);
	}
	else
		return (NULL);
}

char	*ft_ldtoa(long double n)
{
	char	*before;
	char	*after;
	char	*res;

	before = ft_beforedot(n);
	after = ft_afterdot(n);
	if (after)
	{
		res = ft_strcat(before, after);
		return (res);
	}
	else
		return (before);
}

char	*ft_dtoa(double n)
{
	return (ft_ldtoa(n));
}