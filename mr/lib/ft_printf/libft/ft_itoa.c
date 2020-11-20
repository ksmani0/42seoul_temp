/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:27:59 by suntlee           #+#    #+#             */
/*   Updated: 2020/09/13 15:34:45 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	calc_len(unsigned int n)
{
	int len;

	len = 1;
	while (n >= 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int				len;
	unsigned int	nb;
	char			*ptr;

	nb = n >= 0 ? n : -n;
	len = calc_len(nb);
	if (n < 0)
		len += 1;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len] = 0;
	while (len)
	{
		ptr[--len] = nb % 10 + '0';
		nb /= 10;
	}
	if (n < 0)
		ptr[0] = '-';
	return (ptr);
}
