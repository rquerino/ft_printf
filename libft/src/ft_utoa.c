/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:32:49 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/09/28 15:20:11 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline char	*ft_utoa(unsigned n)
{
	return (ft_ulltoa_base(n, 10));
}

inline char	*ft_utoa_base(unsigned n, int base)
{
	return (ft_ulltoa_base(n, base));
}
