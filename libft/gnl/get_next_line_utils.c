/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 00:06:22 by fecunha           #+#    #+#             */
/*   Updated: 2022/09/15 21:37:34 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_ft_strlen(char *string)
{
	int	count;

	if (!string)
		return (0);
	count = 0;
	while (string[count])
		count++;
	return (count);
}

char	*ft_strchr(const char *string, int character)
{
	int		index;
	char	*temp_string;

	if (!string)
		return (NULL);
	temp_string = (char *) string;
	index = 0;
	while (string[index] && string[index] != character)
		index++;
	if (string[index] == character)
		return (&temp_string[index]);
	return (0);
}

char	*gnl_ft_strjoin(char *s1, char *s2)
{
	char	*new_string;
	int		index_s1;
	int		index_s2;

	if (!s1)
		return (NULL);
	new_string = (char *) malloc(gnl_ft_strlen(s1) + gnl_ft_strlen(s2) + 1);
	if (!new_string)
		return (NULL);
	index_s1 = 0;
	while (s1[index_s1])
	{
		new_string[index_s1] = s1[index_s1];
		index_s1++;
	}
	index_s2 = 0;
	while (s2[index_s2])
	{
		new_string[index_s1] = s2[index_s2];
		index_s1++;
		index_s2++;
	}
	new_string[index_s1] = '\0';
	free(s1);
	return (new_string);
}

char	*ft_strdup(const char *s1)
{
	int		index;
	char	*temp_s1;	

	index = 0;
	if (!s1)
		return (NULL);
	temp_s1 = (char *) malloc(gnl_ft_strlen((char *) s1) + 1);
	if (!temp_s1)
		return (NULL);
	while (s1[index])
	{
		temp_s1[index] = s1[index];
		index++;
	}
	temp_s1[index] = '\0';
	return (temp_s1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*substr;

	if ((int) start >= gnl_ft_strlen((char *) s))
		return (ft_strdup(""));
	if (s == NULL)
		return (0);
	i = 0;
	j = 0;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	while (i != start)
		i++;
	while (len--)
		substr[j++] = s[i++];
	substr[j] = '\0';
	return (substr);
}	
