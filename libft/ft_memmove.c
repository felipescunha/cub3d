/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:50:16 by fecunha           #+#    #+#             */
/*   Updated: 2022/06/16 19:21:06 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*temp_src;
	char	*temp_dst;

	i = 0;
	temp_src = (char *)src;
	temp_dst = (char *)dst;
	if (!src && !dst)
		return (NULL);
	if (temp_dst > temp_src)
	{
		while (len--)
			temp_dst[len] = temp_src[len];
	}
	else
	{
		while (i < len)
		{
			temp_dst[i] = temp_src[i];
			i++;
		}	
	}
	return (temp_dst);
}
