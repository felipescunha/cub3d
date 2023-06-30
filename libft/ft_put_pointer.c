/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:22:51 by fecunha           #+#    #+#             */
/*   Updated: 2022/10/20 16:33:47 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_pointer(unsigned long p)
{
	size_t	count;

	count = 0;
	count += ft_put_char('0');
	count += ft_put_char('x');
	count += ft_put_hexa(p, 'x');
	return (count);
}
