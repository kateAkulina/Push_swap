/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 15:34:45 by lcutjack          #+#    #+#             */
/*   Updated: 2019/03/02 18:51:51 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

static t_stack	*clean(t_stack *a)
{
	t_stack	*n;

	while (a)
	{
		n = a->next;
		free(a);
		a = n;
	}
	return (NULL);
}

static int		al_ex(int v, t_stack *a)
{
	while (a)
	{
		if (a->value == v)
			return (1);
		a = a->next;
	}
	return (0);
}

t_stack			*fill_stack(int c, char **av, int *max)
{
	t_stack	*flw;
	t_stack	*i;
	int		m;

	flw = NULL;
	i = NULL;
	m = -2147483648;
	while (--c)
	{
		if (ft_is_ok(av[c][0] == '-' && av[c][1] ? av[c] + 1 : av[c], \
			ft_isdigit) && (i = ft_memalloc(sizeof(t_stack))))
		{
			i->value = ft_atoi(av[c]);
			if (al_ex(i->value, flw))
				return (clean(flw));
		}
		else
			return (clean(flw));
		m = i->value > m ? i->value : m;
		i->next = flw;
		flw = i;
	}
	if (max)
		*max = m;
	return (i);
}

int				is_sorted(t_stack *a, t_stack *b)
{
	if (b)
		return (0);
	while (a->next)
	{
		if (a->value > (a->next)->value)
			return (0);
		a = a->next;
	}
	return (1);
}
