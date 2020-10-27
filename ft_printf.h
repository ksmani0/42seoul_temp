/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:06:17 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/19 13:10:42 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_format {
	char	*str;
	char	flag[6];/* -0.# + */
	char	spec;/*specifier: cspdiuxX%nfge*/
	char	if_num[12];
	char	len;/*h, hh:H, l, ll:L*/
	va_list	ap;
	short	width;
	short	prec;/*precision*/
	short	out_len;
	int	out_num;
}		t_format

/*
*****ft_printf.c*****
/*

t_format	*initial_malloc(t_format **list);
void		print_char(t_format* list);
int		if_flag_check(t_format *list);
void		str_or_format(va_list ap, t_format *list);
int		ft_printf(const char *format, ...);

/*
*****check_func.c*****
/*


#endif
