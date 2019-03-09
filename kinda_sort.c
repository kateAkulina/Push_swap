/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kinda_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 12:24:36 by lcutjack          #+#    #+#             */
/*   Updated: 2019/03/09 20:43:41 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_of_3(t_stack **a)
{
	
}

static void	begin(t_stack **a, t_stack **b, int max)
{
	t_stack	*start;
	int		last;
	int		l;
	int		ll;

	if (!(*a)->next || !(*a)->next->next)
	{
		if ((*a)->next && (*a)->value > (*a)->next->value)
			s(a, a, 'a', 1);
		return ;
	}	
	if ((*a)->value > (*a)->next->value)
		s(a, b, 'a', 1);
	start = *a;
	last = start->value;
	r(a, b, 'a', 1);
	while (((*a)->next)->next != start)
	{
		l = (*a)->value;
		ll = ((*a)->next)->value;
		if (l > last && (last = l))
			r(a, b, 'a', 1);
		else
			p(a, b, 'b', 1);
	}
	if ((*a)->value < (*a)->next->value && (*a)->next->value < start->value)
		return ;
	else if ((*a)->value < (*a)->next->value && (*a)->value < start->value)
		s(a, a, 'a', 2);
	else
	{
		p(a, b, 'b', 2);
		if ((*a)->value > start->value)
			p(a, b, 'b', 2);
	}
}

static void	finish(t_stack **a, int max)
{
	int 	len_r;
	int 	len_rr;
	int 	len;
	t_stack	*i;

	len_r = 1;
	len_rr = 0;
	i = *a;
	while (i->value != max && ++len_r)
		i = i->next;
	while (i->next && ++len_rr)
		i = i->next;
	if (!len_r || !len_rr)
		return ;
	if (len_r <= len_rr)
	{
		while (len_r--)
			r(a, a, 'a', 1);
	}
	else
	{
		while (len_rr--)
			rr(a, a, 'a', 1);
	}
}

void	sort(t_stack **a, t_stack **b, int max)
{
	begin(a, b, max);
	// show(*a, *b);
	while (*b)
	 	base(a, b, max);
	finish(a, max);
	// show(*a, *b);
}
