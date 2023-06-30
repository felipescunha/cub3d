/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:26:05 by fecunha           #+#    #+#             */
/*   Updated: 2022/06/13 21:28:36 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp_s;
	size_t			i;

	temp_s = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (temp_s[i] == (unsigned char) c)
			return (&temp_s[i]);
		i++;
	}
	return (0);
}
