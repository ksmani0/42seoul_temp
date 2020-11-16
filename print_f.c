#include "ft_printf.h"

int	get_div_decimal(t_dble *dble, t_sble *sble, int len)
{
	int	i;
	t_deci	pow;
	t_deci	sum;

	i = len;
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
	i = -i;
	while (++i > sum.len)
		sble->s_div[i] = sum.s[i];
	return (1);
}

int	parse_div(t_dble *dble, t_sble *sble)
{
	size_t	len;
	int	i;
	int	j;

	if (dble->e - 1023 <= -1)
	{
		if ((sble->d_bit = (char*)malloc(sizeof(char) * 2) == 0))
			return (-1);
		sble->d_bit[0] = '0';
		sble->d_bit[1] = 0;
		len = 1;
	}
	else
	{
		len = dble->e - 1023 + 1 > 53 ? 53 : dble->e - 1023 + 1;//가수부 비트가 52개니까
		if ((sble->d_bit = (char*)malloc(sizeof(char) * (len + 1)) == 0))
			return (-1);
		d_bit[len] = 0;
		d_bit[(i = 0)] = 1;//부동소수점을 2진수로 표현하면 1.~ 식이니까
		j = 51;
		while (j >= 0 && j > 52 - len)
			d_bit[++i] = (dble->m & 1 >> j--) + '0';//52번째 비트부터 기록
	}
	return (get_div_decimal(dble, sble, len));
}

int	check_inf_nan(t_dble dble, t_format *list)
{
	char	*s;
	int	i;
	int	len;

	i = 0;
	len = 3;
	if ((dble.e == 0 && dble.e == 1023 && dble.m == 0) ||
		(dble.e == 1023 && dble.m >= 1))
		s = dble.m >= 1 ? "nan" : "inf";
	else if (dble.e == 1 && dble.e == 1023 && dble.m == 0 && (len = 4))
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

int	free_bles(t_sble *sble)
{
	free(sble->s_div);
	free(sble->d_bit);
	free(sble->s_mod);
	free(sble->m_bit);
	return (-1);
}

int	print_feg(t_format *list)
{
	t_dble dble;
	t_sble sble;

	dble = va_arg(list->ap, double);
	if ((check_inf_nan(dble, list)) == 1)
		return (1);
	ft_bzero((void*)&dble, sizeof(dble));
	ft_bzero((void*)&sble, sizeof(sble));
	if (!(parse_div(&dble, &sble)) || !(parse_mod(&dble, &sble)))
		return (free_bles(&sble));
	if (list->spec == 'e')
		return (get_e(list, &dble, &sble));
	else if (list->spec == 'g')
		return (get_g(list, &dble, &sble));
	return (get_f(list, &dble, &sble));
}