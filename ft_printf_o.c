/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 14:59:57 by rquerino          #+#    #+#             */
/*   Updated: 2019/09/04 16:36:04 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	ft_nowidth_ox(t_flags flags, char *var)
{
	

}

void	ft_width_ox(t_flags flags, char *var, int len)
{
	

}


/*
** Function to deal with 'o'.
** Uses all the auxiliary functions of 'd'/'i' to handle the flags.
*/

char	*ft_hashtag_ox(t_flags flags, char *var, int len)
{
	char	*new;
	int		i;
	int		j;

	if (flags.type == 'o')
	{
		new = ft_strnew(len + 1);
		new[0] = '0';
		i = 1;
	}
	else
	{
		new = ft_strnew(len + 2);
		new[0] = '0';
		new[1] = 'X';
		i = 2;
	}
	j = 0;
	while (var[j])
	{
		new[i] = var[j];
		i++;
		j++;
	}
	return (new);
}

int		ft_printf_o(va_list args, t_flags flags)
{
	char	*var;
	int		len;

	if (flags.h == 1)
		var = ft_ulltoa_base((unsigned short)va_arg(args, unsigned), 8);
	else if (flags.hh == 1)
		var = ft_ulltoa_base((unsigned char)va_arg(args, unsigned), 8);
	else if (flags.l == 1) 
		var = ft_utoa_base(va_arg(args, unsigned long), 8);
	else if (flags.ll == 1)
		var = ft_utoa_base(va_arg(args, unsigned long long), 8);
	else
		var = ft_utoa_base(va_arg(args, unsigned), 8);
	len = ft_strlen(var);
	if (var && flags.hashtag == 1)
		var = ft_hashtag_ox(flags, var, len);
	len += len >= 0 && flags.hashtag == 1 ? 1 : 0;
	if (flags.width <= len)
		ft_nowidth_ox(flags, var);
	else
		ft_width_ox(flags, var, len);
	ft_strdel(&var);
	return (0);
}