/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:31:21 by rquerino          #+#    #+#             */
/*   Updated: 2019/09/07 14:58:42 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
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
	int		h;
	int		hh;
	int		l;
	int		ll;
	int		L;
}               t_flags;

/*
** Functions
*/

int		ft_printf(const char *str, ...);
int		ft_countargs(const char *str);
void	ft_startstruct(t_flags *flags, int n);
void	ft_printflags(t_flags flags);

int		ft_countargs(const char *str);
void	ft_printflags(t_flags flags);
int		ft_getwidth(const char *str, t_flags *flags, int i, int n);
int		ft_getafterdot(const char *str, t_flags *flags, int i, int n);
int		ft_getlength(const char *str, t_flags flags, int i);
int		ft_checkflags(const char *str, t_flags *flags, int i, int n);
void	ft_reader(const char *str, va_list args, t_flags *flags);
void	ft_startstruct(t_flags *flags, int n);
int		ft_getlen(va_list args, int n);
char	*ft_readflags(t_flags flags, int arg_len, va_list args, int n);
void	ft_printer(va_list args, t_flags *flags, int n);
char	*ft_lltoa(long long n);
char    *ft_ltoa(long n);
size_t	ft_ulllen_base(unsigned long long n, int base);
size_t	ft_ilen(int n);
char	*ft_utoa_base(unsigned n, int base);
char	*ft_ultoa_base(unsigned long n, int base);
char	*ft_ulltoa_base(unsigned long long n, int base);
int		ft_checkround(int n, int precision);
int		ft_roundafter(long double n, int precision);
void	ft_dotafter(char *res, char *after, int precision);
char	*ft_afterdot(long double n, int precision);
char	*ft_ldtoa(long double n, int precision);
char	*ft_dtoa(double n, int precision);

/*
** Functions for type 's'
*/

int		ft_printf_s(va_list args, t_flags flags);
void	ft_checkwidth_s(t_flags flags, char *res, int len);
void	ft_checkjwidth_s(t_flags flags, char *res);
char	*ft_checkdot_s(t_flags flags, char *var);//, int len);

/*
** Functions for type 'c'
*/

int		ft_printf_c(va_list args, t_flags flags);

/*
** Functions for type 'p'
*/

int		ft_printf_p(va_list args, t_flags flags);
char	*ft_transform_base(unsigned long long n, int base);
int		ft_blen(unsigned long long n, int base);

/*
** Functions for type 'd' and 'i'
*/

int		ft_printf_di(va_list args, t_flags flags);
void	ft_width_di(t_flags flags, char *var, int len);
void	ft_nowidth_di(t_flags flags, char *var);
void	ft_fillwidth(t_flags flags, int len);
char	*ft_precision_di(char *var, int precision, int len);

/*
** Functions for type 'o'
*/

int		ft_printf_o(va_list args, t_flags flags);
void	ft_width_ox(t_flags flags, char *var, int len);
char	*ft_precision_o(t_flags flags, char *var, int len);

/*
** Functions for type 'u'
*/

int		ft_printf_u(va_list args, t_flags flags);
char	*ft_precision_u(t_flags flags, char *var, int len);

/*
** Functions for type 'x' and 'X'
*/

int		ft_printf_x(va_list args, t_flags flags);
void	ft_makehexlower(char *var);
char	*ft_precision_x(t_flags flags, char *var, int len);

/*
** Functions for type 'f'
*/

int		ft_printf_f(va_list args, t_flags flags);
void	ft_nowidth_f(t_flags flags, char *var);
void	ft_width_f(t_flags flags, char *var, int len);

#endif
