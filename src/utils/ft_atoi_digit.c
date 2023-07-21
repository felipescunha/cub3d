/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_digit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:31:40 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/20 21:04:19 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

long	ft_atoi_digit(const char *str)
{
	long	i;
	long	number;

	number = 0;
	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (-1);
	}
	i = 0;
	while (str[i])
	{
		number = number * 10 + (str[i++] - '0');
	}
	return (number);
}
