/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_feg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:03:41 by seungmki          #+#    #+#             */
/*   Updated: 2020/11/21 20:35:16 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		change_e_num(t_sble *sble)
{
	int		elen;
	char	*tp;

	if (sble->out[sble->d_idx] != '0')
		return ;
	if (sble->esign == '-' && sble->out[sble->d_idx] == '0' &&
	sble->out[sble->d_idx - 1] == '1')
	{
		sble->esign = '+';
		elen = 2;
	}
	else if (sble->esign == '+' && sble->out[sble->d_idx] == '0' &&
	sble->out[sble->d_idx - 1] == '1')
	{
		elen = ft_numlen(sble->e_int + 1);
		if ((tp = (char*)malloc(sizeof(char) * (elen + 3))) == 0)
			return (-1);
		free(sble->e);
		sble->e = tp;
	}
	fill_e_num(sble, ++sble->e_int, elen);
	sble->d_idx--;
	return (1);
}

void	output_feg_sign(t_format *list, t_sble *sble, int *i)
{
	int elen;

	*i = *i + 1;
	if (list->flag[0] == 1)
		sble->sign == 1 ? write(1, "+", 1) : write(1, "-", 1);
	else if (list->flag[3] == 1)
		sble->sign == 1 ? write(1, " ", 1) : write(1, "-", 1);
	if (list->width > list->size && list->spec != 'e')
		list->nums += list->width;
	else if (list->width <= list->size && list->spec != 'e')
		list->nums += list->size;
	else if (list->spec == 'e')
	{
		elen = ft_strlen(sble->e);
		if (list->width > list->size + elen)
			list->nums += list->width;
		else if (list->width <= list->size + elen)
			list->nums += (list->size + elen);
	}
}

void	output_decimal(t_format *list, t_sble *sble, int i)
{
	int len;

	i = sble->out[0] != '0' ? 0 : 1;
	while (i <= sble->d_idx)
		write(1, &sble->out[i], 1);
	write(1, ".", 1);
	while (i <= sble->m_idx)
		write(1, &sble->out[i], 1);
	if (list->flag[5] == 1 && list->flag[6] == 1 && list->prec == 0)
		write(1, ".", 1);
	if (list->flag[5] == 1 && list->flag[6] == 1 && list->prec == 0)
		write(1, ".", 1);
	if (list->spec == 'e')
	{
		len = ft_strlen(sble->e) - 1;
		if (list->width > list->size + len)
			list->nums += list->width;
		while (i >= 0)
			write(1, &sble->e[i--], 1);
	}
}

void	output_feg(t_format *list, t_sble *sble, int i)
{
	if (list->width > list->size && list->flag[1] == 0)
	{
		if (list->flag[2] == 1)
			output_feg_sign(list, sble, &i);
		while (list->flag[2] == 1 && i++ < list->width - list->size)
			write(1, "0", 1);
		while (list->flag[2] == 0 && i++ < list->width - list->size)
			write(1, " ", 1);
		if (list->flag[2] == 0)
			output_feg_sign(list, sble, &i);
	}
	if (list->flag[1] == 1)
		output_feg_sign(list, sble, &i);
	output_decimal(list, sble, 0);
	i = 0;
	while (list->flag[1] == 1 && i++ < list->width - list->size)
		write(1, " ", 1);
	free_sble(1, sble);
}

int		get_g_str(t_format *list, t_dble *dble, t_sble *sble)
{
	int p;

	if (list->flag[6] == 0)
		p = 6;
	else if (list->flag[6] == 1)
		p = list->prec == 0 ? 1 : list->prec;
	if (p > sble->e_int && sble->e_int >= -4)
	{
		list->prec = p - 1 - sble->e_int;
		list->spec = 'f';
		return (get_f_str(list, dble, sble));
	}
	list->prec = p - 1;
	list->spec = 'e';
	return (get_e_str(list, dble, sble));
}
