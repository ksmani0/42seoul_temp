/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:12:07 by seungmki          #+#    #+#             */
/*   Updated: 2020/11/21 17:36:17 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_div_decimal(t_dble *dble, t_sble *sble, int blen)
{
	int		i;
	t_deci	pow;
	t_deci	sum;

	i = blen;
	ft_bzero(pow, sizeof(pow));
	pow.s[0] = 1;
	pow.len = 1;
	ft_bzero(sum, sizeof(sum));
	while (i >= 0)
	{
		input_div_pow(&pow);
		input_div_sum(sble->d_bit[i--], &pow, &sum);
	}
	if ((sble->s_div = (char*)malloc(sizeof(char) * (sum.len + 1))) == 0)
		return (-1);
	sble->s_div[sum.len] = 0;
	i = -i;
	while (++i < sum.len)
	{
		sble->s_div[i] = sum.s[i];
		sble->d_len++;
	}
	return (1);
}

int		parse_div(t_dble *dble, t_sble *sble)
{
	size_t	blen;
	int		i;
	int		j;

	if (dble->s_int.e - 1023 <= -1)
	{
		sble->d_bit[0] = '0';
		blen = 1;
	}
	else
	{
		blen = dble->s_int.e - 1023 + 1 > 53 ? 53 : dble->s_int.e - 1023 + 1;
		sble->d_bit[0] = 1;
		i = 0;
		j = 51;
		while (j >= 0 && j > 52 - blen)
			sble->d_bit[++i] = (dble->s_int.m & 1 >> j--) + '0';
	}
	sble->sign = dble->s_int.s == 1 ? '-' : '+';
	return (get_div_decimal(dble, sble, blen));
}

int		check_inf_nan(t_dble *dble, t_format *list, int i)
{
	char	*s;
	int		len;

	len = 3;
	if (dble->s_int.e != 2047)
		return ;
	if ((dble->s_int.s == 0 && dble->s_int.e == 2047 && dble->s_int.m == 0)
	|| (dble->s_int.e == 2047 && dble->s_int.m >= 1))
		s = dble->s_int.m >= 1 ? "nan" : "inf";
	else if (dble->s_int.e == 1 && dble->s_int.e == 2047 &&
	dble->s_int.m == 0 && (len = 4))
		s = "-inf";
	if (list->flag[1] != 0 && list->width > len)
	{
		while (i++ < list->width - len)
			write(1, " ", 1);
	}
	write(1, s, len);
	if (list->flag[1] == 1 && list->width > len)
	{
		while (i++ < list->width - len)
			write(1, " ", 1);
	}
	return (1);
}

int		free_sble(int error_or_not, t_sble *sble)
{
	free(sble->s_div);
	free(sble->s_mod);
	free(sble->out);
	free(sble->e);
	return (error_or_not);
}

int		print_feg(t_format *list)
{
	t_dble dble;
	t_sble sble;

	if (list->len == 'h' || list->len == 'H' || list->len == 'L')
		return (-1);
	dble.value = va_arg(list->ap, double);
	if ((check_inf_nan(&dble, list, 0)) == 1)
		return (1);
	ft_bzero((void*)&dble, sizeof(dble));
	ft_bzero((void*)&sble, sizeof(sble));
	if (!(parse_div(&dble, &sble)) || !(parse_mod(&dble, &sble)))
		return (free_sble(-1, &sble));
	if (list->spec == 'e')
		return (get_e_str(list, &dble, &sble));
	else if (list->spec == 'g')
		return (get_g_str(list, &dble, &sble));
	return (get_f_str(list, &sble));
}
