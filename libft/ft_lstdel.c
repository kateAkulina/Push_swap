/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:09:48 by lcutjack          #+#    #+#             */
/*   Updated: 2018/12/21 14:40:16 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;
	t_list	*p;

	if (!alst || !*alst || !del)
		return ;
	p = *alst;
	while (p)
	{
		tmp = p;
		ft_lstdelone(&p, del);
		p = tmp->next;
	}
	*alst = NULL;
}
