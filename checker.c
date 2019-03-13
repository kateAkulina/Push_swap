/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:37:32 by lcutjack          #+#    #+#             */
/*   Updated: 2019/03/12 18:20:00 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	valid_com(char *line)
{
	if (!line[2])
	{
		if ((line[0] == 's' || line[0] == 'r') && (line[1] == 'a' || \
			line[1] == 'b' || line[0] == line[1]))
			return (1);
		if (line[0] == 'p' && (line[1] == 'a' || line[1] == 'b'))
			return (1);
	}
	else if (!line[3])
	{
		if (line[0] == 'r' && line[1] == 'r' && (line[2] == 'a' || \
			line[2] == 'b' || line[1] == line[2]))
			return (1);
	}
	return (0);
}

static void	ex_com(t_base *all, char *line)
{
	if (line[2])
		rr(all, line[2], 1);
	else if (*line == 's')
		s(all, line[1], 1);
	else if (*line == 'p')
		p(all, line[1]);
	else
		r(all, line[1], 1);
}

int			main(int ac, char **av)
{
	char	*line;
	t_base	all;
	int		*max;

	if (!fill_stack(&all, ac, av, max))
		return (error());
	while (get_next_line(0, &line) > 0)
	{
		if (!valid_com(line))
			return (error());
		ex_com(&all, line);
	}
	if (is_sorted(all.a, all.b))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	clean(all.a);
	clean(all.b);
	return (0);
}
