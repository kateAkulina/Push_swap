/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_oux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 17:13:00 by lcutjack          #+#    #+#             */
/*   Updated: 2019/02/16 18:45:57 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		set_width_u(t_info *d)
{
	char	*new;
	int		minlen;
	char	c;
	int		len;

	len = ft_strlen((*d).buf);
	c = (*d).flag[3] || !(*d).flag[4] ? 32 : 48;
	minlen = (*d).width;
	if (minlen > len)
	{
		new = ft_strnew(minlen);
		ft_memset(new, c, minlen);
		if ((*d).flag[3] == 1)
			new = ft_strncpy(new, (*d).buf, len);
		else
			ft_strcpy(&new[minlen - len], (*d).buf);
		free((*d).buf);
		(*d).buf = new;
	}
}

static void		set_sharp(t_info *d)
{
	char	*tmp;
	char	sym[3];

	if (!(*d).flag[1])
		return ;
	ft_strcpy(sym, "0x");
	if ((*d).spec == 'o')
		sym[1] = 0;
	tmp = ft_strjoin(sym, (*d).buf);
	free((*d).buf);
	(*d).buf = tmp;
}

static void		make_buf_u(t_info *d, unsigned long long ch)
{
	int					base;

	if ((*d).spec == 'o')
		base = 8;
	else if ((*d).spec == 'x' || (*d).spec == 'X')
		base = 16;
	else
		base = (*d).spec == 'u' ? 10 : (2 - ((*d).spec == 'o')) * 8;
	(*d).buf = ft_itoa_base_pos(ch, base);
	if ((*d).spec == 'X' && ((*d).spec = 'x'))
		ft_str_tup((*d).buf);
	set_prec(d);
	if ((*d).buf[0] == '0' && base == 8)
		(*d).flag[1] = 0;
	if (ch && (*d).flag[1])
	{
		if ((*d).prec < 0 && (*d).flag[4] && \
			((*d).width = (*d).width - base / 8))
			set_width_u(d);
		set_sharp(d);
	}
	set_width_u(d);
}

void			tp_oux(t_info *d, va_list *ap)
{
	unsigned long long	ch;

	if ((*d).len == 6)
		ch = va_arg(*ap, unsigned long long int);
	else if ((*d).len == 5)
		ch = va_arg(*ap, unsigned long int);
	else if ((*d).len == 1)
		ch = (unsigned short)va_arg(*ap, unsigned int);
	else if ((*d).len == 2)
		ch = (unsigned char)va_arg(*ap, unsigned int);
	else
		ch = va_arg(*ap, unsigned int);
	make_buf_u(d, ch);
}
