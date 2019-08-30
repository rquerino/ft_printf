/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 13:45:15 by rquerino          #+#    #+#             */
/*   Updated: 2019/08/30 11:44:40 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int		ft_flen(long double n)
{

}

/*
** Function to transform long double to string.
** Divides the double in before dot and after dot.
*/

char	*ft_ldtoa(long double n)
{
	char	*res;
	int		len;
	int		i;

	len = ft_flen(n);


}



int		ft_printf_f(va_list args, t_flags flags)
{
	int		len;
    char    *var;

    if (flags.L == 1)
        var = ft_ldtoa((va_arg(args, long double));
	else
		var = ft_ldtoa(va_arg(args, double));
	len = ft_strlen(var);
	len += len >= 0 && (flags.plus == 1 || flags.hiddenplus == 1) ? 1 : 0;
	if (flags.type == 'x')
		ft_makehexlower(var);
	if (flags.width <= len)
		ft_nowidth_di(flags, var);
	else
		ft_width_di(flags, var, len);
	ft_strdel(&var);
	return (0);
}