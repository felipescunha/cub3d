/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:33:54 by fecunha           #+#    #+#             */
/*   Updated: 2022/06/17 15:16:23 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	if (!s1)
		return (NULL);
	j = ft_strlen(s1) + 1;
	count = j;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (count > i && ft_strrchr(set, s1[count - 1]))
		count--;
	return (ft_substr(s1, i, count - i));
}
