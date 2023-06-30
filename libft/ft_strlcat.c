/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:35:20 by fecunha           #+#    #+#             */
/*   Updated: 2022/06/16 18:59:59 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	j;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	j = 0;
	if (dstsize == 0)
		return (len_src);
	if (dstsize < len_dst)
		return (len_src + dstsize);
	while (src[j] && len_dst + j < dstsize - 1)
	{
		dst[len_dst + j] = src[j];
		j++;
	}
	if (len_dst < dstsize)
		dst[len_dst + j] = '\0';
	return (len_src + len_dst);
}
