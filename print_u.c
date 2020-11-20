/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 11:35:46 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/27 11:36:10 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	output_u(char *out, t_format *list, int len)
{/* |123|..123|..00123|00123|123..| */
	int i;

	i = 0;
	if (list->width > len && list->width > list->prec)
	{/* |..123|..00123| */
		int longer = len > list->prec ? len : list->prec;
		fill_space_or_zero(&i, list->size - longer, out, ' ');
	}
	if (list->prec > len)/* |..00123|00123| */
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

int	print_u(t_format *list)
{
	t_ullint	num;
	int		len;
	char		*out;

	if (list->flag[0] == 1 || list->flag[3] == 1 || list->flag[5] == 1)/* +' '# */
		return (-1);
	num = check_ullint(list);
	len = ft_ullint_to_s(num, list);
	list->size = list->width > list->prec ? list->width : list->prec;
	list->size = len > list->size ? len : list->size;
	if ((out = (char*)malloc(sizeof(char) * (list->size + 1))) == 0)
		return (-1);
	out[list->size] = 0;
	output_u(out, list, len);/*-0.*/
	return (1);
}