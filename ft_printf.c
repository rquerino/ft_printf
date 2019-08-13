/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:31:28 by rquerino          #+#    #+#             */
/*   Updated: 2019/08/12 22:15:05 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>


/*
** Simple function to print a char.
*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
** Print flags to check if it's Ok.
*/

void	ft_printflags(t_flags *flags)
{
	int x;

	x = 0;
	while (x <= 1)
	{
		printf("Variable %d\n", x);
		printf("Type: %c\n", flags[x].type);
		printf("Hashtag: %d\n", flags[x].hashtag);
		printf("Zero: %d\n", flags[x].zero);
		printf("Justdot: %d\n", flags[x].justdot);
		printf("Afterdot: %d\n", flags[x].afterdot);
		printf("Justify: %d\n", flags[x].justify);
		printf("Plus: %d\n", flags[x].plus);
		printf("Hidden plus: %d\n", flags[x].hiddenplus);
		printf("Width: %d\n", flags[x].width);
		printf("Star: %d\n", flags[x].star);
		printf("Dollar: %d\n", flags[x].dollar);
		ft_putchar('\n');
		x++;
	}
}

/*
** Start the structure to argument n.
*/

void	ft_startstruct(t_flags *flags, int n)
{
	flags[n].type = 'a';
	flags[n].justdot = 0;
	flags[n].afterdot = 0;
	flags[n].dollar = 0;
	flags[n].hashtag = 0;
	flags[n].hiddenplus = 0;
	flags[n].justify = 0;
	flags[n].plus = 0;
	flags[n].star = 0;
	flags[n].type = 0;
	flags[n].width = 0;
	flags[n].zero = 0;
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

	flags = NULL;
	flags = malloc(sizeof(flags) * 2);
	va_start(args, str);
	//ret = ft_doprintf(str, args);
	ft_reader(str, flags);
	ft_putchar('\n');
	ft_printflags(flags);
	va_end(args);
	return (1);
	//return (ret);
}

int	main()
{
	ft_printf("Test %% flags %-+5.d , %10s");
	return (0);
}

