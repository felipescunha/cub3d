/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:53:35 by fecunha           #+#    #+#             */
/*   Updated: 2022/06/13 21:34:18 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;

	i = 0;
	temp_s1 = (unsigned char *) s1;
	temp_s2 = (unsigned char *) s2;
	while (n > i)
	{	
		if (temp_s1[i] != temp_s2[i])
			return ((temp_s1[i]) - (temp_s2[i]));
		i++;
	}
	return (0);
}
