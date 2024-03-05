/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:02:44 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/02/22 10:58:30 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr2(char *s, int c)
{
	char	ch;
	int		i;

	i = 0;
	ch = (char) c;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == ch)
		return ((char *) &s[i]);
	return (NULL);
}


char	*ft_strjoin2(char *s1, char *s2)
{
	char	*news;
	ssize_t	i;
	ssize_t	j;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (0);
	news = malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
	if (!(news))
		return (0);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			news[i] = s1[i];
	while (s2[j] != '\0')
		news[i++] = s2[j++];
	news[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free((void *)(s1));
	return (news);
}

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t	slen;
// 	size_t	i;
// 	char	*subs;

// 	i = 0;
// 	slen = ft_strlen(s);
// 	if (start >= slen)
// 		len = 0;
// 	if (len > start + slen)
// 		len = start + slen;
// 	subs = (char *) malloc((len + 1) * sizeof(char));
// 	if (!(subs))
// 		return (0);
// 	while (i < len && s[start + i] != '\0')
// 	{
// 		subs[i] = s[start + i];
// 		i++;
// 	}
// 	subs[i] = '\0';
// 	return (subs);
// }
