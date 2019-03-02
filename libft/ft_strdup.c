/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:41:33 by lcutjack          #+#    #+#             */
/*   Updated: 2018/11/30 17:36:09 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*res;
	char	*new;
	char	*frm;

	frm = (char*)s1;
	res = (char*)malloc(sizeof(char) * (ft_strlen(frm) + 1));
	if (!res)
		return (0);
	new = res;
	while (*frm)
		*(new++) = *(frm++);
	*new = '\0';
	return (res);
}
