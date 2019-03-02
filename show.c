/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:32:02 by lcutjack          #+#    #+#             */
/*   Updated: 2019/03/02 19:02:23 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show(t_stack *a, t_stack *b)
{
	while (a || b)
	{
		ft_printf("%11.d >< %-11.d\n", a ? a->value : 0, b ? b->value : 0);
		a = a ? a->next : a;
		b = b ? b->next : b;
	}
	ft_printf("          a >< b\n");
}
