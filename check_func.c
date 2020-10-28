/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:03:41 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/19 13:04:19 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_width_prec(t_format *list)
{
	short	w_or_p;

	w_or_p = 0;
	if (*list)->str == '*')/* *.*, *., .*, *d */
	{
		if (list->flag[2] == 0)
			list->width = (short)va_arg(list->ap, int);
		else if (list->flag[2] == 1)
			list->prec = (short)va_arg(list->ap, int);
		list->str++;
		return ;
	}
	while (*list->str >= '0' && *list->str <= '9')
		w_or_p = w_or_p * 10 + (*list->str++ - '0');
	if (list->flag[2] == 0 && w_or_p > 0)/*.*/
		list->width = w_or_p;
	else if list->flag[2] == 1 && w_or_p > 0)
		list->prec = w_or_p;
	if (list->flag[0] == 1)/*-*/
		list->flag[1] = 0;
	if (list->flag[5] == 1)/*+*/
		list->flag[4] = 0;
}

void	check_length(t_format **list)
{
	t_format *lp;

	lp = *list;
	if (*lp->str == 'h' && *(lp->str + 1) == 'h')
		lp->len = 'H';
	else if (*lp->str == 'h' && *(lp->str + 1) != 'h')
		lp->len = 'h';
	else if (*lp->str == 'l' && *(lp->str + 1) == 'l')
		list->len = 'l';
	else if (*lp->str == 'l' && *(lp->str + 1) != 'l')
		lp->len = 'L';
	else
		return ;
	lp->str = lp->len == 'h' || lp->len == 'l' ? lp->str + 1 : lp->str + 2;
	*list->str = lp->str;
}

int	check_specific(t_format **list)
{
	char c;

	c = *(*list)->str;
	if ((c >= 'd' && c <= 'g') || c == '%')
		(*list)->spec = c;
	else if (c == 'i' || c == 'n' || c == 'p' ||
		c == 's' || c == 'u' || c == 'x' || c == 'X')
		(*list)->specifier = c;
	else
		return (-1);
	(*list)->str++;
	return (1);
}

void	initial_part(t_format **list)
{
	int i;

	i = 0;
	while (i < 6)
		(*list)->flag[i++] = 0;
	(*list)->spec = 0;
	i = 0;
	while (i < 12 && (*list)->if_num[i] != 0)
		(*list)->if_num[i++] = 0;
	(*list)->len = 0;
	(*list)->width = 0;
	(*list)->prec = 0;
	(*list)->out_len = 0;
}

int	output_specific(t_format *list)
{
	if (list->spec == 'd' || list->spec == 'i')
		return (print_s_int(list));
	else if (list->spec == 'u')
		return (print_s_uint(list));
	else if (list->spec == 'c' || list->spec == '%')
		return (print_s_char(list));
	else if (list->spec == 's')
		print_s_str(list);
	else if (list->spec == 'x' || list->spec == 'X')
		return (print_s_octal(list));
	else if (list->spec == 'e' || list->spec == 'f' || list->spec == 'g')
		ret = print_s_float(list);
	else if (list->spec == 'p')
		ret = print_s_point(list);
	else if (list->spec == 'n')
		print_s_number(list);
	return (-1);
}