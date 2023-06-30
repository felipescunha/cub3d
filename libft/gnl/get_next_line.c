/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 00:08:43 by fecunha           #+#    #+#             */
/*   Updated: 2022/10/20 16:25:52 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*ft_strip_sausage(char *save)
{
	unsigned int	index;	
	char			*ret;

	index = 0;
	if (save[index] == '\0')
	{	
		free(save);
		return (NULL);
	}
	while (save[index] != '\n' && save[index])
		index++;
	if (save[index] == '\n')
		index++;
	ret = ft_substr(save, index, (unsigned int)gnl_ft_strlen(save) - index);
	free(save);
	return (ret);
}

static	char	*ft_read_line(char *save)
{
	int		index;	
	char	*line;

	index = 0;
	if (save[index] == '\0')
		return (NULL);
	while (save[index] != '\n' && save[index])
		index++;
	if (save[index] == '\n')
		index++;
	line = ft_substr(save, 0, index);
	return (line);
}

static char	*get_buffer(int fd, char *save, char *buffer)
{
	int		size;

	size = 1;
	while (size > 0 && !ft_strchr(save, '\n'))
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size < 0)
		{
			free(save);
			free(buffer);
			return (NULL);
		}
		buffer[size] = '\0';
		save = gnl_ft_strjoin(save, buffer);
	}
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;
	char		*buffer;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!save)
		save = ft_strdup("\0");
	save = get_buffer(fd, save, buffer);
	line = ft_read_line(save);
	save = ft_strip_sausage(save);
	free(buffer);
	return (line);
}
