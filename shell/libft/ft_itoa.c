/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:14:03 by tseo              #+#    #+#             */
/*   Updated: 2020/10/07 11:11:42 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_abs(int n)
{
	return (n < 0) ? -n : n;
}

static int	get_num_len(int n)
{
	int len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*ret;
	int		len;

	len = get_num_len(n);
	if (!(ret = malloc(sizeof(char) * (len + 1))))
		return (0);
	if (n < 0)
		ret[0] = '-';
	else if (n == 0)
		ret[0] = '0';
	ret[len] = 0;
	while (n != 0)
	{
		len--;
		ret[len] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	return (ret);
}
