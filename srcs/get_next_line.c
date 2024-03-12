/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:02:37 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/12 18:36:14 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buffer;
	char		*line;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd == 1 || fd == 2)
	{
		free(backup);
		free(buffer);
		backup = NULL;
		buffer = NULL;
		return (NULL);
	}
	line = read_from_file(fd, backup, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	backup = read_line(line);
	return (line);
}

char	*read_from_file(int fd, char *backup, char *buffer)
{
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(backup), NULL);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!backup)
			backup = ft_calloc(1, sizeof(char));
		temp = backup;
		backup = ft_strjoin2(temp, buffer);
		temp = NULL;
		if (ft_strchr2(buffer, '\n'))
			break ;
	}
	return (backup);
}

char	*read_line(char *full_line)
{
	int		i;
	char	*line;

	i = 0;
	if (!full_line)
		return (free(full_line), NULL);
	while (full_line[i] != '\n' && full_line[i])
		i++;
	if (full_line[i] == 0 || full_line[1] == 0)
		return (NULL);
	line = ft_substr(full_line, i + 1, ft_strlen(full_line) - i);
	if (*line == 0)
		return (free(line), NULL);
	full_line[i + 1] = '\0';
	return (line);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	tmp = malloc(count * size);
	i = 0;
	if (!(tmp))
		return (NULL);
	while (i < size * count)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}
