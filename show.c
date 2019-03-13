/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:32:02 by lcutjack          #+#    #+#             */
/*   Updated: 2019/03/13 09:33:35 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show(t_stack *a, t_stack *b)
{
	while (a || b)
	{
		if (a)
			ft_printf("%11d >< ", a->value);
		else
			ft_printf("%11c >< ", ' ');
		if (b)
			ft_printf("%-11d\n", b->value);
		else
			ft_printf("%-11c\n", ' ');
		a = a ? a->next : a;
		b = b ? b->next : b;
	}
	ft_printf("          ------\n       a    ><    b\n");
}
