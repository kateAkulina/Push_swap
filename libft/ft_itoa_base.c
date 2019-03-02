/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:04:59 by lcutjack          #+#    #+#             */
/*   Updated: 2019/02/10 16:39:49 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	zap_mas(char *f)
{
	int i;

	i = -1;
	while (++i < 10)
		f[i] = i + 48;
	while (i < 17)
	{
		f[i] = 87 + i;
		++i;
	}
}

char		*ft_itoa_base(long long n, int base)
{
	char				f[17];
	char				new[66];
	char				*p;
	int					sign;
	unsigned long long	k;

	zap_mas(f);
	p = &new[65];
	*p = '\0';
	sign = (n < 0);
	k = (n < 0) ? (unsigned long long)0 - n : n;
	while (k > 0)
	{
		*(--p) = f[k % base];
		k /= base;
	}
	if (sign)
		*(--p) = '-';
	return (ft_strdup(p));
}
