origin]get_f_str~~~~~~~~~~~~~~~~~~~
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

void	round_up(t_sble *sble, int prec)
{
	int i;
	int up;
	int temp;

	i = prec;
	up = 1;
	sble->m_len = prec;
	whlie (i >= 0 && up = 1)
	{
		temp = (sble->s_mod[i] - '0') + up;
		sble->s_mod[i--] = temp % 10 + '0';
		up = temp <= 9 ? 0 : up;
	}
	while (up == 1 && i <= sble->d_len)
	{
		temp = (sble->s_div[i] - '0') + up;
		sble->s_div[i++] = temp % 10 + '0';
		up = temp <= 9 ? 0 : up;
		if (temp > 9 && i == sble->d_len)
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
	if ((make_out_str(sble)) == 0)
		return (free_sble(-1, sble));
	round_f(list, &ret);
	list->size = ret->d_len + 1 + ret->m_len;
	if (list->flag[0] == 1 || list->flag[3] == 1)
		list->size++;
	output_feg(list, &ret, 0);//need
	list->nums = list->nums + (list->size > list->width ?
		list->size : list->width);
	return (free_sble(1, sble));
}