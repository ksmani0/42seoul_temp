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

void		print_char(t_format *list)
{
	list->nums++;
	write(1, list->str++, 1);
}

void	initial_part(t_format *list)
{
	int i;

	i = 0;
	while (i < 6)
		list->flag[i++] = 0;
	list->spec = 0;
	i = 0;
	while (i < 21 && list->if_num[i] != 0)
		list->if_num[i++] = 0;
	list->len = 0;
	list->width = 0;
	list->prec = 0;
	list->size = 0;
}

int		str_or_format(t_format *list)
{
	while (*list->str != 0)
	{
		if (*list->str != '%')
			print_char(list);
		else if (*list->str++ == '%')
		{
			initial_part(list);
			if_flag_check(list);
			check_width_star(list);
			check_prec_star(list);
			check_length(list);
			if ((check_spec(list)) == -1 || (output_spec(list)) == -1)
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
		list->nums = -1;
	va_end(list->ap);
	ret = list->nums;
	free(list);
	return (ret);
}