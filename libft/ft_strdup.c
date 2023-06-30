/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:04:32 by fecunha           #+#    #+#             */
/*   Updated: 2022/06/16 22:06:30 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*temp_s1;

	i = 0;
	temp_s1 = (char *) malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (!temp_s1)
		return (NULL);
	while (s1[i])
	{
		temp_s1[i] = s1[i];
		i++;
	}
	temp_s1[i] = '\0';
	return (temp_s1);
}
