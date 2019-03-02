/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 13:55:43 by lcutjack          #+#    #+#             */
/*   Updated: 2018/12/21 12:11:15 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = ft_memalloc(sizeof(t_list))))
		return (NULL);
	new->next = NULL;
	if (!content)
	{
		new->content = 0;
		new->content_size = 0;
		return (new);
	}
	if (!(new->content = ft_memalloc(content_size)))
	{
		ft_memdel((void**)&new);
		return (NULL);
	}
	new->content_size = content_size;
	new->content = ft_memcpy(new->content, content, content_size);
	return (new);
}
