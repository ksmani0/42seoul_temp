#include "ft_printf.h"

void	parse_div(t_format *list, t_dble *dble, t_sble *sble)
{
	//
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

int	print_f(t_format *list)
{
	t_dble dble;
	t_sble sble;

	dble = va_arg(list->ap, double);
	if ((check_inf_nan(dble, list)) == 1)
		return (1);
	ft_bzero((void*)&dble, sizeof(dble));
	ft_bzero((void*)&sble, sizeof(sble));
	parse_div(list, &dble, &sble);//정수
	parse_mod();//소수점이하
	output_f();
	return (1);
}