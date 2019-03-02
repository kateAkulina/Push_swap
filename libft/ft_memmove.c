/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:00:21 by lcutjack          #+#    #+#             */
/*   Updated: 2018/12/21 14:38:26 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*new;
	unsigned char	*frm;

	if (dst == src)
		return (dst);
	new = (unsigned char*)dst;
	frm = (unsigned char*)src;
	if (frm > new)
	{
		while (len-- > 0)
			*(new++) = *(frm++);
	}
	else
	{
		while (len-- > 0)
			*(new + len) = *(frm + len);
	}
	return (dst);
}
