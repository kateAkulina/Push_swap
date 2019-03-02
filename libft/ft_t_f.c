/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 20:06:40 by lcutjack          #+#    #+#             */
/*   Updated: 2019/02/16 18:16:22 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*prec_double(int len, long double ch)
{
	int		i;
	char	*buf;

	i = -1;
	ch = ch - (int)ch;
	buf = ft_strnew(len + 1);
	while (++i < len)
	{
		buf[i] = (int)ch + 48;
		ch = ch * 10 - ((int)ch) * 10;
	}
	buf[0] = '.';
	buf[i] = (int)(ch + 0.5) + 48;
	return (buf);
}

void			tp_f(t_info *d, va_list *ap)
{
	long double	n;
	int			sign;
	char		*whole;

	(*d).prec = (*d).prec == -1 ? 6 : (*d).prec;
	if ((*d).len == 3 || (*d).len == 6)
		n = va_arg(*ap, long double);
	else
		n = va_arg(*ap, double);
	sign = n >= 0 ? 0 : -1;
	n = n < 0 ? -n : n;
	whole = ft_itoa_base_pos((unsigned long long)n, 10);
	(*d).buf = ft_rejoin(whole, prec_double((*d).prec, n));
	if ((*d).flag[0] || (*d).flag[2] || sign)
	{
		if ((*d).flag[4] && --(*d).width)
			set_width(d);
		set_sign(d, sign);
	}
	set_width(d);
}
