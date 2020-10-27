/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 11:35:46 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/27 11:36:10 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_s_uint(t_format *list)
{
	unsigned int	num;
	size_t		len;
	char		*out;

	num = (unsigned int)va_arg(list->ap, int);
	len = count_num_len((long)num, list);
	input_list_num(list, (long)num, len);
	list->out_len = list->width > list->prec ? list->width : list->prec;
	list->out_len = len > list->out_len ? len : list->out_len;
	if ((out = (char*)malloc(sizeof(char) * (list->out_len + 1))) == 0)
		return (-1);
	out[list->out_len] = 0;
	if (list->flag[0] == 1 && list->flag[1] == 1)/*-, 0*/
		list->flag[0] = 0;
	output_num(out, list, len);
	return (1);
}

int	print_s_char(t_format *list)
{
	char	c;
	size_t	len;
	char	*out;

	c = '%';
	if (list->spec == 'c')
		c = (char)va_arg(ap, int);
	list->if_num[0] = c;
	len = 1;
	list->out_len = list->width > list->prec ? list->width : list->prec;
	list->out_len = len > list->out_len ? len : list->out_len;
	if ((out = (char*)malloc(sizeof(char) * (list->out_len + 1))) == 0)
		return (-1);
	out[list->out_len] = 0;
	output_num(out, list, len);
	return (1);
}

size_t	parse_input_hex(unsigend int x, t_format *list)
{
	unsigned int	temp;
	size_t		len;
	size_t		ret;
	char		hp;

	temp = x;
	len = 1;
	while (temp / 16 > 0)
		len++;
	ret = len;
	hp = list->spec == 'x' ? g_hex_s : g_hex_b;
	while (x > 0)
	{
		list->if_num[--len] = hp[x % 16];
		x /= 16;
	}
	return (ret);
}

int	print_s_octal(t_format **list)
{
	unsigned int	x;
	size_t		len;

	x = (unsigned int)va_arg(list->ap, int);
	len = parse_input_hex(x, list);
	list->out_len = list->width > list->prec ? list->width : list->prec;
	list->out_len = len > list->out_len ? len : list->out_len;
	output_num(out, list, len);
	return (1);
}

void	print_s_number(t_format *list)
{//잘못된 인자 들어와도 얘만 제외하고 나머지 출력됨
	size_t len;

	if ((list->str - 1) == 'n' && (list->str - 1) != '%')
		return ;
	len = count_num_len((long)list->out_num, list);
	input_list_num(list, (long)num, len);
	if ((out = (char*)malloc(sizeof(char) * (len + 1))) == 0)
		return ;
	out[len] = 0;
	output_num(out, list, len);
}