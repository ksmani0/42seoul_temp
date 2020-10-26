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
	int w_or_p;

	w_or_p = 0;
	while (*list->str >= '0' && *list->str <= '9')
		w_or_p = w_or_p * 10 + (*list->str++ - '0');
	if (list->flags[2] == 0)
		list->width = w_or_p;
	else if (list->flags[2] == 1)
		list->precision = w_or_p;
}

void	check_length(t_format *list)
{
	while (*list->str >= 'h' && *list->str <= 'l')
	{
		if (*list->str == 'h')
			list->length += 1;
		else if (*list->str == 'l')
			list->length += 3;
		list->str++;
	}
}

void	check_specific(t_format *list)
{
	char c;

	c = *list->str++;
	if (c == 'd' || c == 'i' || c == 'u' || c == 'c' || c == '%'
		|| c == 'x' || c == 'X' || c == 's' || c == 'e'
		|| c == 'f' || c == 'g' || c == 'p' || c == 'n')
		list->specifier = c;
}

void	output_specific(va_list ap, t_format *list)
{
	if (list->specific == 'd' || list->specific == 'i')
		print_s_int(ap, list);
	else if (list->specific == 'u')
		print_s_uint(ap, list);
	else if (list->specific == 'c' || list->specific == 's')
		print_s_char(ap, list);
	else if (list->specific == '%')
		print_s_percent(ap, list);
	else if (list->specific == 'x' || list->specific == 'X')
		print_s_octal(ap, list);
	else if (list->specific == 'e' || list->specific == 'f' || list->specific == 'g')
		print_s_float(ap, list);
	else if (list->specific == 'p')
		print_s_point(ap, list);
	else if (list->specific == 'n')
		print_s_number(ap, list);
}