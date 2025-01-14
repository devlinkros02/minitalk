/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:14:48 by dkros             #+#    #+#             */
/*   Updated: 2024/02/27 14:41:30 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*read_file(int fd, char *remainder)
{
	char	*buffer;
	int		bytesread;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free_func(&remainder));
	bytesread = 1;
	while (bytesread > 0 && check_nl(remainder) == 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread > 0)
		{
			buffer[bytesread] = '\0';
			remainder = ft_strjoinn(remainder, buffer);
			if (!remainder)
				return (free_func(&buffer));
		}
	}
	free_func(&buffer);
	if (bytesread < 0)
		return (free_func(&remainder));
	return (remainder);
}

char	*get_the_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = buffer[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*get_remainder(char *buffer, char **line)
{
	int		i;
	int		j;
	char	*remainder;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	if (buffer[i] == '\0')
		return (free_func(&buffer));
	remainder = malloc(ft_strlenn(buffer + i) + 1);
	if (!remainder)
	{
		free_func(&buffer);
		return (free_func(line));
	}
	while (buffer[i])
		remainder[j++] = buffer[i++];
	remainder[j] = '\0';
	free_func(&buffer);
	return (remainder);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remainder = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = read_file(fd, remainder);
	if (!remainder)
		return (NULL);
	line = get_the_line(remainder);
	if (!line)
		return (free_func(&remainder));
	remainder = get_remainder(remainder, &line);
	return (line);
}
