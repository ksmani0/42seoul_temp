/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki </var/mail/seungmki>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 22:49:54 by seungmki          #+#    #+#             */
/*   Updated: 2020/11/20 22:49:58 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_lsw_size(t_format *list, wchar_t ls, t_uchar *new)
{
	int len;

	len = ls < 128 ? 1 : 0;
	len = len == 0 && ls < 2048 ? 2 : len;
	len = len == 0 && ls < 65536 ? 3 : len;
	len = len == 0 && ls < 2097152 ? 4 : len;
	if ((new = (t_uchar*)malloc(sizeof(t_uchar) * len)) == 0)
		return (-1);
	if (len == 1)
		new[0] = (t_uchar)ls;
	else if (len == 2)
		new[0] = (ls >> 6) + 192;/*110?????*/
	else if (len == 3)
		new[0] = (ls >> 12) + 224;/*1110????*/
	else if (len == 4)
	{
		new[0] = (ls >> 18) + 240;/*11110???*/
		new[1] = ((ls >> 12) & 63) + 128;/*10??????*/
	}
	if (len > 2)
		new[len - 2] = ((ls >> 6) & 63) + 128;/*10??????*/
	if (len > 1)
		new[len - 1] = (ls & 63) + 192;/*10??????*/
	list->size++;/*출력할 문자수 기록*/
	return (len);
}

int	input_ls_to_us(t_format *list, wchar_t ls, t_uchar *out)
{
	int	bytes;
	int	len;
	t_uchar new[5];
	t_uchar *temp;
	int	i;
	int	j;

	ft_bzero((void*)new, 5);
	if ((bytes = count_lsw_size(list, ls, new)) < 0)
		return (-1);
	len = (int)ft_ustrlen(out) + bytes;/*ls의 바이트수만큼 추가해서 out 늘림*/
	if ((temp = (t_uchar*)malloc(sizeof(t_uchar) * (len + 1))) == 0)
		return (-1);
	i = -1;
	while (out[++i] != 0)
		temp[i] = out[i];
	j = 0;
	while (j < bytes)
		temp[i++] = new[j++];
	free(out);
	out = temp;
	return (bytes);
}

int	count_out_num(t_format *list, wchar_t *ls, t_uchar *out, int *bytes)
{
	int temp;
	int size;
	int i;

	i = 0;
	size = (int)ft_wcharlen((const wchar_t *)ls);/*몇 문자 출력되는지 따짐*/
	if (list->flag[6] == 1 && list->prec < size)
	{/*정밀도 존재하고 크기가 문자 개수보다 작을 때*/
		while (i < list->prec)
		{
			if (temp = input_ls_to_us(list, ls[i++], out) < 0)
				return (-1);
			*bytes += temp;
		}
	}
	else
	{
		while (ls[i] != 0)
		{
			if (temp = input_ls_to_us(list, ls[i++], out) < 0)
				return (-1);
			*bytes += temp;
		}
	}
	return (1);
}

void	output_ls(t_format *list, t_uchar *out, int bytes)
{
	int i;
	int size;/*number of characters to be printed*/

	size = list->size;
	i = 0;
	if (list->flag[1] == 0 && list->width > size)
	{
		while (i++ < list->width - size)
			write(1, " ", 1);
	}
	write(1, out, bytes);
	i = 0;
	if (list->flag[1] == 1 && list->width > size)
	{
		while (i++ < list->width - size)
			write(1, " ", 1);
	}
	free(out);
	list->nums += size;
}

int	print_ls(t_format *list)
{
	wchar_t	*ls;
	t_uchar	*out;
	int	bytes;/*ls's bytes to print*/

	out = 0;
	bytes = 0;
	if ((ls = va_arg(list->ap, wchar_t*)) == 0)/*wchar=4bytes*/
		return (print_null(list));
	if ((count_out_num(list, ls, out, &bytes)) < 0)
	{
		free(out);
		return (-1);
	}
	output_ls(list, out, bytes);
	return (1);
}
