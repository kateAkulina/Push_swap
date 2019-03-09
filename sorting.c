/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 16:15:15 by lcutjack          #+#    #+#             */
/*   Updated: 2019/03/01 14:13:09 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	give_last(t_stack *a)
// {
// 	while (a->next)
// 		a = a->next;
// 	return (a->value);
// }

// static void	sort_3(t_stack **a)
// {
// 	int f;
// 	int n;
// 	int l;

// 	f = (*a)->value;
// 	n = ((*a)->next)->value;
// 	l = (((*a)->next)->next)->value;
// 	if (f < n && n < l)
// 	 	return ;
// 	if (f > n && n > l)
// 	{
// 		s(a, a, 'a');
// 		rr(a, a, 'a');
// 	}
// 	else if ((f > l) && (l > n))
// 	 	r(a, a, 'a');
// 	else if (f > n && f < l)
// 		s(a, a, 'a');
// 	else if ((f < l) && (l < n))
// 	{
// 	 	rr(a, a, 'a');
// 	 	s(a, a, 'a');
// 	}
// 	else if ((f > l) && (f < n))
// 	 	rr(a, a, 'a');
// }

// static void		st_split(t_stack **a, t_stack **b)
// {
// 	t_stack	*third;

// 	if (!(*a)->next)
// 	 	return ;
// 	if (!((*a)->next)->next)
// 	{
// 		if ((*a)->value > ((*a)->next)->value)
// 			s(a, a, 'a');
// 		return ;
// 	}
// 	third = ((*a)->next)->next;
// 	while (third->next)
// 	{
// 		p(a, b, 'b');
// 		third = (*a)->next->next;
// 	}
// 	sort_3(a);
// }

// static void		base_sort(t_stack **a, t_stack **b)
// {
// 	while 
// }

// void		sort(t_stack **a, t_stack **b)
// {
// 	t_stack *start;

// 	st_split(a, b);
// 	base_sort(a, b);
// 	show(*a, *b);
// }
