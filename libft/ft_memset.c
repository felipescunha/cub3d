/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:16:03 by fecunha           #+#    #+#             */
/*   Updated: 2022/06/13 20:41:45 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*b_temp;

	i = 0;
	b_temp = (char *) b;
	while (len--)
	{
		b_temp[i] = c;
		i++;
	}
	return (b_temp);
}
