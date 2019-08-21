/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:31:21 by rquerino          #+#    #+#             */
/*   Updated: 2019/08/20 21:15:57 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define	FL_h = 32
# define	FL_hh = 64
# define	FL_l = 128
# define	FL_ll = 256
# define	FL_L = 512
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

/*
** Functions for type 's'
*/

//char	*ft_printf_s(va_list args, t_flags *flags, int n);
int		ft_printf_s(va_list args, t_flags flags);
void	ft_checkwidth_s(t_flags flags, char *res, int len);
void	ft_checkjwidth_s(t_flags flags, char *res);
char	*ft_checkdot_s(t_flags flags, char *var);//, int len);

/*
** Functions for type 'c'
*/

int		ft_printf_c(va_list args);

/*
** Functions for type 'p'
*/

int		ft_printf_p(va_list args);
char	*ft_transform_base(unsigned long long n, int base);
int		ft_blen(unsigned long long n, int base);

/*
** Functions for type 'd' and 'i'
*/

int		ft_printf_di(va_list args, t_flags flags);
void	ft_width_di(t_flags flags, int var, int len);
void	ft_nowidth_di(t_flags flags, int var);
void	ft_fillwidth(t_flags flags, int len);
int		ft_intlen(int num);

#endif
