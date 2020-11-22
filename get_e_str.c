/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_e_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:03:41 by seungmki          #+#    #+#             */
/*   Updated: 2020/11/21 20:30:38 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	input_mod_pow(t_deci *pow)
{
	int i;

	i = 0;
	while (i < pow->len)
	{
		if (((pow->s[i] - '0') % 2) != 0)
			pow->s[i + 1] = '5';
		pow->s[i] = (pow->s[i] - '0') / 2 + '0';
		i++;
	}
	pow->len++;
}

void	input_mod_sum(char bit, t_deci *pow, t_deci *sum)
{
	int i;
	int up;
	int temp;
	int longer;

	if (bit == 0)
		return ;
	up = 0;
	longer = pow->len > sum->len ? pow->len : sum->len;
	i = longer - 1;
	while (i >= 0)
	{
		if ((temp = (pow->s[i] - '0') + (sum->s[i] - '0') + up) > 9)
			up = temp / 10;
		else
			up = 0;
		sum->s[i--] = (temp % 10) + '0';
	}
	sum->len = longer;
}

void	fill_e_num(t_sble *sble, int e, int elen)
{
	int i;

	sble->e[elen + 2] = 0;
	sble->e[elen + 1] = 'e';
	sble->e[elen] = sble->esign;
	i = 0;
	sble->e[0] = e == 0 ? '0' : 0;
	sble->e[1] = e == 0 ? '0' : 0;
	while (e != 0)
	{
		sble->e[i++] = (e % 10) + '0';
		e /= 10;
	}
	sble->e[i] = i == 1 ? '0' : sble->e[i];
}

int		move_point(t_sble *sble)
{
	int i;
	int elen;

	i = 0;
	sble->esign = '+';
	if ((sble->out[1] == '0') && ((sble->m_idx > 2) ||
	(sble->m_idx == 2 && sble->out[2] != '0')))
		sble->esign = '-';
	if (sble->esign != '+')
		sble->e_int = sble->d_idx - 1;
	else if (sble->esign == '-')
	{
		i = sble->d_idx + 1;
		while (sble->out[i++] == '0')
			sble->e_int--;
		sble->e_int--;
	}
	elen = ft_intlen(sble->e_int);
	elen = elen == 1 ? 2 : elen;
	if ((sble->e = (char*)malloc(sizeof(char) * (elen + 3))) == 0)
		return (-1);
	fill_e_num(sble, sble->e_int, elen);
	sble->d_idx = sble->out[1] != '0' ? 1 : sble->e_int * -1;
	return (1);
}

int		get_e_str(t_format *list, t_sble *sble)
{
	if ((make_out_str(sble)) == -1 || (move_point(sble)) == -1)
		return (free_sble(-1, sble));
	round_feg(list, sble);
	if ((change_e_num(sble)) == -1)
		return (free_sble(-1, sble));
	list->size = sble->out[0] == '0' ? sble->m_idx + 1 : sble->m_idx + 2;
	list->size = sble->sign == '-' ? list->size++ : list->size;
	if ((sble->sign == '+') && (list->flag[0] == 1 || list->flag[3] == 1))
		list->size++;
	if (list->flag[5] == 1 && list->flag[6] == 1 && list->prec == 0)
		list->size++;
	output_feg(list, sble, 0);
	list->nums = list->nums + (list->size > list->width ?
		list->size : list->width);
	return (free_sble(1, sble));
}
