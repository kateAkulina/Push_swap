/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:10:00 by lcutjack          #+#    #+#             */
/*   Updated: 2018/11/30 21:02:38 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	n_size(int n)
{
	int		i;
	size_t	size;

	i = n;
	size = 0;
	if (!i)
		size = 1;
	while (i)
	{
		size += 1;
		i /= 10;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	char			*new;
	unsigned int	ch;
	size_t			size;

	size = n_size(n);
	if (n < 0)
	{
		ch = (unsigned int)(0 - n);
		size += sizeof(char);
	}
	else
		ch = (unsigned int)n;
	if (!(new = ft_strnew(size)))
		return (NULL);
	*new = '-';
	if (!ch)
		*new = '0';
	while (ch)
	{
		new[--size] = '0' + ch % 10;
		ch = ch / 10;
	}
	return (new);
}
