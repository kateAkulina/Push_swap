/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:26:53 by lcutjack          #+#    #+#             */
/*   Updated: 2019/03/09 16:34:06 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	len_stack(t_stack *a)
{
	int	len;

	len = 0;
	while (a && ++len)
		a = a->next;
	return (len);
}

static int	where_to_push(int n, t_stack *a, int max)
{
	int	apl;
	int len;

	len = len_stack(a);
	apl = 1;
	while (apl <= len / 2)
	{
		if (a->next->value > n && (a->value < n || a->value == max))
			return (apl);
		++apl;
		a = a->next;
	}
	while(a->next)
	{
		if ((a->value < n || a->value == max) && a->next->value > n)
			return (apl - len);
		++apl;
		a = a->next;
	}
	return (0);
}

static void	find_short_way(t_stack *a, t_stack *b, t_solve *w, int max)
{
	int len;
	int	apl;
	int bpl;

	bpl = 0;
	len = len_stack(b);
	while (bpl < len / 2 + len % 2)
	{
		apl = where_to_push(b->value, a, max);
		if (!bpl || (apl + bpl < w->pla + w->plb))
		{
			w->pla = apl < 0 ? -apl : apl;
			w->plb = bpl;
			w->tpa = apl < 0 ? 1 : 0;
			w->tpb = 0;
		}
		b = b->next;
		++bpl;
	}
	while(b)
	{
		apl = where_to_push(b->value, a, max);
		if (apl + (len - bpl) < w->pla + w->plb)
		{
			w->pla = apl < 0 ? -apl : apl;
			w->plb = len - bpl;
			w->tpa = apl < 0 ? 1 : 0;
			w->tpb = 1;
		}
		b = b->next;
		++bpl;
	}
	// printf("HERE : PL_A: %d, TP_A: %d, PL_B: %d, TP_B: %d AND MAXIM: %d\n", w->pla, w->tpa, w->plb, w->tpb, max);
}

void		sort_out(t_stack **a, t_stack **b, t_solve *w)
{
	while (w->tpa && w->tpb && w->plb && w->pla && w->plb-- && w->pla--)
		rr(a, b, 'r', 1);
	while (!w->tpa && !w->tpb && w->plb && w->pla && w->plb-- && w->pla--)
		r(a, b, 'r', 1);
	while (w->tpa && w->pla && w->pla--)
		rr(a, b, 'a', 1);
	while (w->tpb && w->plb && w->plb--)
		rr(a, b, 'b', 1);
	while (!w->tpa && w->pla && w->pla--)
		r(a, b, 'a', 1);
	while (!w->tpb && w->plb && w->plb--)
		r(a, b, 'b', 1);
	p(a, b, 'a', 1);
}

void		base(t_stack **a, t_stack **b, int max)
{
	t_solve what;
	
	find_short_way(*a, *b, &what, max);
	sort_out(a, b, &what);
	//show(*a, *b);
}
