/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 21:22:26 by rquerino          #+#    #+#             */
/*   Updated: 2019/09/07 18:39:20 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** hashtag = 1 and number != 0, start with 0x ONLY!!!!!!!!
** 
*/

char	*ft_precision_x(t_flags flags, char *var, int len)
{
	int		i;
	int		j;
	char	*final;

	if (flags.justdot == 1)
		return (ft_strnew(0));
	final = ft_strnew(flags.afterdot);
	i = 0;
	j = 0;
	while (i < (flags.afterdot - len))
	{
		final[i++] = '0';
	}
	while (var[j])
		final[i++] = var[j++];
	return (final);
}

void	ft_makehexlower(char *var)
{
	int	i;

	i = 0;
	while (var[i])
	{
		ft_putchar(ft_tolower(var[i]));
		i++;
	}
}

void	ft_width_x(t_flags flags, char *var, int len)
{

}

int		ft_printf_x(va_list args, t_flags flags)
{
	int		len;
    char    *var;

    if (flags.h == 1)
        var = ft_utoa_base((unsigned short)va_arg(args, unsigned), 16);
    else if (flags.hh == 1)
        var = ft_utoa_base((unsigned char)va_arg(args, unsigned), 16);
    else if (flags.l == 1)
        var = ft_ulltoa_base(va_arg(args, unsigned long), 16);
    else if (flags.ll == 1)
        var = ft_ulltoa_base(va_arg(args, unsigned long long), 16);
	else
		var = ft_utoa_base(va_arg(args, unsigned), 16);
	len = ft_strlen(var);
	if (flags.afterdot > len || flags.justdot == 1)
	{
		var = ft_precision_x(flags, var, len);
		len = flags.afterdot;
	}
	if (var && flags.hashtag)
		len += 2;
	if (flags.width > len)
		ft_width_x(flags, var, len);
	else
	{
		if (flags.hashtag)
			ft_putstr("0x");
		if (flags.type == 'x')
			ft_makehexlower(var);
		else
			ft_putstr(var);
	}
	ft_strdel(&var);
	return (0);
}