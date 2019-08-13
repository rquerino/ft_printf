/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:31:21 by rquerino          #+#    #+#             */
/*   Updated: 2019/08/12 21:44:11 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

/*
** Most of this flags are 1 if present, 0 if not.
** Except fl_width and fl_afterdot, they receive the number used.
*/

typedef struct  s_flags
{
	char	type;
	int		hashtag;
	int		zero;
	int		justdot;
	int		afterdot;
	int		justify;
	int		plus;
	int		hiddenplus;
	int		width;
	int		star;
	int		dollar;
}               t_flags;

void	ft_putchar(char c);
int		ft_getwidth(const char *str, t_flags *flags, int i, int n);
int		ft_getafterdot(const char *str, t_flags *flags, int i, int n);
int		ft_checkflags(const char *str, t_flags *flags, int i, int n);
void	ft_reader(const char *str, t_flags *flags);
void	ft_startstruct(t_flags *flags, int n);

#endif
