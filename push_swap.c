/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 16:11:57 by lcutjack          #+#    #+#             */
/*   Updated: 2019/03/12 18:08:56 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	*line;
	t_stack	*a;
	t_stack *b;
	int		max;
	t_base	all;

	if (!fill_stack(&all, ac, av, &max))
		return (error());
	sort(&all, max);
	clean(all.a);
	return (0);
}
