/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:55:32 by fecunha           #+#    #+#             */
/*   Updated: 2022/06/16 23:09:01 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	int	index;
	int	start_word;
	int	count;

	index = 0;
	count = 0;
	while (s[index])
	{
		while (s[index] == c && s[index])
			index++;
		start_word = index;
		while (s[index] != c && s[index])
			index++;
		if (start_word != index)
			count++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		word;
	int		index;
	int		start_word;

	if (!s)
		return (NULL);
	word = 0;
	index = 0;
	arr = ft_calloc(ft_count_word(s, c) + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	while (s[index])
	{
		while (s[index] == c && s[index])
			index++;
		start_word = index;
		while (s[index] != c && s[index])
			index++;
		if (start_word != index)
			arr[word++] = ft_substr(s, start_word, index - start_word);
	}
	arr[word] = NULL;
	return (arr);
}
