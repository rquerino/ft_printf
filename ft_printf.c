/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:31:28 by rquerino          #+#    #+#             */
/*   Updated: 2019/08/12 17:49:55 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_printflags(t_flags *flags)
{
	int x;

	x = 0;
	while (x < 2)
	{
		printf("Variable %d:\n", x);
		printf("Type: %c\n", flags[x].type);
		printf("Hashtag: %d\n", flags[x].hashtag);
		printf("Zero: %c\n", flags[x].zero);
		printf("Afterdot: %c\n", flags[x].afterdot);
		printf("Justify: %c\n", flags[x].justify);
		printf("Plus: %c\n", flags[x].plus);
		printf("Hidden plus: %c\n", flags[x].hiddenplus);
		printf("Width: %c\n", flags[x].width);
		printf("Star: %c\n", flags[x].star);
		printf("Dollar: %c\n", flags[x].dollar);
		ft_putchar('\n');
		x++;
	}
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
	flags = malloc(sizeof(flags) * 2); //change later
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
	ft_printf("Testing %% the flags %-+5d and %10s");
	return (0);
}

