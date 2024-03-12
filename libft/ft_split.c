/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:18:48 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/12 13:12:20 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(const char *str, char chr)
{
	size_t	word;
	size_t	i;

	if (!str)
		return (0);
	word = 0;
	i = 0;
	while (str[i])
	{
		if ((i == 0 || str[i -1] == chr) && str[i] != chr)
			word++;
		i++;
	}
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	res = (char **) malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!res || !s)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i > start)
		{
			res[j] = ft_substr(s, start, i - start);
			j++;
		}
	}
	// clean_upsubstr(res, i, j);
	res[j] = NULL;
	return (res);
}


void	clean_upsubstr(char **res, int i, int j)
{
	// printf("j: %d\n", j);
	while (i < j)
	{
		free(res[i]);
		i++;
	}
	free(res);
	
}
