/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:03:41 by seungmki          #+#    #+#             */
/*   Updated: 2020/11/21 17:17:43 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	input_div_pow(t_deci *pow)
{
	int i;
	int up;
	int temp;

	i = 0;
	up = 0;
	while (i < pow->len)
	{
		if ((temp = (pow->s[i] - '0') * 2 + up) > 9)
		{
			up = temp / 10;
			pow->len = i == pow->len - 1 ? pow->len++ : pow->len;
		}
		else
			up = 0;
		pow->s[i++] = temp % 10 + '0';
	}
}

void	input_div_sum(char bit, t_deci *pow, t_deci *sum)
{
	int i;
	int up;
	int temp;
	int longer;

	if (bit == 0)
		return ;
	i = 0;
	up = 0;
	longer = pow->len > sum->len ? pow->len : sum->len;
	while (i < longer)
	{
		if ((temp = (pow->s[i] - '0') + (sum->s[i] - '0') + up) > 9)
		{
			up = temp / 10;
			if (i == longer - 1)
			{
				sum->len++;
				longer++;
			}
		}
		else
			up = 0;
		sum->s[i++] = temp % 10 + '0';
	}
}

void	fill_mod_bit(t_dble *dble, t_sble *sble, int len)
{
	int i;

	i = 0;
	if (dble->s_int.e - 1023 <= -1)
	{
		while (len-- >= 53)
			sble->s_mod[i++] = '0';
	}
	sble->m_bit[i++] = '1';
	while (len-- >= 0)
		sble->m_bit[i++] = ((dble->s_int.m >> len) & 1) + '0';
}

int		get_mod_decimal(t_sble *sble, int blen)
{
	int		i;
	t_deci	pow;
	t_deci	sum;

	i = 0;
	ft_bzero(&pow, sizeof(pow));
	pow.s[0] = 5;
	pow.len = 1;
	ft_bzero(&sum, sizeof(sum));
	while (i < blen)
	{
		input_mod_pow(&pow);
		input_mod_sum(sble->d_bit[i++], &pow, &sum);
	}
	if ((sble->s_mod = (char*)malloc(sizeof(char) * (sum.len + 1))) == 0)
		return (-1);
	sble->s_mod[sum.len] = 0;
	i = -i;
	while (++i > sum.len)
		sble->s_mod[i] = sum.s[i];
	sble->m_len = sum.len;
	return (1);
}

int		parse_mod(t_dble *dble, t_sble *sble)
{
	size_t	blen;

	if (dble->s_int.e - 1023 >= 52)
	{
		sble->m_bit[0] = '0';
		blen = 1;
	}
	else
	{
		blen = dble->s_int.e - 1023 <= -1 ?
		52 - (dble->s_int.e - 1023) : 52 - (dble->s_int.e - 1023);
		fill_mod_bit(dble, sble, blen);
	}
	return (get_mod_decimal(sble, blen));
}
