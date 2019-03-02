/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:58:30 by lcutjack          #+#    #+#             */
/*   Updated: 2019/03/01 18:24:40 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_flag(char **f, char *flag)
{
	char	p;

	ft_bzero(flag, 5);
	while (ft_strchr(" #+-0", **f))
	{
		p = **f;
		flag[p / 35 + p / 43 + p / 45 + p / 48] = 1;
		++(*f);
	}
	if (flag[3])
		flag[4] = 0;
}

void	fill_wp(char **f, t_info *d, va_list *ap)
{
	char	*p;

	p = *f;
	if (*p == '*' && (++p))
		(*d).width = va_arg(*ap, int);
	else
		(*d).width = ft_atoi(p);
	while (ft_isdigit(*p))
		++p;
	if (*p == '.' && ++p)
	{
		if (*p == '*' && (++p))
			(*d).prec = va_arg(*ap, int);
		else
			(*d).prec = ft_atoi(p);
		while (ft_isdigit(*p))
			++p;
	}
	else
		(*d).prec = -1;
	*f = p;
}

void	fill_ls(char **f, t_info *d)
{
	if ((**f == 'l' || **f == 'h'))
	{
		(*d).len = **f - 103;
		++(*f);
		if (**f == *((*f) - 1) && ++(*f))
			(*d).len = (*d).len + 1;
	}
	else if (**f == 'L' && ++(*f))
		(*d).len = 3;
	else
		(*d).len = 0;
	if (ft_strchr("cspdiouxXf%", **f))
	{
		(*d).spec = **f;
		++(*f);
	}
	else if (ft_strchr("OU", **f))
	{
		(*d).len = 5;
		(*d).spec = ft_tolower(**f);
		++(*f);
	}
	else
		(*d).spec = 0;
}

t_info	*fill_info(char **f, va_list *ap)
{
	t_info	*data;

	data = (t_info*)malloc(sizeof(t_info));
	fill_flag(f, (*data).flag);
	fill_wp(f, data, ap);
	fill_ls(f, data);
	(*data).size = 0;
	return (data);
}

int		what_type(char **format, va_list *ap)
{
	t_info	*data;
	int		len;

	data = fill_info(format, ap);
	if (ft_strchr("c%", (*data).spec))
		tp_c(data, ap);
	else if ((*data).spec == 's')
		tp_s(data, ap);
	else if ((*data).spec == 'p')
		tp_p(data, ap);
	else if (ft_strchr("id", (*data).spec))
		tp_i(data, ap);
	else if ('f' == (*data).spec)
		tp_f(data, ap);
	else if (ft_strchr("ouxX", (*data).spec))
		tp_oux(data, ap);
	ft_putstr((*data).buf);
	len = ft_strlen((*data).buf) + (*data).size;
	free((*data).buf);
	free(data);
	return (len);
}
