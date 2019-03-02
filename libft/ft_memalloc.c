/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:18:30 by lcutjack          #+#    #+#             */
/*   Updated: 2018/11/30 20:26:17 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*new;

	new = (unsigned char*)malloc(size * sizeof(unsigned char));
	if (!new)
		return (NULL);
	while (size-- > 0)
		new[size] = 0;
	return (new);
}
