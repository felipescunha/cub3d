/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learn <learn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:25:35 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/01 00:38:23 by learn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static char	*remove_new_line(char *str)
{
	int	i;
	int	len;

	if (!str)
		return (NULL);
	i = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		if (str[i] && str[i] == '\n' && len > 1)
		{
			str[i] = '\0';
			break ;
		}
		i++;
	}
	return (str);
}

void	copy_file(t_cub3d *cub3d, char *argv)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	cub3d->lines = 0;
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	cub3d->file = ft_calloc(cub3d->read_lines + 1, sizeof (char *));
	cub3d->file[i++] = remove_new_line(line);
	//free(line);
	while (cub3d->read_lines > i)
	{
		line = get_next_line(fd);
		if(!line)
			break;
		cub3d->file[i++] = remove_new_line(line);
		//free(line);
	}
	close(fd);
}