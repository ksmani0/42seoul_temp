/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:03:41 by seungmki          #+#    #+#             */
/*   Updated: 2020/11/21 20:44:49 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_space_or_zero(int *i, int limit, char *out, char s_or_z)
{
	int j;

	j = *i;
	while (j < limit)
		out[j++] = s_or_z;
	*i = j;
}

void	output_di_ngf(char *out, t_format *list, int len)
{
	int i;

	i = 0;
	if (list->if_num[0] == '-')
		out[i++] = '-';
	else if (list->flag[0] == 1 || list->flag[3] == 1)
		out[i++] = list->flag[0] == 1 ? '+' : ' ';
	if (list->prec > len)
		fill_space_or_zero(&i, list->size - len, out, '0');
	len = list->if_num[0] == '-' ? 1 : 0;
	while (list->if_num[len] != 0)
		out[i++] = list->if_num[len++];
	if (i < list->size)
		fill_space_or_zero(&i, list->size, out, ' ');
	write(1, out, i);
	free(out);
	list->nums += i;
}

void	output_di(char *out, t_format *list, int len)
{
	int i;

	i = 0;
	if (list->width > len && list->width > list->prec)
	{
		int longer = len > list->prec ? len : list->prec;
		if (list->if_num[0] != '-' && (list->flag[0] == 1 ||
		list->flag[3] == 1))
			longer++;
		fill_space_or_zero(&i, list->size - longer, out, ' ');
	}
	if (list->if_num[0] == '-')
		out[i++] = '-';
	else if (list->flag[0] == 1 || list->flag[3] == 1)
		out[i++] = list->flag[0] == 1 ? '+' : ' ';
	if (list->prec > len)
		fill_space_or_zero(&i, list->size - len, out, '0');
	if (list->width > len && list->width > list->prec)
		fill_space_or_zero(&i, list->prec - len, out, '0');
	len = list->if_num[0] == '-' ? 1 : 0;
	while (list->if_num[len] != 0)
		out[i++] = list->if_num[len++];
	write(1, out, i);
	free(out);
	list->nums += i;
}

int		print_di(t_format *list)
{
	t_llint	num;
	int		len;
	char	*out;

	if (list->flag[5] == 1)
		return (-1);
	num = check_llint(list);
	len = ft_llint_to_s(num, list);
	len = num == 0 && list->prec == 0 ? 0 : len;
	list->if_num[0] = num == 0 && list->prec == 0 ? 0 : list->if_num[0];
	list->size = list->width > list->prec ? list->width : list->prec;
	list->size = len > list->size ? len : list->size;
	if (list->if_num[0] != '-' && (list->flag[0] == 1 || list->flag[3] == 1)
		&& (len == list->size || list->prec == list->size))
		list->size++;
	if ((out = (char*)malloc(sizeof(char) * (list->size + 1))) == 0)
		return (-1);
	out[list->size] = 0;
	if (list->flag[1] == 1)
		output_di_ngf(out, list, len);
	else
		output_di(out, list, len);
	return (1);
}

int		output_spec(t_format *list)
{
	if (list->spec == 'd' || list->spec == 'i')
		return (print_di(list));
	else if (list->spec == 'u')
		return (print_u(list));
	else if (list->spec == 'c')
		return (print_c(list));
	else if (list->spec == '%')
		return (print_percent(list));
	else if (list->spec == 's')
		return (print_s(list));
	else if (list->spec == 'x' || list->spec == 'X')
		return (print_x(list));
	else if (list->spec == 'o')
		return (print_o(list));
	else if (list->spec == 'e' || list->spec == 'f' || list->spec == 'g')
		return (print_feg(list));
	else if (list->spec == 'p')
		return (print_p(list));
	else if (list->spec == 'n')
		return (print_n(list));
	return (-1);
}
