/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:31:40 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/10 16:30:52 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

size_t ft_array_size(char **array)
{
	size_t i;
	
	i = 0;
	if(!array)
		return (0);
	while (array[i])
		i++;
	return (i);
}