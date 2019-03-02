/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:53:55 by lcutjack          #+#    #+#             */
/*   Updated: 2018/12/04 11:44:46 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*th;
	int		i;
	int		j;

	if (!*needle)
		return ((char*)haystack);
	i = 0;
	th = (char*)needle;
	while (haystack[i])
	{
		if (haystack[i] == th[0])
		{
			j = 0;
			while (th[j] && haystack[i + j] == th[j])
				j++;
			if (!th[j])
				return ((char*)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
