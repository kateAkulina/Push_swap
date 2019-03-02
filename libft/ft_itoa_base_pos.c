/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:01:53 by lcutjack          #+#    #+#             */
/*   Updated: 2019/02/11 18:01:23 by lcutjack         ###   ########.fr       */
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

char		*ft_itoa_base_pos(unsigned long long n, int base)
{
	char				f[17];
	char				new[67];
	char				*p;

	zap_mas(f);
	p = &new[66];
	*p = '\0';
	if (!n && --p)
		new[65] = '0';
	while (n > 0)
	{
		*(--p) = f[n % base];
		n /= base;
	}
	return (ft_strdup(p));
}
