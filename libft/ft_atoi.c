/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:39:01 by lcutjack          #+#    #+#             */
/*   Updated: 2019/01/29 16:51:16 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	size_t		i;
	long long	new;
	int			sign;

	i = 0;
	new = 0;
	sign = 1;
	while ((s[i] >= 8 && s[i] <= 14) || s[i] == 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		sign = 44 - s[i];
		i++;
	}
	while (s[i] && s[i] <= '9' && s[i] >= '0')
	{
		if (new * 10 / 10 != new)
			return (sign == 1 ? -1 : 0);
		new = new * 10;
		if ((new += s[i] - '0') < 0)
			return (sign == 1 ? -1 : 0);
		i++;
	}
	return (sign * (int)new);
}
