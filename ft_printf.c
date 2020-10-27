/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:03:41 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/19 13:04:19 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*initial_malloc(t_format **list)
{
	if((*list = (t_format*)malloc(sizeof(t_format) * 1)) == 0)
		return ((void*)0);
	*(*list) = { 0, };
	return (*list);
}

void		print_char(t_format **list)
{
	(*list)->out_num++;
	write(1, (*list)->str++, 1);
}

void		if_flag_check(t_format **list)
{
	t_format *lp;

	lp = *list;
	while (1)
	{
		if (*lp->str == '-')
			lp->flag[0] = 1;
		else if (*lp->str == '0')
			lp->flag[1] = 1;
        	else if (*lp->str == '.')
			lp->flag[2] = 1;
		else if (*lp->str == '#')
			lp->flag[3] = 1;
		else if (*lp->str == ' ')
			lp->flag[4] = 1;
		else if (*lp->str == '+')
			lp->flag[5] = 1;
		else
		{
			(*list)->str = lp->str;
			return ;
		}
		lp->str++;
	}
}

int		str_or_format(t_format *list)
{
	while (*list->str != 0)
	{
		if (*list->str != '%')
			print_char(&list);
		else if (*list->str++ == '%')
		{
			initial_part(&list);
			if_flag_check(&list);
			check_width_prec(&list);
			if_flag_check(&list);
			check_width_prec(&list);
			check_length(&list);
			if ((check_specific(&list)) == -1 || (output_specific(list)) == -1)
				return (-1);
		}
		list->str++;
	}
	return (1);
}

int		ft_printf(const char *format, ...)
{
	t_format	*list;
	int		ret;

	if (format == 0 || (initial_malloc(&list)) == 0)
		return (-1);
	list->str = format;/*서식지정자 등 담긴 문자열*/
	va_start(list->ap, list->str);/*ap가 고정 인자 너머 가변 인자로 주소 이동*/
	if ((str_or_format(list)) == -1)
		list->out_num = -1;
	va_end(list->ap);
	ret = list->out_num;
	free(list);
	return (ret);
}