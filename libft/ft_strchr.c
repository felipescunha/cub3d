/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:43:02 by fecunha           #+#    #+#             */
/*   Updated: 2022/06/13 14:48:00 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*temp_s;

	temp_s = (char *) s;
	i = 0;
	while (s[i] != (unsigned char) c && s[i] != '\0')
		i++;
	if (s[i] == (unsigned char) c)
		return (&temp_s[i]);
	return (0);
}
