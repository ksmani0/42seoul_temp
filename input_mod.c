/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_mod.c                                        :+:      :+:    :+:   */
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