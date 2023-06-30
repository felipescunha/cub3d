/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:31:56 by fecunha           #+#    #+#             */
/*   Updated: 2022/06/14 19:18:01 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp_s;
	int		len;

	temp_s = (char *) s;
	len = ft_strlen(temp_s);
	while (temp_s[len] != (char) c && len > 0)
	{
		len--;
	}
	if (temp_s[len] == (char) c)
		return (&temp_s[len]);
	return (0);
}