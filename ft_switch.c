/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 00:10:41 by miyolchy          #+#    #+#             */
/*   Updated: 2025/02/01 01:40:30 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_switch(char spf, va_list args, int fd, const char *base)
{
	if (spf == '%')
		ft_putchar_fd(spf, fd);
	else if (spf == 'c')
		return (print_char(va_arg(args, int), fd));
	else if (spf == 's')
		return (print_str(va_arg(args, char *), fd));
	else if (spf == 'd' || spf == 'i')
		return (print_int(va_arg(args, int), fd));
	else if (spf == 'u')
		return (print_unsigned(va_arg(args, unsigned int), fd));
	else if (spf == 'x')
		return (print_hex_lower(va_arg(args, unsigned int), base, fd));
	else if (spf == 'X')
		return (print_hex_upper(va_arg(args, unsigned int), base, fd));
	else if (spf == 'p')
		return (print_ptr(va_arg(args, void *), base, fd));
	else if (spf == '%')
		ft_putchar_fd(spf, fd);
	return (1);
}
