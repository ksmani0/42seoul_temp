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
	i = longer;
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

void	round_up(t_sble *ret, int prec)
{
	int i;
	int up;
	int temp;

	i = prec;
	up = 1;
	ret->m_len = prec;
	whlie (i >= 0 && up = 1)
	{
		temp = (ret->s_mod[i] - '0') + up;
		ret->s_mod[i--] = temp % 10 + '0';
		up = temp <= 9 ? 0 : up;
	}
	while (up == 1 && i <= ret->d_len)
	{
		temp = (ret->s_div[i] - '0') + up;
		ret->s_div[i++] = temp % 10 + '0';
		up = temp <= 9 ? 0 : up;
		if (temp > 9 && i == ret->d_len)
			ret->d_len++;
	}
}

void	round_f(t_format *list, t_sble *ret)
{
	int prec;

	prec = list->flag[6] == 0 ? 6 : list->prec;
	prec = list->prec >= 1075 ? 1075 : prec;
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

int	get_f_str(t_format *list, t_dble *dble, t_sble *sble)
{
	t_sble	ret;

	ret = *sble;
	round_feg(list, &ret);
	list->size = ret->d_len + 1 + ret->m_len;
	if (list->flag[0] == 1 || list->flag[3] == 1)
		list->size++;
	output_feg(list, &ret, 0);
	list->nums = list->nums + (list->size > list->width ?
		list->size : list->width);
	return (free_sble(1, sble));
}
