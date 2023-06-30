/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 20:07:38 by fecunha           #+#    #+#             */
/*   Updated: 2023/04/15 20:50:26 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	validation_char(t_cub3d *cub3d)
{
	int	i;
	int	j;

	j = 0;
	while (j < cub3d->lines)
	{
		i = 0;
		while (cub3d->map[j][i] != '\0')
		{
			if (!ft_strchr("01NSEW \n", cub3d->map[j][i]))
				print_error("Invalid character in map\n");
			i++;
		}
		j++;
	}
	return (1);
}

