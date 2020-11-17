/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_feg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:03:41 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/27 11:47:13 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	rounding_meet_five(t_sble *ret, int prec)
{
	int i;
	int not_zero;

	i = prec + 2;
	not_zero = 0;
	while (i <= ret->m_len && not_zero == 0)
	{
		if (ret->s_mod[i++] != '0')
			not_zero = 1;
	}
	if (not_zero == 1)
		round_up(ret, prec);
	else if (not_zero == 0 && (ret->s_mod[prec] - '0') % 2 != 0)
		round_up(ret, prec);
}

void	output_feg_sign(t_format *list, t_sble *ret, int *i)
{
	*i = *i + 1;
	if (list->flag[0] == 1)
		ret->sign == 1 ? write(1, "+", 1) : write(1, "-", 1);
	else if (list->flag[3] == 1)
		ret->sign == 1 ? write(1, " ", 1) : write(1, "-", 1);
}

void	output_feg(t_format *list, t_sble *ret, int i)//#, e+
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
	i = ret->d_len - 1;
	while (i >= 0)
		write(1, &ret->[i--], 1);
	write(1, ".", 1);
	i = 0;
	while (i < ret->m_len)
		write(1, &ret->[i++], 1);
	i = 0;
	while (list->flag[1] == 1 && i++ < list->width - list->size)
		write(1, " ", 1);
}

int	move_point(t_sble *ret)
{
	int e;
	int i;

	e = 0;//ret->d_len == 1
	i = 0;
	if (ret->d_len > 1)
		e = d_len - 1;
	else if (ret->d_len == 1 && ret->s_div[0] == '0')
	{
		while (ret->s_mod[i++] == '0')
			e--;
	}


	if ((ret->e == (char*)melloc(sizeof() * )) == 0)
	return (1);
}

int	get_e_str(t_format *list, t_dble *dble, t_sble *sble)
{
	t_sble	ret;

	ret = *sble;
	if ((move_point(&ret)) == 0)
		return (free_sble(-1, sble));
	round_feg(list, &ret);
	list->size = ret->d_len + 1 + ret->m_len;
	if (list->flag[0] == 1 || list->flag[3] == 1)
		list->size++;
	output_feg(list, &ret, 0);
	list->nums = list->nums + (list->size > list->width ?
		list->size : list->width);
	return (free_sble(1, sble));
}