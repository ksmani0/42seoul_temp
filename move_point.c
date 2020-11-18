/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:56:08 by seungmki          #+#    #+#             */
/*   Updated: 2020/11/18 11:57:21 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_e_num(t_sble *ret, int e, int sign, int len)
{
	int i;

	i = 0;
	ret->e_int = e;
	ret->esign = esign == 1 ? '+' ? '-';
	ret->e[0] = e == 0 ? '0' : 0;/*+00*/
	ret->e[1] = e == 0 ? '0' : 0;
	while (e != 0)
	{
		ret->e[i++] = (e % 10) + '0';
		e /= 10;
	}
	ret->e[i] = i == 1 ? '0' : ret->e[i];
}

int	move_point(t_sble *ret)
{
	int e;
	int i;
	int esign;
	int len;

	i = 0;
	e = ret->d_len > 1 ? d_len - 1 : 0;
	esign = ret->d_len > 1 ? 1 : -1;
	else if (ret->d_len == 1 && ret->s_div[0] == '0')
	{
		while (ret->s_mod[i++] == '0')
			e--;
		esign = e >= 1 ? -1 : sign;
	}
	len = ft_intlen(e);
	len = len == 1 ? 2 : len;
	if ((ret->e = (char*)melloc(sizeof(char) * (len + 3))) == 0)
		return (-1);
	ret->e[len + 2] = 0;
	ret->e[len + 1] = 'e';
	ret->e[len] = esign == 1 ? '+' : '-';
	fill_e_num(ret, e, esign, len);/*reversal*/
	return (1);
}

void	round_e(t_format *list, t_sble *ret)
{
	int prec;

	prec = list->flag[6] == 0 ? 6 : list->prec;
	prec = list->prec >= 1075 ? 1075 : prec;
	if ()

	if ((list->flag[6] == 0 && ret->m_len < 6) || (ret->m_len < prec))
		ret->m_len = list->flag[6] == 0 ? 6 : prec;/*append 0*/
	else if (prec == 1075 && ret->m_len == 1075)
		return ;
	else
	{
		if (ret->s_mod[prec + 1] < 5)
		{
			ret->m_len = prec;
			return ;
		}
		else if (ret->s_mod[prec + 1] > 5)
		{
			round_up(ret, prec);
			return ;
		}
		else
			rounding_meet_five(ret, prec);
	}
}