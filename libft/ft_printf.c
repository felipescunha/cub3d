/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:40:44 by fecunha           #+#    #+#             */
/*   Updated: 2022/10/20 16:32:34 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	verify_print_type(char c, va_list my_list)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_put_char(va_arg(my_list, int));
	if (c == 's')
		count = ft_put_string(va_arg(my_list, char *));
	if (c == 'p')
		count = ft_put_pointer(va_arg(my_list, unsigned long));
	if (c == 'i' || c == 'd')
		count = ft_put_number(va_arg(my_list, int));
	if (c == 'u')
		count = ft_put_unsigned_int(va_arg(my_list, unsigned int));
	if (c == 'x' || c == 'X')
		count = ft_put_hexa((unsigned long)va_arg(my_list, unsigned int), c);
	if (c == '%')
		count = ft_put_char('%');
	return (count);
}

int	ft_printf(const char *string, ...)
{
	int		index;
	int		response;
	va_list	my_list;

	index = 0;
	response = 0;
	va_start(my_list, string);
	while (string[index])
	{
		if (string[index] == '%')
		{
			response += verify_print_type(string[++index], my_list);
		}
		else
			response += ft_put_char(string[index]);
		index++;
	}
	va_end(my_list);
	return (response);
}
