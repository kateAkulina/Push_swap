/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:35:12 by lcutjack          #+#    #+#             */
/*   Updated: 2018/12/04 19:39:20 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	k_size(char const *s, char c)
{
	size_t	i;
	size_t	n;

	n = 0;
	i = 0;
	while (s[i] && s[i + 1])
	{
		if (s[i] == c && s[i + 1] != c)
			++n;
		i++;
	}
	if (*s && s[0] != c)
		n += 1;
	return (n);
}

static void		*del_created(char ***d, size_t j)
{
	while (--j)
		free(**(d++));
	free(*d);
	*d = NULL;
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**new;
	size_t	j;
	size_t	len;
	size_t	count;
	char	*word;

	if (!s)
		return (NULL);
	count = k_size(s, c);
	if (!s || !(new = (char**)malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	new[count] = 0;
	j = 0;
	while (count-- && !(len = 0))
	{
		while (*s == c && *s)
			s++;
		word = (char*)s;
		while (*s != c && ++len && *s)
			s++;
		if (!(new[j] = ft_strnew(len)))
			return (del_created(&new, j));
		ft_strncpy(new[j++], word, len);
	}
	return (new);
}
