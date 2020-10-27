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

void	print_s_uint(va_list ap, t_format *list)
{
	unsigned int	num;
	size_t		len;
	char		*out;

	num = va_arg(ap, unsigned int);
	len = count_num_len((long)num, (long)num, list);/*수 저장해놓음*/
	list->if_num[0] = num == 0 ? '0' : list->if_num[0];
	list->out_len = list->width > list->prec ? list->width : list->prec;
	list->out_len = len > list->out_len ? len : list->out_len;
	if ((out = (char*)malloc(sizeof(char) * (list->out_len + 1))) == 0)
		return ;
	out[list->out_len] = 0;
	if (list->flag[0] == 1 && list->flag[1] == 1)/*-, 0*/
		list->flag[0] = 0;
	make_int(out, list, len);
}

void	print_s_char(va_list ap, t_format *list)
{
	char	c;
	size_t	len;
	char	*out;

	c = va_arg(ap, int);////
	len = count_num_len((long)num, (long)num, list);/*수 저장해놓음*/
	list->if_num[0] = num == 0 ? '0' : list->if_num[0];
	list->out_len = list->width > list->prec ? list->width : list->prec;
	list->out_len = len > list->out_len ? len : list->out_len;
	if ((out = (char*)malloc(sizeof(char) * (list->out_len + 1))) == 0)
		return ;
	out[list->out_len] = 0;
	if (list->flag[0] == 1 && list->flag[1] == 1)/*-, 0*/
		list->flag[0] = 0;
	make_int(out, list, len);
}
