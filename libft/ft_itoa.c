/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:44:39 by fecunha           #+#    #+#             */
/*   Updated: 2022/06/16 23:31:43 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count(int n)
{
	int			count;
	long int	aux;

	aux = n;
	count = 0;
	if (aux < 0)
	{
		count = count + 1;
		aux *= -1;
	}
	while (aux > 9)
	{
		aux = aux / 10;
		count++;
	}
	count++;
	return (count);
}

char	*ft_itoa(int n)
{
	long int	aux;
	char		*p_ascii;
	int			count;

	count = ft_count(n);
	aux = n;
	p_ascii = malloc((count + 1) * sizeof(char));
	if (!p_ascii)
		return (NULL);
	if (aux < 0)
		aux *= -1;
	p_ascii[count] = '\0';
	while (count != 0)
	{
		p_ascii[count - 1] = (aux % 10) + 48;
		aux = (aux / 10);
		count--;
	}
	if (n < 0)
		p_ascii[0] = '-';
	return (p_ascii);
}
