/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:31:28 by rquerino          #+#    #+#             */
/*   Updated: 2019/08/20 21:05:14 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

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
	//int		ret;
	t_flags *flags;
	int		n_args;
	/*int		i;
	double	d;
	char	*s;*/

	n_args = ft_countargs(str);
	//flags = NULL;
	flags = malloc(sizeof(t_flags) * n_args);
	va_start(args, str);
	//ret = ft_doprintf(str, args);
	ft_reader(str, args, flags);
	ft_putchar('\n');
	va_end(args);
	return (1);
	//return (ret);
}

int	main()
{
	/*
	//Testing 's'
	ft_putstr("Testing 's':\n");
	ft_putstr("Params: ...%-1s..., abc\n");
	ft_printf("...%-1s...", "abc");
	ft_putstr("\n\n");
	ft_putstr("Params: ...%-3s..., ab\n");
	ft_printf("...%-3s...", "ab");
	ft_putstr("\n\n");
	ft_putstr("Params: ...%-10s..., abcde\n");
	ft_printf("...%-10s...", "abcde");
	ft_putstr("\n\n");
	ft_putstr("Params: ...%5s..., abc\n");
	ft_printf("...%5s...", "abc");
	ft_putstr("\n\n");
	ft_putstr("Params: ...%5.2s..., abcd\n");
	ft_printf("...%5.2s...", "abcd");
	ft_putstr("\n\n");
	ft_putstr("Params: ...%5.s..., abcd\n");
	ft_printf("...%5.s...", "abcd");
	ft_putstr("\n\n");
	ft_putstr("Params: ...%-2.s..., abcd\n");
	ft_printf("...%-2.s...", "abcd");
	ft_putstr("\n\n");
	ft_putstr("Params: ...%-2.s...%4.1s..., abc, def\n");
	ft_printf("...%-2.s...%4.1s...", "abcd", "def");
	ft_putstr("\n\n");
	ft_putstr("Params: ...%.s...%-12s..., abcd, 1234567\n");
	ft_printf("...%.s...%-12s...", "abcd", "1234567");
	*/
	//Testing 'c'
	/*
	ft_putstr("Testing 'c':\n");
	ft_putstr("Params: ...%c...%c..., 97, a, b\n");
	ft_printf("...%c...%c...%c...", 97, 'a', 'b');
	ft_putstr("\n\n");
	*/
	//Testing 'p'
	/*int	x = 10;
	int *a = &x;

	ft_putstr("Testing 'p':\n");
	ft_putstr("Params: ...%p..., int *a\n");
	ft_printf("...%p...", a);
	ft_putstr("\n\n");
	printf("...%p...", a);*/

	//Testing 'd' and 'i'
	ft_putstr("Testing 'd' and 'i':\n");
	ft_putstr("Params: ...%-10d...%-+5i..., -500, 125\n");
	ft_printf("....%-10d...%-+5i...", -500, 125);
	ft_putstr("\n\n");
	ft_putstr("...%04d...%- 03i, 10, 2\n");
	ft_printf("...%04d...%- 03i", 10, 2);
	ft_putstr("\n\n");
	return (0);
}

