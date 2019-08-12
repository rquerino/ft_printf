/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:31:28 by rquerino          #+#    #+#             */
/*   Updated: 2019/08/12 15:29:27 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
** Variadic Function: a function that accepts a variable number of arguments.
** printf exists 0 on success, and >0 if an error occurs.
*/

int	ft_printf(const char *str, ...)
{
	va_list args;
	int		ret;

	va_start(args, str);
	ret = ft_doprintf(str, args);
	va_end(args);
	return (ret);
}


/*
** Example of variadic function
*/

int print_ints(int num, ...)
{
	va_list	args;
	int		i;
	int		value;

	i = 0;
	va_start(args, num);	//Takes the va_list as an argument and the last required argument
	while (i < num)
	{
		value = va_arg(args, int);
		printf("%d: %d\n", i, value);
		i++;
	}
	va_end(args);
	return (0);
}


