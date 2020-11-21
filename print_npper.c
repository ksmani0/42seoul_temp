/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_npper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 11:35:46 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/27 11:36:10 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_percent(t_format *list)
{
	char	*out;
	int	i;

	list->size = list->width > 1 ? list->width : 1;
	if ((out = (char*)malloc(sizeof(char) * (list->size + 1))) == 0)
		return (-1);
	out[list->size] = 0;
	i = 0;
	if (list->flag[2] == 1 && list->size > 1)/*0*/
		fill_space_or_zero(&i, list->size - 1, out, '0');
	out[i] = '%';/* 최너/-/0만 유효*/
	write(1, out, list->size);
	free(out);
	return (1);
}

int	print_n(t_format *list)
{
	t_lint	*lint;
	int	*o_int;
	t_sint	*sint;

	if (list->width > 0 || list->prec > 0 || list->flag[0] == 1 ||
	list->flag[1] == 1 || list->flag[2] == 1 || list->flag[3] == 1
	|| list->flag[4] == 1 || list->flag[5] == 1)
		return (-1);
	if (list->len == 'L' || list->len == 'l')
	{/* long long과 long은 64비트 동일 */
		lint = va_arg(list->ap, long int*);
		*lint = list->nums;
	}
	else if (list->len == '0' || list->len == 'H')
	{/* char는 int로 승격 */
		o_int = va_arg(list->ap, int*);
		*o_int = list->nums;
	}
	if (list->len == 'h')
	{
		sint = va_arg(list->ap, short int*);
		*sint = list->nums;
	}
	return (1);
}

int	ft_arr_to_s(t_ulint adrr, t_format *list)
{
	t_ulint temp;
	int	len;
	int	ret;

	len = 0;
	temp = adrr;
	while (adrr != 0)
	{
		adrr /= 16;
		len++;
	}
	ret = len;
	adrr = temp;
	while (adrr != 0)
	{
		list->if_num[--len] = g_hex_s[adrr % 16];
		adrr /= 16;
	}
	list->if_num[0] = len == 0 ? '0' : list->if_num[0];
	return (ret);
}

void	output_p(char *out, t_format *list, int len)
{
	int i;

	i = 0;
	if (list->width > len + 2 && list->flag[1] != 1)/* |..0x7ffeef8e786b| */
		fill_space_or_zero(&i, list->size - list->width, out, ' ');
	out[i++] = '0';
	out[i++] = 'X';
	len = 0;
	while (list->if_num[len] != 0)
		out[i++] = list->if_num[len++];
	if (list->width > len + 2)/* |0x7ffeef8e786b|0x7ffeef8e786b...| */
		fill_space_or_zero(&i, list->size, out, ' ');
	write(1, out, i);
	free(out);
	list->nums += i;
}

int	print_p(t_format *list)
{
	t_ulint	adrr;
	int	len;
	char	*out;

	if (list->prec > 0 || list->flag[0] == 1 || list->flag[2] == 1	
	|| list->flag[3] == 1 || list->flag[4] == 1 || list->flag[5] == 1)
		return (-1);/* +0' '*# 최너/-만 가능 */
	adrr = (t_ulint)va_arg(list->ap, void*);/* 0x7ffeef8e786b/12 */
	len = ft_arr_to_s(adrr, list);
	list->size = len == 0 ? 3 : len + 2;
	list->size = list->size > list-> width ? list->size : list->width;
	if ((out == (char*)malloc(sizeof(char) * (list->size + 1))) == 0)
		return (-1);
	out[list->size] = 0;
	output_p(out, list, len);
	return (1);
}