/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:31:28 by rquerino          #+#    #+#             */
/*   Updated: 2019/09/27 16:11:14 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

// gcc -Wall -Wextra -Werror ft_printf.c read.c printer.c ft_printf_d.c ft_printf_s.c ft_printf_c.c ft_printf_p.c aux.c ft_dtoa.c ft_printf_f.c ft_printf_o.c ft_printf_x.c ft_printf_u.c libft/libft.a

/*
Stuff to handle:

- Return the number of printed chars
- Free on 's'

Basic flag errors: 
'-' makes '0' useless. Need to advise the user
'+' and ' ' are undefined behavior to %o
'0' is ignored when there is a '-' flag (at least with %o, need to test with others)


*/


/*
** Error management:
** 1: Insuficient arguments;
** 2: Argument doesn't match flag;
** 3: Invalid flag;
*/

void	ft_printerror(int error)
{
	if (error == 1)
	{

	}
	else if (error == 2)
	{

	}
	else if (error == 3)
	{
		
	}
}

/*
** Print flags to check if it's Ok.
*/

void	ft_printflags(t_flags flags)
{
	ft_putchar('\n');
	printf("Type: %c\n", flags.type);
	printf("Hashtag: %d\n", flags.hashtag);
	printf("Zero: %d\n", flags.zero);
	printf("Justdot: %d\n", flags.justdot);
	printf("Afterdot: %d\n", flags.afterdot);
	printf("Justify: %d\n", flags.justify);
	printf("Plus: %d\n", flags.plus);
	printf("Hidden plus: %d\n", flags.hiddenplus);
	printf("Width: %d\n", flags.width);
	printf("h: %d\n", flags.h);
	printf("hh: %d\n", flags.hh);
	printf("l: %d\n", flags.l);
	printf("ll: %d\n", flags.ll);
	printf("L: %d\n", flags.L);
	ft_putchar('\n');
}

/*
** Start the structure to argument n.
*/

void	ft_startstruct(t_flags *flags, int n)
{
	flags[n].type = 'a';
	flags[n].justdot = 0;
	flags[n].afterdot = 0;
	flags[n].hashtag = 0;
	flags[n].hiddenplus = 0;
	flags[n].justify = 0;
	flags[n].plus = 0;
	flags[n].type = 0;
	flags[n].width = 0;
	flags[n].zero = 0;
	flags[n].h = 0;
	flags[n].hh = 0;
	flags[n].l = 0;
	flags[n].ll = 0;
	flags[n].L = 0;
}

/*
** Counts how many arguments were passed after the string.
*/

int		ft_countargs(const char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while(str[i])
	{
		if (str[i] == '%' && str[i + 1] == '%')
			i++;
		if (str[i] == '%' && str[i + 1] != '%')
		{
			while (str[i] != 'c' && str[i] != 'd' && str[i] != 'e' &&
				str[i] != 'f' && str[i] != 'g' && str[i] != 'i' &&
				str[i] != 'o' && str[i] != 's' && str[i] != 'u' &&
				str[i] != 'x' && str[i] != 'p')
				i++;
			n += 1;
		}
		i++;
	}
	return (n);
}

/*
** Variadic Function: a function that accepts a variable number of arguments.
** printf exists 0 on success, and >0 if an error occurs.
*/

int	ft_printf(const char *str, ...)
{
	va_list args;
	t_flags *flags;
	int		n_args;
	int		ret;

	n_args = ft_countargs(str);
	flags = malloc(sizeof(t_flags) * n_args);
	va_start(args, str);
	ret = ft_reader(str, args, flags);
	va_end(args);
	return (ret);
}