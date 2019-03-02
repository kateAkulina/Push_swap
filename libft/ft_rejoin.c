/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rejoin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 11:55:17 by lcutjack          #+#    #+#             */
/*   Updated: 2018/12/21 11:58:56 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_rejoin(char *a, char *b)
{
	char	*new;

	new = ft_strjoin(a, b);
	free(a);
	free(b);
	a = NULL;
	b = NULL;
	return (new);
}
