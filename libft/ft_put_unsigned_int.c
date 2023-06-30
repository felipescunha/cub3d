/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:22:51 by fecunha           #+#    #+#             */
/*   Updated: 2022/10/20 16:34:35 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_unsigned_int(unsigned int u)
{
	int	count;

	count = 0;
	if (u >= 10)
	{
	count += ft_put_unsigned_int(u / 10);
	count += ft_put_unsigned_int(u % 10);
	}
	if (u < 10)
	{
		ft_put_char(u + 48);
		count++;
	}
	return (count);
}
