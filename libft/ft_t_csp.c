/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_csp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:59:30 by lcutjack          #+#    #+#             */
/*   Updated: 2019/02/16 17:47:51 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	tp_c(t_info *d, va_list *ap)
{
	char	c;
	int		len;
	char	*str;

	c = '%';
	if ((*d).spec == 'c')
		c = (char)va_arg(*ap, int);
	len = (*d).width > 0 ? (*d).width - 1 : 0;
	str = ft_strnew(len);
	ft_memset(str, 32, len);
	(*d).size = len + 1;
	if ((*d).flag[3])
	{
		ft_putchar(c);
		ft_putstr(str);
	}
	else
	{
		ft_putstr(str);
		ft_putchar(c);
	}
	free(str);
	(*d).buf = ft_strnew(0);
}

void	tp_s(t_info *d, va_list *ap)
{
	char	*s;
	int		len;

	s = va_arg(*ap, char*);
	if (!s)
	{
		s = ft_strnew(6);
		ft_strcpy(s, "(null)");
	}
	else
		s = ft_strdup(s);
	len = ft_strlen(s);
	len = ((*d).prec < len && (*d).prec >= 0) ? (*d).prec : len;
	(*d).buf = ft_strnew(len);
	ft_strncpy((*d).buf, s, len);
	free(s);
	set_width(d);
}

void	tp_p(t_info *d, va_list *ap)
{
	unsigned long	p;
	char			*fr;

	p = (unsigned long)va_arg(*ap, void *);
	(*d).buf = ft_itoa_base(p, 16);
	if (!p)
	{
		(*d).buf = ft_strnew(1);
		(*d).buf[0] = '0';
	}
	set_prec(d);
	fr = (*d).buf;
	(*d).buf = ft_strjoin("0x", (*d).buf);
	free(fr);
	set_width(d);
}
