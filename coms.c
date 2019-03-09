/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coms.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:32:17 by lcutjack          #+#    #+#             */
/*   Updated: 2019/03/06 18:15:58 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_stack **a, t_stack **b, char wh, char status)
{
	t_stack	*start;
	t_stack **l;

	l = wh == 'a' ? a : b;
	if (!(*l) || !(*l)->next)
		return ;
	start = (*l)->next;
	(*l)->next = ((*l)->next)->next;
	start->next = *l;
	*l = start;
	if (wh == 's')
		s(a, b, 'a', 0);
	if (status > 0)
		ft_printf("s%c\n", wh);
	if (status > 1)
		show(*a, *b);
}

void	p(t_stack **a, t_stack **b, char wh, char status)
{
	t_stack	**from;
	t_stack **to;
	t_stack *tmp;

	from = wh == 'a' ? b : a;
	to = wh == 'a' ? a : b;
	if (!*from)
		return ;
	tmp = *from;
	*from = (*from)->next;
	tmp->next = *to;
	*to = tmp;
	if (status > 0)
		ft_printf("p%c\n", wh);
	if (status > 1)
		show(*a, *b);
}

void	r(t_stack **a, t_stack **b, char wh, char status) // 1 -> last
{
	t_stack	*start;
	t_stack **l;
	t_stack *last;

	l = wh == 'a' ? a : b;
	if (!*l || !(*l)->next)
		return ;
	start = (*l)->next;
	last = *l;
	while ((*l)->next)
		*l = (*l)->next;
	(*l)->next = last;
	last->next = NULL;
	*l = start;
	if (wh == 'r')
		r(a, b, 'a', 0);
	if (status > 0)
		ft_printf("r%c\n", wh);
	if (status > 1)
		show(*a, *b);
}

void	rr(t_stack **a, t_stack **b, char wh, char status) // last -> 1
{
	t_stack	*start;
	t_stack **l;
	t_stack *new_start;

	l = wh == 'a' ? a : b;
	if (!*l || !(*l)->next)
		return ;
	start = *l;
	while ((new_start = (*l)->next))
	{
		if (!new_start->next && (new_start->next = start) && !((*l)->next = NULL))
			break ;
		*l = (*l)->next;
	}
	*l = new_start;
	if (wh == 'r')
		rr(a, b, 'a', 0);
	if (status > 0)
		ft_printf("rr%c\n", wh);
	if (status > 1)
		show(*a, *b);
}
/* those are absolutely done */