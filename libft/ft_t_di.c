/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:30:07 by lcutjack          #+#    #+#             */
/*   Updated: 2019/02/16 18:12:42 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		set_sign(t_info *d, int sign)
{
	char	start[2];
	char	*tmp;

	if (sign)
	{
		tmp = (*d).buf;
		(*d).buf = ft_strjoin("-", (*d).buf);
		free(tmp);
	}
	else if ((*d).flag[0] || (*d).flag[2])
	{
		start[1] = '\0';
		start[0] = (*d).flag[2] ? '+' : ' ';
		tmp = (*d).buf;
		(*d).buf = ft_strjoin(start, tmp);
		free(tmp);
	}
}

static void	make_buf_i(t_info *d, long long int ch)
{
	int				sign;

	sign = 0;
	if (ch < 0 && (sign = -1))
		ch = -ch;
	(*d).buf = ft_itoa_base_pos(ch, 10);
	set_prec(d);
	if ((*d).flag[0] || (*d).flag[2] || sign)
	{
		if ((*d).flag[4] && --(*d).width)
			set_width(d);
		set_sign(d, sign);
	}
	set_width(d);
}

void		tp_i(t_info *d, va_list *ap)
{
	long long int	ch;

	if ((*d).len == 5)
		ch = va_arg(*ap, long int);
	else if ((*d).len == 6)
		ch = va_arg(*ap, long long int);
	else if ((*d).len == 1)
		ch = (short)va_arg(*ap, int);
	else if ((*d).len == 2)
		ch = (char)va_arg(*ap, int);
	else
		ch = va_arg(*ap, int);
	make_buf_i(d, ch);
}
