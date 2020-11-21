/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 20:25:38 by seungmki          #+#    #+#             */
/*   Updated: 2020/11/21 20:27:29 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_llint		check_llint(t_format *list)
{
	t_llint arg;

	if (list->len == 0 || list->len == 'h' || list->len == 'H')
		arg = va_arg(list->ap, int);
	else if (list->len == 'l')
		arg = va_arg(list->ap, long int);
	else if (list->len == 'L')
		arg = va_arg(list->ap, long long int);
	if (list->len == 0)
		arg = (int)arg;
	else if (list->len == 'h')
		arg = (t_sint)arg;
	else if (list->len == 'H')
		arg = (char)arg;
	return (arg);
}

t_ullint	check_ullint(t_format *list)
{
	t_ullint arg;

	if (list->len == 0 || list->len == 'h' || list->len == 'H')
		arg = va_arg(list->ap, unsigned int);
	if (list->len == 'l')
		arg = va_arg(list->ap, unsigned long int);
	else if (list->len == 'L')
		arg = va_arg(list->ap, unsigned long long int);
	if (list->len == 0)
		arg = (t_uint)arg;
	else if (list->len == 'h')
		arg = (t_usint)arg;
	else if (list->len == 'H')
		arg = (t_uchar)arg;
	return (arg);
}

void		ft_llint_to_s(t_llint num, t_format *list)
{
	t_llint	temp;
	int		sign;
	int		len;
	int		ret;

	sign = num >= 0 ? 1 : -1;
	temp = sign == 1 ? num : num * -1;
	len = num <= 0 ? 1 : 0;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	ret = len;
	list->if_num[len] = 0;
	while (temp != 0)
	{
		list->if_num[--len] = temp % 10 + '0';
		temp /= 10;
	}
	list->if_num[0] = sign == -1 ? '-' : list->if_num[0];
	list->if_num[0] = sign == 1 && len == 1 ? '0' : list->if_num[0];
	return (ret);
}

void		ft_ullint_to_s(t_llint num, t_format *list)
{
	t_ullint	temp;
	int			len;
	int			ret;

	temp = num;
	len = num == 0 ? 1 : 0;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	ret = len;
	list->if_num[len] = 0;
	num = temp;
	while (num != 0)
	{
		list->if_num[--len] = num % 10 + '0';
		num /= 10;
	}
	list->if_num[0] = temp == 0 ? '0' : list->if_num[0];
	return (ret);
}
