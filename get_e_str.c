/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_e_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:03:41 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/27 11:47:13 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



void	output_feg_sign(t_format *list, t_sble *ret, int *i)
{
	*i = *i + 1;
	if (list->flag[0] == 1)
		ret->sign == 1 ? write(1, "+", 1) : write(1, "-", 1);
	else if (list->flag[3] == 1)
		ret->sign == 1 ? write(1, " ", 1) : write(1, "-", 1);
}

void	output_decimal(t_format *list, t_sble *ret)//
{
	int i;

	i = ret->d_len - 1;
	if (ret->e != 0 && ret->esign = '+')
		write(1, &ret->s_div[i], 1);
	else if (ret->e != 0 && ret->esign = '-')
		write(1, &ret->s_mod[e - 1], 1);
	else if (ret->e == 0)
	{
		while (i >= 0)
			write(1, &ret->s_div[i--], 1);
	}
	write(1, ".", 1);
	if (ret->e != 0 && ret->esign = '+')
	{
		i = 0;
		while (i < ret->m_len)
			write(1, &ret->[i++], 1);
	}
	else if (ret->e == 0)
	{
		while (i < ret->m_len)
			write(1, &ret->[i++], 1);
	}
}

void	output_e(t_format *list, t_sble *ret)//
{
	int i;

	if (ret->e == 0)
		return ;
	i = ft_strlen(ret->e) - 1;
	list->nums += (i + 1);
	while (i >= 0)
		wirte(1, &ret->e[i--], 1);
}

void	output_feg(t_format *list, t_sble *ret, int i)/////////# 하고 e는 따로??
{
	if (list->width > list->size && list->flag[1] == 0)
	{
		if (list->flag[2] == 1)
			output_feg_sign(list, ret, &i);
		while (list->flat[2] == 1 && i++ < list->width - list->size)
			write(1, "0", 1);
		while (list->flat[2] == 0 && i++ < list->width - list->size)
			write(1, " ", 1);
		if (list->flag[2] == 0)
			output_feg_sign(list, ret, &i);
	}
	if (list->flag[1] == 1)
		output_feg_sign(list, ret, &i);
	output_decimal(list, ret);
	output_e(list, ret);
	i = 0;
	while (list->flag[1] == 1 && i++ < list->width - list->size)
		write(1, " ", 1);
}

int	get_e_str(t_format *list, t_dble *dble, t_sble *sble)
{
	t_sble	ret;

	ret = *sble;
	make_out_str(ret);
	if ((move_point(&ret)) == 0)
		return (free_sble(-1, sble));
	round_e(list, &ret);
	list->size = ret->d_len + 1 + ret->m_len;
	if (list->flag[0] == 1 || list->flag[3] == 1)
		list->size++;
	output_feg(list, &ret, 0);
	list->nums = list->nums + (list->size > list->width ?
		list->size : list->width);
	return (free_sble(1, sble));
}