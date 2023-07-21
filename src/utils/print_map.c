/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:25:28 by learn             #+#    #+#             */
/*   Updated: 2023/07/20 21:07:09 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_map(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (cub3d->full_map[i])
		printf("%s\n", cub3d->full_map[i++]);
}
