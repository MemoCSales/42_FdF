/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:41:56 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/02/25 17:25:30 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	printchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_placeholders(const char *format, va_list args)
{
	int	i;

	i = 0;
	if (*format == 'c')
		i += printchar(va_arg(args, int));
	else if (*format == 's')
		i += printstring(va_arg(args, char *));
	else if (*format == 'd' || *format == 'i')
		i += printdecimal(va_arg(args, int));
	else if (*format == 'u')
		i += printunsigned(va_arg(args, unsigned int));
	else if (*format == 'X' || *format == 'x')
		i += printhexa(va_arg(args, unsigned int), format);
	else if (*format == 'p')
	{
		i += printstring("0x");
		i += printhexa(va_arg(args, unsigned long long), format);
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;

	va_start (args, format);
	i = 0;
	while (*format)
	{
		if (*format == '%' && ft_strchr2("cspdiuxX", *(++format)))
			i += ft_placeholders(format, args);
		else if (*format == '%')
			i += printchar('%');
		else
			i = i + printchar(*format);
		format++;
	}
	va_end(args);
	return (i);
}
