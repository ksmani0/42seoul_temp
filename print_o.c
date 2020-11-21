/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:38:03 by seungmki          #+#    #+#             */
/*   Updated: 2020/11/21 17:46:03 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		octal_to_str(t_ullint o, t_format *list)
{
	t_ullint	temp;
	char		*octal;
	int			len;
	int			ret;

	temp = o;
	len = 0;
	while (o != 0)
	{
		o /= 8;
		len++;
	}
	ret = len;
	octal = "01234567";
	o = temp;
	while (o != 0)
	{
		list->if_num[--len] = octal[o % 8];
		temp /= 8;
	}
	list->if_num[0] = ret == 0 ? '0' : list->if_num[0];
	return (ret != 0 ? ret : 1);
}

void	output_sharp_o(char *out, t_format *list, int len)
{
	int i;
	int longer;

	i = 0;
	longer = len > list->prec ? len : list->prec;
	if (list->flag[1] == 0 && list->width > len + 1 && len >= list->prec)
		fill_space_or_zero(&i, list->size - (len + 1), ' ');
	else if (list->flag[1] == 0 && list->width > longer)
		fill_space_or_zero(&i, list->size - longer, ' ');
	out[i++] = '0';
	if (list->prec > len + 1)
		fill_space_or_zero(&i, list->prec - (len + 1), '0');
	len = 0;
	while (list->if_num[len] != 0)
		out[i++] = list->if_num[len++];
	if (len + 1 >= list->prec && list->width > len + 1)
		fill_space_or_zero(&i, list->size, ' ');
	else if (list->width > longer)
		fill_space_or_zero(&i, list->size - longer, ' ');
	write(1, out, i);
	free(out);
}

void	output_o(char *out, t_format *list, int len)
{
	int i;
	int longer;

	i = 0;
	if (list->flag[1] == 0 && list->width > len && list->width > list->prec)
	{
		longer = len > list->prec ? len : list->prec;
		fill_space_or_zero(&i, list->size - longer, out, ' ');
	}
	if (list->prec > len)
		fill_space_or_zero(&i, list->size - len, out, '0');
	len = 0;
	while (list->if_num[len] != 0)
		out[i++] = list->if_num[len++];
	if (list->flag[1] == 1 && list->width > len && list->width > list->prec)
		fill_space_or_zero(&i, list->size, out, ' ');
	write(1, out, i);
	free(out);
	list->nums += i;
}

int		print_o(t_format *list)
{
	t_ullint	o;
	int			len;
	char		*out;

	if (list->flag[0] == 1 || list->flag[3] == 1)
		return (-1);
	o = check_ullint(list);
	len = octal_to_str(o, list);
	len = o == 0 && list->prec == 0 ? 0 : len;
	list->if_num[0] = o == 0 && list->prec == 0 ? 0 : list->if_num[0];
	list->size = list->width > list->prec ? list->width : list->prec;
	list->size = len > list->size ? len : list->size;
	if (list->flag[5] == 1 && list->width < len + 1 && list->prec < len + 1)
		list->size = list->size + 1;
	if ((out = (char*)malloc(sizeof(char) * (list->size + 1))) == 0)
		return (-1);
	out[list->size] = 0;
	if (list->flag[5] == 1)
		output_sharp_o(out, list, len);
	else
		output_o(out, list, len);
	return (1);
}
