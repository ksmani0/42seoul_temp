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

t_format	*initial_malloc(t_format *list)
{
	if((list = (t_format*)malloc(sizeof(t_format) * 1)) == 0)
		return ((void*)0);
	*list = { 0, };
	return (list);
}

void	print_char(t_format* list)
{
	list->output_num++;
	write(1, list->str++, 1);
}

int	if_flags_check(t_format *list)
{
	if (*list->str == '-')
		list->flags[0] = 1;
	else if (*list->str == '0')
		list->flags[1] = 1;
        else if (*list->str == '.')
		list->flags[2] = 1;
        else if (*list->str == '*')
		list->flags[3] = 1;
	else if (*list->str == '#')
		list->flags[4] = 1;
	else if (*list->str == ' ')
		list->flags[5] = 1;
	else if (*list->str == '+')
		list->flags[6] = 1;
	else
		return (-1);
	return (1);
}

void		str_or_format(va_list ap, t_format *list)
{
	int i;

	while (*list->str != 0)
	{
		if (*list->str != '%')
			print_char(list);
		else if (*list->str == '%')
		{
			i = 2;
			while (i-- != 0)
			{
				while ((if_flags_check(list)) != -1 && *list->str != 0)
				list->str++;
				check_width_prec(list);
			}
			check_length(list);
			check_specific(list);
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

	if ((initial_malloc(list)) == 0)
		return (-1);
	list->str = format;/*서식지정자 등 내용 남긴 문자열*/
	va_start(ap, list->str);/*ap가 고정 인자 다음 인자로 주소 이동*/
	str_or_format(ap, list);
	va_end(ap);
	ret = list->output_num;
	free(list->flags);
	free(list);
	return (ret);
}