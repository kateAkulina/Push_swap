/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 19:53:22 by lcutjack          #+#    #+#             */
/*   Updated: 2019/02/16 16:15:13 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		size;
	char	*f;
	va_list	ap;

	size = 0;
	f = (char*)format;
	va_start(ap, format);
	while (*f)
	{
		if (*f == '%' && ++f)
			size += what_type(&f, &ap);
		else if (++size)
			ft_putchar((char)*(f++));
	}
	va_end(ap);
	format = f;
	return ((int)size);
}
