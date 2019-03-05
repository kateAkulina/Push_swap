/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 16:11:57 by lcutjack          #+#    #+#             */
/*   Updated: 2019/02/26 15:48:51 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	*line;
	t_stack	*a;
	t_stack *b;
	int		max;

	if (!(a = fill_stack(ac, av, &max)))
		return (error());
	sort(&a, &b, max);
	// show(a, b);
	return (0);
}
