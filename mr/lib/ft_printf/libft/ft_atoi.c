/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 21:54:14 by suntlee           #+#    #+#             */
/*   Updated: 2020/02/29 00:10:39 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static int	is_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

int			ft_atoi(const char *str)
{
	int sign;
	int result;

	while (*str && is_space(*str))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
		sign = (*(str++) == '-') ? -1 : 1;
	result = 0;
	while (*str && is_numeric(*str))
		result = 10 * result + (*(str++) - '0');
	return (result * sign);
}
