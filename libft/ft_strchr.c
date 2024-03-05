/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:29:20 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/02/24 18:18:00 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	int		i;

	i = 0;
	ch = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			return ((char *) &s[i]);
		i++;
	}
	if (ch == '\0')
		return ((char *) &s[i]);
	return (NULL);
}
