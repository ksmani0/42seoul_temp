/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_f_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:03:41 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/27 11:47:13 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	round_up(t_sble *sble, int prec)
{
	int i;
	int up;
	int temp;

	i = sble->p_idx + prec;
	up = 1;
	sble->out_mlen = prec;
	whlie (i > sble->p_idx && up = 1)
	{
		temp = (sble->out[i] - '0') + up;
		sble->out[i--] = temp % 10 + '0';
		up = temp <= 9 ? 0 : up;
	}
	while (up == 1 && i >= 0)
	{
		temp = (sble->out[i] - '0') + up;
		sble->out[i--] = temp % 10 + '0';
		up = temp <= 9 ? 0 : up;
	}
}

void	rounding_meet_five(t_sble *sble, int prec)
{
	int i;
	int not_zero;

	i = sble->p_idx + prec + 2;////
	not_zero = 0;
	while (i <= sble->m_len + prec && not_zero == 0)
	{
		if (ret->s_mod[i++] != '0')
			not_zero = 1;
	}
	if (not_zero == 1)
		round_up(sble, prec);
	else if (not_zero == 0 && (ret->s_mod[prec] - '0') % 2 != 0)
		round_up(sble, prec);
	sble->out_mlen = prec;
}

void	round_f(t_format *list, t_sble *sble)
{
	int prec;

	prec = list->flag[6] == 0 ? 6 : list->prec;
	prec = list->prec >= 1075 ? 1075 : prec;
	if ((list->flag[6] == 0 && sble->m_len < 6) || (sble->m_len < prec))
		sble->out_mlen = list->flag[6] == 0 ? 6 : prec;/*append 0*/
	else if (prec == 1075 && sble->m_len == 1075)
		sble->out_mlen = 1075;
	else
	{
		if (sble->s_mod[prec] < '5')
			sble->out_mlen = prec;
		else if (sble->s_mod[prec] > '5')
			round_up(sble, prec);
		else
			rounding_meet_five(sble, prec);
	}
}

int	make_out_str(t_sble *sble)
{
	int i;

	i = 1;
	j = sble->d_len - 1;
	sble->p_idx = sble->d_len;
	if ((sble->out = (char*)malloc(sizeof(char) *
		(sble->d_len + 1 + m_len + 1))) == 0)
		return (-1);
	sble->out[0] = '0';
	while (i <= sble->d_len)
		sble->out[i++] = sble->s_div[j--];
	i = -1;
	while (++i < sble->m_len)
		sble->out[i] = sble->s_div[i];
	return (1);
}

int	get_f_str(t_format *list, t_dble *dble, t_sble *sble)
{
	t_sble	ret;

	ret = *sble;
	if ((make_out_str(sble)) == 0)
		return (free_sble(-1, sble));
	round_f(list, sble);
	list->size = ret->d_len + 1 + ret->m_len;
	if (list->flag[0] == 1 || list->flag[3] == 1)
		list->size++;
	output_feg(list, &ret, 0);//need
	list->nums = list->nums + (list->size > list->width ?
		list->size : list->width);
	return (free_sble(1, sble));
}