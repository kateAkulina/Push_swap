/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 19:54:41 by lcutjack          #+#    #+#             */
/*   Updated: 2019/03/01 17:42:54 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

typedef	struct	s_struct{
	char		flag[5];
	int			width;
	int			prec;
	char		len;
	char		spec;
	int			size;
	char		*buf;
}				t_info;

void			set_prec(t_info *d);
void			set_sign(t_info *d, int sign);
void			set_width(t_info *d);
void			tp_c(t_info *data, va_list *ap);
void			tp_s(t_info *data, va_list *ap);
void			tp_p(t_info *data, va_list *ap);
void			tp_i(t_info *data, va_list *ap);
void			tp_oux(t_info *data, va_list *ap);
void			tp_f(t_info *data, va_list *ap);
int				what_type(char **s, va_list *ap);
int				ft_printf(const char *format, ...);

#endif
