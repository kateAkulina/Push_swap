/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 15:34:45 by lcutjack          #+#    #+#             */
/*   Updated: 2019/03/13 10:01:15 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	al_ex(int v, char *str, t_stack *a)
{
	char *tmp;

	tmp = ft_itoa(v);
	if (ft_strlen(*str == '-' ? str + 1 : str) > 10 ||\
		ft_strcmp(tmp, str))
		return (1);
	ft_strdel(&tmp);
	while (a)
	{
		if (a->value == v)
			return (1);
		a = a->next;
	}
	return (0);
}

static char	**kind_of_st(t_base *all, char **av, int *c)
{
	int k;

	k = 0;
	if (!av[1])
		return (av);
	if ((*av)[2] == 'p')
		k = 10;
	if (!ft_strcmp(av[1], "-v") && --(*c) && (++av))
		k += 1;
	all->status = k;
	return (av);
}

static int	add_some(t_stack **i, char **ar, int *m)
{
	int		len;
	t_stack	*flw;

	flw = *i;
	len = 0;
	while (ar[len])
		++len;
	while (len--)
	{
		if (ft_is_ok(ar[len] + (ar[len][0] == '-'), ft_isdigit))
		{
			*i = ft_memalloc(sizeof(t_stack));
			(*i)->value = ft_atoi(ar[len]);
			(*i)->next = flw;
			if (al_ex((*i)->value, ar[len], flw))
				return (clean(*i));
		}
		else
			return (clean(flw));
		*m = *m < (*i)->value ? (*i)->value : *m;
		flw = *i;
		ft_strdel(ar);
	}
	return (1);
}

int			fill_stack(t_base *all, int c, char **av, int *max)
{
	t_stack	*flw;
	t_stack	*i;
	char	**ar;
	int		m;

	flw = NULL;
	i = NULL;
	m = -2147483648;
	av = kind_of_st(all, av, &c);
	while (--c)
	{
		ar = ft_strsplit(av[c], ' ');
		if (!add_some(&i, ar, &m))
			return (0);
	}
	if (max)
		*max = m;
	all->a = i;
	all->b = NULL;
	return (1);
}
