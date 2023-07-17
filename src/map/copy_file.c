/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:25:35 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/17 17:24:59 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"



static char	*remove_new_line(char *line)
{
	int	i;
	int	len;

	if (!line)
		return (NULL);
	i = 0;
	len = ft_strlen(line);

	while (line[i])
	{
		if (line[i] && line[i] == '\n' && len > 1)
		{
			line[i] = '\0';
			break ;
		}
		i++;
	}
	return (line);
}

void	copy_file(t_cub3d *cub3d, char *argv)
{
	int		fd;
	char	*line;
	int		i;

 	i = 0;
	fd = open(argv, O_RDONLY);
	if(fd == -1)
		return ;
	line = get_next_line(fd);
	if(!line)
		return ;
	cub3d->file = ft_calloc(cub3d->read_lines + 1, sizeof (char *));
	cub3d->file[i++] = remove_new_line(line);
	
	while (cub3d->read_lines >= i)
	{
		line = get_next_line(fd);
		if(!line)
			break;
		cub3d->file[i++] = remove_new_line(line);
	}
	close(fd);
}