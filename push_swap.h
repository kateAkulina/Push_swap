/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 20:58:05 by lcutjack          #+#    #+#             */
/*   Updated: 2019/04/13 20:28:13 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "libft/ft_printf.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef	struct	s_stack {
	int				value;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_stacks
{
	t_stack		*a;
	t_stack		*b;
	int			status;
	int			min;
	int			max;
}				t_base;

typedef struct	s_solve
{
	int		pla;
	char	tpa;
	int		plb;
	char	tpb;
	int		way;
}				t_solve;

int				error(void);
int				clean(t_stack *a);
int				len_stack(t_stack *a);
int				fill_stack(t_base *all, int c, char **av, int *max);
void			base(t_base *all, int max);
void			sort(t_base *all, int max);
void			show(t_stack *a, t_stack *b);
void			s(t_base *all, char wh, char stat);
void			p(t_base *all, char wh);
void			r(t_base *all, char wh, char stat);
void			rr(t_base *all, char wh, char stat);
void			finish(t_base *all, int max);
void			sort_3(t_base *all);
int				is_sorted(t_stack *a, t_stack *b, int max, int stat);

#endif
