/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learn <learn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:01:47 by learn             #+#    #+#             */
/*   Updated: 2023/06/30 17:05:11 by learn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void ft_free_array(char **array)
{
    int i;

    i = 0;
	if(!array)
		return ;
    while (array[i])
        free(array[i++]);
    free(array);
}