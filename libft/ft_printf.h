/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fecunha <fecunha@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:34:31 by fecunha           #+#    #+#             */
/*   Updated: 2022/08/10 18:57:44 by fecunha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *string, ...);
int	ft_put_char(char c);
int	ft_put_string(char *s);
int	ft_put_pointer(unsigned long p);
int	ft_put_number(int n);
int	ft_put_unsigned_int(unsigned int u);
int	ft_put_hexa(unsigned long x, char type_char);

#endif
