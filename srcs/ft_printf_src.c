/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdecimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:21:45 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/02/21 11:01:07 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	else if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	num;

	num = n;
	len = ft_intlen(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num == 0)
		return (str[0] = '0', str);
	str[len - 1] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num)
	{
		str[--len] = (num % 10) + 48;
		num = num / 10;
	}
	return (str);
}

int	printdecimal(int n)
{
	char	*num;
	int		i;

	i = 0;
	num = ft_itoa(n);
	i += printstring(num);
	free(num);
	return (i);
}

int	printunsigned(unsigned int n)
{
	char	*num;
	int		i;

	i = 0;
	if (n == 0)
		i += write(1, "0", 1);
	else
	{
		num = itoa(n);
		i += printstring(num);
		free(num);
	}
	return (i);
}
