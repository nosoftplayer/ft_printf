/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 00:10:41 by miyolchy          #+#    #+#             */
/*   Updated: 2025/02/01 02:04:52 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		size;
	int		fd;

	size = 0;
	fd = 1;
	va_start(args, format);
	if (!format || !*format)
		return (0);
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			size = size + ft_switch(*format, args, fd);
		}
		else
		{
			++size;
			ft_putchar_fd(*format, fd);
		}
		++format;
	}
	va_end(args);
	return (size);
}
/*
#include <stdio.h>

int main(void)
{
	int i = 1234;
	int k = 1234;
	int p    =    printf("%p\n", &i);
	int ft_p = ft_printf("%p\n", &i);
	printf("int p     = %d\nint ft_p  = %d\n", p, ft_p);
}
*/