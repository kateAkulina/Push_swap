/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coms.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:32:17 by lcutjack          #+#    #+#             */
/*   Updated: 2019/03/17 12:50:17 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_base *all, char wh, char stat)
{
	t_stack	*start;
	t_stack **l;
	t_stack **ll;

	l = wh == 'a' ? &(all->a) : &(all->b);
	if (!(*l) || !(*l)->next)
		return ;
	start = (*l)->next;
	(*l)->next = ((*l)->next)->next;
	start->next = *l;
	*l = start;
	if (wh == 's')
		s(all, 'a', 0);
	if (all->status / 10 && stat)
	{
		ft_putchar('s');
		ft_putchar(wh);
		ft_putchar('\n');
	}
	if (all->status % 10)
		show(all->a, all->b);
}

void	p(t_base *all, char wh)
{
	t_stack	**from;
	t_stack **to;
	t_stack *tmp;

	from = wh == 'a' ? &(all->b) : &(all->a);
	to = wh == 'a' ? &(all->a) : &(all->b);
	if (!*from)
		return ;
	tmp = *from;
	*from = (*from)->next;
	tmp->next = *to;
	*to = tmp;
	if (all->status / 10)
	{
		ft_putchar('p');
		ft_putchar(wh);
		ft_putchar('\n');
	}
	if (all->status % 10)
		show(all->a, all->b);
}

void	r(t_base *all, char wh, char stat)
{
	t_stack	*start;
	t_stack **l;
	t_stack *last;

	l = wh == 'a' ? &(all->a) : &(all->b);
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
		r(all, 'a', 0);
	if (all->status / 10 && stat)
	{
		ft_putchar('r');
		ft_putchar(wh);
		ft_putchar('\n');
	}
	if (all->status % 10)
		show(all->a, all->b);
}

void	rr(t_base *all, char wh, char stat)
{
	t_stack	*start;
	t_stack **l;
	t_stack *new_start;

	l = wh == 'a' ? &(all->a) : &(all->b);
	if (!(start = *l) || !(*l)->next)
		return ;
	while ((new_start = (*l)->next))
	{
		if (!new_start->next && (new_start->next = start) && \
			!((*l)->next = NULL))
			break ;
		*l = (*l)->next;
	}
	*l = new_start;
	if (wh == 'r')
		rr(all, 'a', 0);
	if (all->status / 10 && stat)
	{
		ft_putstr("rr");
		ft_putchar(wh);
		ft_putchar('\n');
	}
	if (all->status % 10)
		show(all->a, all->b);
}

int		error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}
