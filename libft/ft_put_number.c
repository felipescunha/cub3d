/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:22:51 by fecunha           #+#    #+#             */
/*   Updated: 2023/07/21 22:41:50 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_number(int n)
{
	int			count;
	long int	nbr;

	count = 0;
	nbr = n;
	if (n < 0)
	{
		nbr = -nbr;
		count += ft_put_char('-');
	}
	if (nbr >= 10)
	{
		count += ft_put_number(nbr / 10);
		count += ft_put_number(nbr % 10);
	}
	if (nbr < 10)
	{
		ft_put_char(nbr + 48);
		count++;
	}
	return (count);
}
