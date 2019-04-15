/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kinda_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 12:24:36 by lcutjack          #+#    #+#             */
/*   Updated: 2019/04/13 20:32:48 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		lets_start(t_base *all, int max, int l, int ll)
{
	int last;

	if (!all->a || !all->a->next || !all->a->next->next || \
		!all->a->next->next->next)
	{
		sort_3(all);
		return ;
	}
	last = all->a->value;
	r(all, 'a', 1);
	while (all->a->next->next->next)
	{
		if (is_sorted(all->a, all->b, max, 1))
			return ;
		if (all->a->value == max || last < all->a->value)
		{
			last = all->a->value;
			r(all, 'a', 1);
		}
		else
			p(all, 'b');
	}
	sort_3(all);
}

void			sort(t_base *all, int max)
{
	int l;
	int ll;

	if (!is_sorted(all->a, all->b, max, 1))
	{
		lets_start(all, max, l, ll);
		while (all->b)
			base(all, all->max);
	}
	finish(all, max);
}
