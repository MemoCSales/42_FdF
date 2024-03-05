/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:09:52 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/02/21 11:00:32 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	printstring(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (s[i])
		i++;
	ft_putstr_fd(s, 1);
	return (i);
}

int	printhexa(unsigned long long n, const char *format)
{
	unsigned long long		num;
	char					*hexabase;
	int						i;

	num = n;
	i = 0;
	hexabase = NULL;
	if (*format == 'x' || *format == 'p')
		hexabase = LOWERHEXABASE;
	else if (*format == 'X')
		hexabase = UPPERHEXABASE;
	if (num >= 16)
		i += printhexa(num / 16, format);
	printchar(hexabase[num % 16]);
	return (i + 1);
}

int	intlen(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*itoa(unsigned int n)
{
	char	*num;
	int		len;

	len = intlen(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}
