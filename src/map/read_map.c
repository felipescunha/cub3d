/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:21:09 by fecunha           #+#    #+#             */
/*   Updated: 2023/04/15 20:49:20 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	read_map(t_cub3d *cub3d, char *argv)
{
	int		fd;
	char	*line;
	int		total_lines;

	fd = open(argv, O_RDONLY);
	total_lines = 0;
	if (fd < 0)
		print_error("Map not found!\n");
	line = get_next_line(fd);
	if (!line)
		print_error("Empty map!\n");
	total_lines = 1;
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		if(!line)
			break;
		total_lines++;
		if (line)
			free(line);
	}
	cub3d->read_lines = total_lines;
	close(fd);
}