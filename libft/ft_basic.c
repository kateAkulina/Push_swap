/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 23:28:45 by lcutjack          #+#    #+#             */
/*   Updated: 2019/02/16 18:44:45 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_prec(t_info *d)
{
	char	*new;
	int		len;
	int		blen;
	char	*tmp;

	if (ft_strlen((*d).buf) == 1 && (*d).buf[0] == '0' && !(*d).prec && \
		ft_strchr("oOuUxXdi", (*d).spec) && \
		(((*d).flag[1] && (*d).spec == 'x') || !(*d).flag[1]))
	{
		tmp = (*d).buf;
		(*d).buf = ft_strnew(1);
		free(tmp);
		return ;
	}
	if ((*d).prec < 0)
		return ;
	len = ft_strlen((*d).buf);
	(*d).flag[4] = 0;
	blen = ((*d).prec >= len) ? (*d).prec : len;
	new = ft_strnew(blen);
	new = ft_memset(new, 48, blen - 1);
	ft_strncpy(new + blen - len, (*d).buf, blen);
	tmp = (*d).buf;
	(*d).buf = new;
	free(tmp);
}

void	set_width(t_info *d)
{
	char	*new;
	int		minlen;
	char	c;
	int		len;
	char	*tmp;

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
		tmp = (*d).buf;
		(*d).buf = new;
		free(tmp);
	}
}
