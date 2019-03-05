/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:26:53 by lcutjack          #+#    #+#             */
/*   Updated: 2019/03/05 17:14:40 by lcutjack         ###   ########.fr       */
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

static void	do_sort(t_stack **a, t_stack **b, t_solve *what)
{
	while (what->tpa_com && what->tpb_com && what->sta && what->stb)
	{
		what->sta--;
		what->stb--;
		rr(a, b, 'r', 1);
	}
	while (what->tpa_com && what->sta)
	{
		what->sta--;
		rr(a, b, 'a', 1);
	}
	while (what->tpb_com && what->stb)
	{
		what->stb--;
		rr(a, b, 'b', 1);
	}
	while (!what->tpa_com && !what->tpb_com && what->sta && what->stb)
	{
		what->sta--;
		what->stb--;
		r(a, b, 'r', 1);
	}
	while (!what->tpa_com && what->sta)
	{
		what->sta--;
		r(a, b, 'a', 1);
	}
	while (!what->tpb_com && what->stb)
	{
		what->stb--;
		r(a, b, 'b', 1);
	}
	p(a, b, 'a', 1);
}

static int 	find_right(int n, t_stack *a, int max)
{
	int len;
	int pl;

	pl = 1;
	len = len_stack(a);
	while (pl < len / 2 + len % 2)
	{
		if ((a->value < n && a->next->value) || (n == max && n > a->value))
			return (-pl);
		++pl;
		a = a->next;
	}
	while (a->next)
	{
		if ((a->value < n || a->value == max) && a->next->value > n)
			return (len - pl);
		++pl;
		a = a->next;
	}
	return (0);
}

static void	find_way(t_stack *a, t_stack *b, t_solve *what, int max)
{
	int		pl_a;
	int		pl_b;
	char	tp;
	int		len;

	pl_b = 1;
	len = len_stack(b);
	while (pl_b < len / 2 + len % 2)
	{
		pl_a = find_right(b->value, a, max);
		tp = pl_a < 0 ? -1 : 0;
		pl_a = pl_a < 0 ? -pl_a : pl_a;
		if ((pl_b == 1) || (pl_a + pl_b < what->sta + what->stb))
		{
			what->sta = pl_a;
			what->stb = pl_b;
			what->tpb_com = 0;
			what->tpa_com = tp;
		}
		++pl_b;
		b = b->next;
	}
	pl_b = 0;
	while (b && ++pl_b)
	{
		pl_a = find_right(b->value, a, max);
		tp = pl_a < 0 ? -1 : 0;
		pl_a = pl_a < 0 ? -pl_a : pl_a;
		if (pl_a + pl_b < what->sta + what->stb)
		{
			what->sta = pl_a;
			what->stb = pl_b;
			what->tpb_com = -1;
			what->tpa_com = tp;
		}
		b = b->next;
	}
	printf("HERE A: %d, B: %d\n", what->sta, what->stb);
}

void	base(t_stack **a, t_stack **b, int max)
{
	t_solve what;
	
	find_way(*a, *b, &what, max);
	show(*a, *b);
	do_sort(a, b, &what);
}