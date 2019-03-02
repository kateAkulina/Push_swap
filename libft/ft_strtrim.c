/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:21:45 by lcutjack          #+#    #+#             */
/*   Updated: 2018/12/01 17:03:28 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	char	*st;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	st = (char*)s;
	while (*st == ' ' || *st == '\n' || *st == '\t')
		++st;
	i = ft_strlen(st) - 1;
	while (i > -1 && (st[i] == ' ' || st[i] == '\n' || st[i] == '\t'))
		--i;
	++i;
	if (!(new = ft_strnew(i * sizeof(char))))
		return (NULL);
	if (!*st)
		return (new);
	else
		new = ft_strncpy(new, st, i);
	return (new);
}
