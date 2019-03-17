/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 12:28:07 by lcutjack          #+#    #+#             */
/*   Updated: 2019/03/17 12:49:54 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			clean(t_stack *a)
{
	t_stack	*n;

	while (a)
	{
		n = a->next;
		free(a);
		a = n;
	}
	return (0);
}

int			is_sorted(t_stack *a, t_stack *b, int max, int stat)
{
	if (b)
		return (0);
	if (!a)
		return (1);
	while (a->next)
	{
		if ((!stat) && a->value > (a->next)->value)
			return (0);
		else if (stat && a->value > (a->next)->value && a->value != max)
			return (0);
		a = a->next;
	}
	return (1);
}

void		finish(t_base *all, int max)
{
	int		len_r;
	int		len_rr;
	int		len;
	t_stack	*i;

	if (!all->a)
		return ;
	len_r = 1;
	len_rr = 0;
	i = all->a;
	while (i->value != max && ++len_r)
		i = i->next;
	while (i->next && ++len_rr)
		i = i->next;
	if (!len_r || !len_rr)
		return ;
	if (len_r <= len_rr)
		while (len_r--)
			r(all, 'a', 1);
	else
		while (len_rr--)
			rr(all, 'a', 1);
}

static void	sort_real_3(t_base *all, int l, int ll, int lll)
{
	if (l < ll && ll < lll)
		return ;
	else if (lll < l && l < ll)
		rr(all, 'a', 1);
	else if (ll < lll && lll < l)
		r(all, 'a', 1);
	else if (l < lll && lll < ll)
	{
		rr(all, 'a', 1);
		s(all, 'a', 1);
	}
	else if (lll < ll && ll < l)
	{
		s(all, 'a', 1);
		rr(all, 'a', 1);
	}
	else
		s(all, 'a', 1);
}

void		sort_3(t_base *all)
{
	int l;
	int ll;
	int lll;

	if (!all->a)
		return ;
	l = all->a->value;
	if (!(all->a->next))
		return ;
	ll = all->a->next->value;
	if (!all->a->next->next)
	{
		if (l > ll)
			s(all, 'a', 1);
		return ;
	}
	lll = all->a->next->next->value;
	sort_real_3(all, l, ll, lll);
}
