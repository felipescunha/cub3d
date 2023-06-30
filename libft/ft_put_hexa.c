/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:22:51 by fecunha           #+#    #+#             */
/*   Updated: 2022/10/20 16:34:58 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_hexa(unsigned long x, char type_char)
{
	int		count;
	char	*base;

	if (type_char == 'x')
		base = "0123456789abcdef";
	if (type_char == 'X')
		base = "0123456789ABCDEF";
	count = 0;
	if (x >= 16)
	{
		count += ft_put_hexa(x / 16, type_char);
		count += ft_put_hexa(x % 16, type_char);
	}
	if (x < 16)
	{
		ft_put_char(base[x]);
		count++;
	}
	return (count);
}
