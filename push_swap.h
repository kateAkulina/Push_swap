/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 20:58:05 by lcutjack          #+#    #+#             */
/*   Updated: 2019/03/06 16:16:27 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "libft/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef	struct	s_stack {
	int				value;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_solve
{
	int		pla;
	char	tpa;
	int		plb;
	char	tpb;
}				t_solve;

int				error(void);
t_stack			*fill_stack(int c, char **av, int *max);
void			base(t_stack **a, t_stack **b, int max);
void			sort(t_stack **a, t_stack **b, int max);
void			show(t_stack *a, t_stack *b);
void			s(t_stack **a, t_stack **b, char wh, char status);
void			p(t_stack **a, t_stack **b, char wh, char status);
void			r(t_stack **a, t_stack **b, char wh, char status);
void			rr(t_stack **a, t_stack **b, char wh, char status);
int				is_sorted(t_stack *a, t_stack *b);

#endif
