/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kinda_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 12:24:36 by lcutjack          #+#    #+#             */
/*   Updated: 2019/03/21 15:21:47 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		lets_start(t_base *all, int max, int l, int ll)
{
	if (!all->a || !all->a->next || !all->a->next->next || \
		!all->a->next->next->next)
	{
		sort_3(all);
		return ;
	}
	while (all->a->next->next->next)
	{
		if (all->a->value == max)
			r(all, 'a', 1);
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
			base(all, max);
	}
	finish(all, max);
}
