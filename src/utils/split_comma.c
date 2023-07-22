/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_comma.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:07:46 by marolive          #+#    #+#             */
/*   Updated: 2023/07/22 13:38:55 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*my_realloc(char *str, size_t new_size)
{
	size_t	old_size;
	char	*new_str;

	old_size = ft_strlen(str) + 1;
	if (new_size == 0)
	{
		free(str);
		return (NULL);
	}
	new_str = ft_calloc(sizeof(char), new_size + 1);
	if (!new_str)
		return (NULL);
	if (str)
	{
		if (old_size < new_size)
			ft_memcpy(new_str, str, old_size);
	}
	free(str);
	return (new_str);
}

static int	count_word(char const *s)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && (s[i] == 32 || s[i] == 44))
			i++;
		j = i;
		while (s[i] != '\0' && (s[i] != 32 && s[i] != 44))
			i++;
		if (j != i)
			k++;
	}
	return (k);
}

static void	*clear_word(char **temp_s)
{
	int	i;

	i = 0;
	while (temp_s[i] != NULL)
	{
		free(temp_s[i]);
		i++;
	}
	free(temp_s);
	return (temp_s = NULL);
}

char	**ft_split_comma(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	**temp_s;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	temp_s = ft_calloc(count_word(s) + 1, sizeof(char *));
	if (!temp_s)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && (s[i] == 32 || s[i] == 44))
			i++;
		j = i;
		while (s[i] != '\0' && (s[i] != 32 && s[i] != 44))
			i++;
		if (j != i)
			temp_s[k++] = ft_substr(s, j, i - j);
		if (temp_s[k - 1] == NULL && count_word(s) > 0)
			return (clear_word(temp_s));
	}
	return (temp_s);
}

void	check_comma(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		print_error("Need only two comma\n");
}

char	*ft_split_texture(char **texture)
{
	if (ft_array_size(texture) != 2)
		print_error("In texture array\n");
	return (texture[1]);
}