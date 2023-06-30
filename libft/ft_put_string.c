/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:59:22 by fecunha           #+#    #+#             */
/*   Updated: 2022/10/20 16:33:30 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

int	ft_put_string(char *s)
{
	int	index;

	index = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[index])
	{
		index++;
	}		
	return (write(1, s, index));
}
