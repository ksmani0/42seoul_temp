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

void		print_char(t_format* list)
{
	list->out_num++;
	write(1, list->str++, 1);
}

int		if_flag_check(t_format *list)
{
	if (*list->str == '-')
		list->flag[0] = 1;
	else if (*list->str == '0')
		list->flag[1] = 1;
        else if (*list->str == '.')
		list->flag[2] = 1;
	else if (*list->str == '#')
		list->flag[3] = 1;
	else if (*list->str == ' ')
		list->flag[4] = 1;
	else if (*list->str == '+')
		list->flag[5] = 1;
	else
		return (-1);
	return (1);
}

void		str_or_format(va_list ap, t_format *list)
{
	while (*list->str != 0)
	{
		if (*list->str != '%')
			print_char(list);
		else if (*list->str++ == '%')
		{
			initial_part(&list);
			while ((if_flag_check(list)) == 1 && *list->str != 0)
				list->str++;
			check_width_prec(ap, list);
			while ((if_flag_check(list)) == 1 && *list->str != 0)
				list->str++;
			check_width_prec(ap, list);
			check_length(list);
			if ((check_specific(list)) == -1)
				return ;
			output_specific(ap, list);
		}
		list->str++;
	}
}

int		ft_printf(const char *format, ...)
{
	t_format	*list;
	va_list		ap;/*char**/
	int		ret;

	if (format == 0 || (initial_malloc(&list)) == 0)
		return (-1);
	list->str = format;/*서식지정자 등 담긴 문자열*/
	va_start(ap, list->str);/*ap가 고정 인자 너머 가변 인자로 주소 이동*/
	str_or_format(ap, list);
	va_end(ap);
	ret = list->output_num;
	free(list);
	return (ret);
}