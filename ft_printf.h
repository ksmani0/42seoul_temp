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

char g_hex_b[17] = "0123456789ABCDEF";
char g_hex_s[17] = "0123456789abcdef";

typedef struct s_format {
	char	*str;
	char	flag[6];/*-0.# +*/
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

/*
*****print_int.c*****
/*

size_t		count_num_len(long num, t_format *list);
void		input_list_num(t_format *list, long num, size_t len);
void		output_int(char *out, t_format *list, size_t len);
int		print_s_int(t_format *list);

/*
*****print_uint.c*****
/*

int		print_s_uint(t_format *list);
int		print_s_char(t_format *list);
size_t		parse_input_hex(unsigend int x, t_format *list);
int		print_s_octal(t_format **list);

#endif
